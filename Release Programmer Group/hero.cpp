#include "hero.h"
#include "ioSettings.h"

Hero::Hero(int strength, int agility, int intelligence, int health, int mana) : Creature(health, mana) {
	this->strength = strength;
	this->intelligence = intelligence;
	this->agility = agility;
	strengthCur = strength;
	intelligenceCur = intelligence;
	agilityCur = agility;
}

void Hero::newTurn()
{
	manaCur += 1;
	if (manaCur > mana)
	{
		manaCur = mana;
	}
	if (appliedDebuff != nullptr)
	{
		calculateDebuff();
	}
	output->callHealth(healthCur, health);
	output->callMana(manaCur, mana);
}

void Hero::getAttack(Creature* enemy)
{
	output->call("PHeroList");
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

void Hero::setDamage(int damage)
{
    RPGUtils::getDamageScatter(damage, 4-agility/3)
	healthCur -= damage;
}

bool Hero::hasUpgrades()
{
	if (upgradePoints > 0)
	{
		return true;
	}
	return false;
}

void Hero::upStrength()
{
	if (hasUpgrades())
	{
		strength += 1;
		strengthCur = strength;
	}
}

void Hero::upIntelligence()
{
	if (hasUpgrades())
	{
		intelligence += 1;
		intelligenceCur = intelligence;
	}
}

void Hero::upAgility()
{
	if (hasUpgrades())
	{
		agility += 1;
		agilityCur = agility;
	}
}

void Hero::attack(Creature* enemy)
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

	output->callAttack("PHeroAttack", damage);

	enemy->setDamage(damage);
}

bool Hero::superAttack(Creature* enemy)
{
	if (manaCur >= 2)
	{
		bool crit = false;
		manaCur -= 2;
		int damage = RPGUtils::getDamage(strength);
		if (symbiote)
		{
			damage += symDamage;
		}
		damage += 2;
		if (RPGUtils::calculateCrit(damage, agility))
		{
			crit = true;
			RPGUtils::getCrit(&damage, agility);
		}
		RPGUtils::getDamageScatter(&damage, strength);

		output->callAttack("PHeroSuperAttack", damage);
		if (crit)
		{
			output->call("Crit");
		}

		enemy->setDamage(damage);
		return true;
	}
	else
	{
		return false;
	}
}

void Hero::calculateDebuff()
{
	int res[4];
	appliedDebuff->inflict(res);
	if (res[0] == 0) free(appliedDebuff);
	strengthCur = strength + res[1];
	agilityCur = agility + res[2];
	intelligenceCur = intelligence + res[3];
}

void Hero::applyDebuff(Debuff* debuff)
{
	appliedDebuff = debuff;
}
