#include "utils.h"

int RPGUtils::getDamage(int strength)
{
	return (int)(4 * pow(strength, 0.2));
}

int RPGUtils::getRandom(int from, int to)
{
	srand(time(NULL));
	return rand() % (to - from + 1) + from;
}

void RPGUtils::getDamageScatter(int* damage, int strength)
{
	if (strength > 0)
		*damage = *damage + RPGUtils::getRandom((10-strength)/3, 0);
}

bool RPGUtils::calculateCrit(int damage, int agility)
{
	return RPGUtils::getRandom(0, 100) < agility ? true : false;
}

bool RPGUtils::getCrit(int* damage, int agility)
{
	*damage = (int)(*damage * 2.5);
	return true;
}


Inventory::Inventory(ItemType* inv, int invSize)
{
	for (int i = 0; i < invSize; ++i)
	{
		this->inv[i] = inv[i];
	}
}

void Inventory::getInventory()
{
	//cout << "Your inventory:]n"
	int x = 0;
	for (int i = 0; i < invSize; ++i)
	{
		switch (invSize)
		{
		case MP_POTION:
			++x;
			//cout << "Health Potion\n";
		case HP_POTION:
			++x;
			//cout << "Mana Potion\n";
		case WELL_POTION:
			++x;
			//cout << "Well Potion\n";
		}
	}
	if (x == 0)
	{
		//cout << "hmm... empty\n";
	}
	//cout << endl;
}

void Inventory::addItem(ItemType drop)
{
	int i = 0;
	while (i < invSize && inv[i] != NONE) ++i;
	if (i == invSize)
	{
		//cout << "YOUR INVENTORY IS FULL";
		;
	}
	else
	{
		inv[i] = drop;
	}
}

bool Inventory::useItem(ItemType drop)
{
	int i = 0;
	while (i < invSize && inv[i] != drop) ++i;
	if (i == invSize)
	{
		//cout << "WTF you don't have it";
		;
		return false;
	}
	else
	{
		inv[i] = NONE;
		return true;
	}
}

Drop::Drop(int experience, ItemType type)
{
	this->experience = experience;
	this->type = type;
}
