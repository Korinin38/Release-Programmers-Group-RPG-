#include "monster.h"


Monster::Monster(int damage, int health, int mana, Debuff * debuff) : Creature(health, mana) {
	this->damage = damage;
	this->debuff = debuff;
}


void Monster::newTurn()
{
	manaCur += 1;
	if (manaCur > mana)
	{
		manaCur = mana;
	}
	output->call("MTurn");
	output->callHealth(healthCur, health);
}

void Monster::getAttack(Creature* enemy)
{
	if (calculateAttack() == ATTACK)
	{
		attack(enemy);
	}
	else
	{
		superAttack(enemy);
	}
}

void Monster::calculateDebuff()
{
	//do nothing
}

void Monster::applyDebuff(Debuff * debuff)
{
	//do nothing;
}
