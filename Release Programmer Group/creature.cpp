#include "creature.h"

Creature::Creature(int health, int mana)
{
	this->health = health; 
	healthCur = health;
	this->mana = mana;
	manaCur = mana;
	output = new OutputCreature();
}

void Creature::setDamage(int damage)
{
	healthCur -= damage;
}


int Creature::getHealth()
{
	return healthCur;
}
