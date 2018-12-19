#pragma once
#include "creature.h"
#include "utils.h"
#include "debuff.h"

const int symDamage = 3;

class Hero : public Creature
{
private:
	int experience = 0;
	int level = 1;
protected:
	int upgradePoints = 0;
	int strength;
	int intelligence;
	int agility;
	int strengthCur;
	int intelligenceCur;
	int agilityCur;
	bool symbiote = 0;
	Debuff* appliedDebuff = nullptr;
public:
	Hero(int strength = 1, int agility = 1, int intelligence = 1, int health = 10, int mana = 2);
	void newTurn();
	void getAttack(Creature* enemy);
	void setDamage(int damage);

	bool hasUpgrades();
	void upStrength();
	void upIntelligence();
	void upAgility();

	void attack(Creature* enemy);
	bool superAttack(Creature* enemy);
	void calculateDebuff();
	void applyDebuff(Debuff* debuff);
};

