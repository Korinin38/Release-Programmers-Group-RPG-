#pragma once
#include <stdlib.h>
#include <time.h>
#include <math.h>


const int levelRate[10] = { 5, 10, 15, 20, 30, 45, 60, 80, 100, 125 };
enum ItemType { NONE, HP_POTION, MP_POTION, WELL_POTION };

class Inventory
{
private:
	static const int invSize = 10;
	ItemType inv[invSize];
protected:
public:
	Inventory(ItemType* inv = nullptr, int invSize = 0);
	void getInventory();
	void addItem(ItemType drop);
	bool useItem(ItemType drop);
};

class Drop
{
private:
	int experience;
	ItemType type;
public:
	Drop(int experience, ItemType type);
};

class RPGUtils
{
public:
	static int getDamage(int strength);
	static int getRandom(int from, int to);
	static void getDamageScatter(int* damage, int strength = 0);
	static bool calculateCrit(int damage, int agility);
	static bool getCrit(int* damage, int agility);
}; 
