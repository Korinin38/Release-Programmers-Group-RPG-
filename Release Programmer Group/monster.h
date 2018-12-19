#pragma once
#include "creature.h"
#include "utils.h"
#include "debuff.h"

enum AttackType { ABSENT, ATTACK, SUPER_ATTACK };
class Monster : public Creature
{
private:
protected:
	Debuff* debuff = nullptr;
	int damage;
	AttackType nextAttack = ABSENT;
public:
	Monster(int damage, int health, int mana, Debuff* debuff);
	void newTurn();
	void getAttack(Creature* enemy);

	virtual AttackType calculateAttack() = 0;
	virtual Drop getDrop() = 0;
	virtual void inflict(Creature * enemy) = 0;
	void calculateDebuff();
	void applyDebuff(Debuff* debuff);
};

