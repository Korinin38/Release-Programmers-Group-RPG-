#include "monsters.h"

Rat::Rat() : Monster(1, 5, 0, nullptr) {}

AttackType Rat::calculateAttack()
{
	return ATTACK;
}

void Rat::attack(Creature * enemy)
{
	//Rat bites you and deal 'damage'; 
	enemy->setDamage(damage);
	output->callAttack("MRatAttack", damage);
}

bool Rat::superAttack(Creature * enemy)
{
	//Rat bites you. 
	//Suddenly, you become infected with typhus, plague, syphilis, split personality and third hand syndrome.
	//You decide to escape from the dungeon and spend the rest of your life with your family.
	//After 3 years (or days, i think) you become unable to get out of bed.
	//Your daughter, Diana, cries on your breast. 
	//You died.
	enemy->setDamage(enemy->getHealth() + 1);
	return true;
}

void Rat::inflict(Creature * enemy){}

Drop Rat::getDrop()
{
	Drop result(1, NONE);
	return result;
}

Gelbin::Gelbin() : Monster(5, 20, 4, nullptr){}

AttackType Gelbin::calculateAttack()
{
	if (manaCur >= 4)
		if (RPGUtils::getRandom(0, 1)==1)
		{
			return SUPER_ATTACK;
		}
		else
		{
			return ATTACK;
		}
	return ATTACK;
}

void Gelbin::attack(Creature * enemy)
{
	//Gelbin hits you with club and deal 'damage'; 
	enemy->setDamage(damage);
}

bool Gelbin::superAttack(Creature * enemy)
{
	if (manaCur >= 4)
	{
		manaCur -= 4;
		//Gelbin prepares his attack;
		//He strilkes you and deal additional 'damage'! 
		enemy->setDamage(damage + 3);
		return true;
	}
	else
	{
		return false;
	}
}

void Gelbin::inflict(Creature * enemy){}

Drop Gelbin::getDrop()
{
	if (RPGUtils::getRandom(0, 10) == 10)
	{
		Drop result(3, HP_POTION);
		return result;
	}
	else
	{
		Drop result(3, NONE);
		return result;
	}
}

Spider::Spider() : Monster(4, 22, 5, new GooedSpider) {}

AttackType Spider::calculateAttack()
{
	if (manaCur >= 3)
		if (RPGUtils::getRandom(0, 2) > 1)
		{
			return SUPER_ATTACK;
		}
		else
		{
			return ATTACK;
		}
	return ATTACK;
}

void Spider::attack(Creature * enemy)
{
	//Spider bites you and deal 'damage'; 
	enemy->setDamage(damage);
}

bool Spider::superAttack(Creature * enemy)
{
	if (manaCur >= 3)
	{
		manaCur -= 3;
		//Spider shoots with web, covering you and debuffing! 
		inflict(enemy);
		return true;
	}
	else
	{
		return false;
	}
}

void Spider::inflict(Creature * enemy)
{
	debuff = new GooedSpider();
	enemy->applyDebuff(debuff);
	enemy->calculateDebuff();
}

Drop Spider::getDrop()
{
	if (RPGUtils::getRandom(0, 5) >= 4)
	{
		Drop result(7, HP_POTION);
		return result;
	}
	else
	{
		Drop result(7, NONE);
		return result;
	}
}