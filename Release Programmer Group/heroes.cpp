#include "heroes.h"
Warrior::Warrior() : Hero(6, 3, 3, 20, 6){}

void Warrior::getAttack(Creature* enemy)
{
	output->call("PWarriorList");
	string str = input::get();
	bool b = true;
	while (b)
	{
		if (str == "1")
		{
			b = false;
			attack(enemy);
		}
		else if (str == "2")
		{
			if (superAttack(enemy))
			{
				b = false;
			}
			else
			{
				output->call("NotEnoughMana");
				str = input::get();
			}
		}
		else
		{
			output->call("WrongInput");
			str = input::get();
		}
	}
}

void Warrior::attack(Creature* enemy)
{
	int damage = RPGUtils::getDamage(strength);
	if (symbiote)
	{
		damage += symDamage;
	}
	if (RPGUtils::calculateCrit(damage, agility))
	{
		//"crit!"
		RPGUtils::getCrit(&damage, agility);
	}

	output->callAttack("PHeroAttack", damage);
	enemy->setDamage(damage);
}

bool Warrior::superAttack(Creature * enemy)
{
	if (manaCur >= mana / 2)
	{
		manaCur -= mana / 2;
		int damage = RPGUtils::getDamage(strength);
		if (symbiote)
		{
			damage += symDamage;
		}
		damage += mana / 2;
		if (RPGUtils::calculateCrit(damage, agility))
		{
			//"crit!"
			RPGUtils::getCrit(&damage, agility);
		}

		//"You ram into 'enemy' and deal 'damage' + mana/2"
		enemy->setDamage(damage);
		return true;
	}
	else
	{
		return false;
	}
}

Mage::Mage() : Hero(2, 2, 8, 14, 16) {}

void Mage::newTurn()
{
	manaCur += 2;
	if (manaCur > mana)
	{
		manaCur = mana;
	}
}

void Mage::getAttack(Creature* enemy)
{
	output->call("PMageList");
	string str = input::get();
	bool b = true;
	while (b)
	{
		if (str == "1")
		{
			b = false;
			attack(enemy);
		}
		else if (str == "2")
		{
			if (superAttack(enemy))
			{
				b = false;
			}
			else
			{
				output->call("NotEnoughMana");
				str = input::get();
			}
		}
		else
		{
			output->call("WrongInput");
			str = input::get();
		}
	}
}

void Mage::attack(Creature * enemy)
{
	int damage = RPGUtils::getDamage(strength);
	if (symbiote)
	{
		damage += symDamage;
	}
	if (RPGUtils::calculateCrit(damage, agility))
	{
		//"crit!"
		RPGUtils::getCrit(&damage, agility);
	}
	RPGUtils::getDamageScatter(&damage, strength);

	output->callAttack("PMageAttack", damage);
	enemy->setDamage(damage);
}

bool Mage::superAttack(Creature * enemy)
{
	if (manaCur >= 5)
	{
		manaCur -= 5;
		int damage = RPGUtils::getDamage(strength);
		if (symbiote)
		{
			damage += symDamage;
		}
		if (RPGUtils::calculateCrit(damage, agility))
		{
			//"crit!"
			RPGUtils::getCrit(&damage, agility);
		}
		RPGUtils::getDamageScatter(&damage, strength);

		//"You summon an iron crate into 'enemy' and deal 'damage' + 'crateDamage'"
		enemy->setDamage((int)(strength * 1.1) + (symbiote ? symDamage : 0) + 7);
		return true;
	}
	else
	{
		return false;
	}
}

Archer::Archer() : Hero(4, 4, 4, 16, 6) {
	upgradePoints = 1;
}

void Archer::getAttack(Creature* enemy)
{
	output->call("PArcherList");
	string str = input::get();
	bool b = true;
	while (b)
	{
		if (str == "1")
		{
			b = false;
			attack(enemy);
		}
		else if (str == "2")
		{
			if (superAttack(enemy))
			{
				b = false;
			}
			else
			{
				output->call("NotEnoughMana");
				str = input::get();
			}
		}
		else
		{
			output->call("WrongInput");
			str = input::get();
		}
	}
}

void Archer::attack(Creature * enemy)
{
	int damage = RPGUtils::getDamage(strength);
	if (symbiote)
	{
		damage += symDamage;
	}
	if (RPGUtils::calculateCrit(damage, agility))
	{
		//"crit!"
		RPGUtils::getCrit(&damage, agility);
	}
	RPGUtils::getDamageScatter(&damage, strength);

	output->callAttack("PArcherAttack", damage);
	enemy->setDamage(damage);
}

bool Archer::superAttack(Creature * enemy)
{
	if (manaCur >= 4)
	{
		manaCur -= 4;
		int damage = RPGUtils::getDamage(strength);
		if (symbiote)
		{
			damage += symDamage;
		}

		//"crit! (guaranteed)"
		RPGUtils::getCrit(&damage, agility);

		RPGUtils::getDamageScatter(&damage, strength);

		//"You shoot poisoned arrow to 'enemy' and deal 'damage' (crit)"
		enemy->setDamage(damage);
		return true;
	}
	else
	{
		return false;
	}
}
