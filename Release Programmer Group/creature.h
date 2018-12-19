#pragma once
#include "debuff.h"
#include "ioSettings.h"
class Creature
{
private:
protected:
	int health;
	int healthCur;
	int mana;
	int manaCur;
	OutputCreature* output = nullptr;
public:
	Creature(int health, int mana);
	void setDamage(int damage);
	int getHealth();
	virtual void getAttack(Creature* enemy) = 0;
	virtual void newTurn() = 0;
	virtual void attack(Creature* enemy) = 0;
	virtual bool superAttack(Creature* enemy) = 0;
	virtual void calculateDebuff() = 0;
	virtual void applyDebuff(Debuff* debuff) = 0;
};