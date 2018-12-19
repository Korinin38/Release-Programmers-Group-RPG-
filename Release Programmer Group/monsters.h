#pragma once
#include "monster.h"

class Rat : public Monster
{
private:
protected:
public:
	Rat(); //stats: damage - 3; health - 10; mana - 0; 
	AttackType calculateAttack();
	void attack(Creature* enemy);
	bool superAttack(Creature* enemy);
	void inflict(Creature * enemy);
	Drop getDrop();
};

class Gelbin : public Monster
{
private:
protected:
public:
	Gelbin(); //stats: damage - 5, health - 20, mana - 4;
	AttackType calculateAttack();
	void attack(Creature* enemy);
	bool superAttack(Creature* enemy);
	void inflict(Creature * enemy);
	Drop getDrop();
};

class Spider : public Monster
{
private:
protected:
public:
	Spider(); //stats: damage - 4, health - 22, mana - 5;
	AttackType calculateAttack();
	void attack(Creature* enemy);
	bool superAttack(Creature* enemy);
	void inflict(Creature * enemy);
	Drop getDrop();
};