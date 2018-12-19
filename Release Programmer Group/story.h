#pragma once
#include "heroes.h"
#include "monsters.h"
#include "utils.h"
#include "ioSettings.h"
class Story
{
private:
	int chapter;
	int stage;
	Hero* mainCharacter;
	Monster* currentMonster;
	Inventory* inventory = nullptr;
	string lang;
	Output* oS = nullptr;
	int turn;
public:
	Story(string lang = "RU", int chapter = 0, int stage = 1, Hero* mainCharacter = new Hero(), Monster* currentMonster = nullptr, int turn = 0);
	void start();
	void end(int end);
	bool fight();
	void chooseClass();
};
