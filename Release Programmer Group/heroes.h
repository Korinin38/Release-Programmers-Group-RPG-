#pragma once
#include "hero.h"
#include "utils.h"
class Warrior : public Hero
{
private: //stats: health - 20; mana=i*2 = 6;  s/a/i - 6/3/3
protected:
public:
	Warrior();
	void getAttack(Creature* enemy);
	void attack(Creature* enemy); // special: no 'damage scatter'
	bool superAttack(Creature * enemy); // cost: 1/2 mana
};

class Mage : public Hero
{
private: //stats: health - 14; mana=i*2 = 16;  s/a/i - 2/2/8
protected:
public:
	Mage();
	void newTurn(); // special: regen 1 additional 'mana' every turn
	void getAttack(Creature* enemy);
	void attack(Creature* enemy);
	bool superAttack(Creature* enemy); //cost: 5
};

class Archer : public Hero
{
private: //stats: health - 16; mana=i*2 = 6;  s/a/i - 4/4/4
protected:
public:
	Archer(); // special: get additional 'Upgrade Point'
	void getAttack(Creature* enemy);
	void attack(Creature* enemy);
	bool superAttack(Creature* enemy); // cost: 4
};