#include "story.h"

Story::Story(string lang, int chapter, int stage, Hero* mainCharacter, Monster* currentMonster, int turn)
{
	this->chapter = chapter;
	this->stage = stage;
	this->mainCharacter = mainCharacter;
	this->currentMonster = currentMonster;
	this->turn = turn;
	this->lang = lang;
}

void Story::start()
{
	switch (chapter)
	{
	case 0:
	{
		oS = new OutputChapter0();
		oS->setLang(lang);
		oS->clearScreen();
		switch (stage)
		{
		case 1:
			oS->call("1");
			stage++;
		case 2:
			oS->call("2");
			stage++;
		case 3:
			oS->call("3");
			stage++;
		case 4:
			oS->call("4");
			stage++;
		case 5:
			oS->call("5");
			oS->pause();
			stage++;
			chapter = 1;
			stage = 1;
			free(oS);
		}
	}
	case 1:
	{
		oS = new OutputChapter1();
		oS->setLang(lang);
		oS->clearScreen();
		switch (stage)
		{
		case 1:
			oS->call("1");
			stage++;
		case 2:
			oS->call("2");
			stage++;
		case 3:
			oS->call("3");
			stage++;
		case 4:
			oS->call("4");
			stage++;
		case 5:
			currentMonster = new Rat();
			fight();
		case 6:
			oS->call("5");
			oS->pause();
			stage++;
			chapter = 1;
			stage = 1;
			free(oS);
		}
	}
	case 2:
    {
		oS = new OutputChapterFast();
		oS->setLang(lang);
		oS->clearScreen();
		switch (stage)
		{
		case 1:
			oS->call("1");
			stage++;
		case 2:
			oS->call("2");
			stage++;
		case 3:
			currentMonster = new Gelbin();
			fight();
		case 4:
			currentMonster = new Spider();
			fight();
		case 5:
		    stage++;
		case 6:
		    free(oS);
		}
    }
	}
	if (chapter == 1)
	{
		end(1);
	}
}

void Story::end(int end)
{
	switch (end)
	{
	case 0:
		//cout << "Your dead";
		break;
	case 1:
		//cout << "You won!";
		break;
	}
}

bool Story::fight()
{
	OutputFight* oF = new OutputFight();
	oF->setLang(lang);
	if (turn == 0)
	{
		turn = RPGUtils::getRandom(1, 2);
		if (turn == 1)
		{
			oF->call("PTurn");
		}
		else
		{
			oF->call("MTurn");
		}
	}
	while (mainCharacter->getHealth() > 0 && currentMonster->getHealth() > 0)
	{
		if (turn == 1)
		{
			mainCharacter->newTurn();
			mainCharacter->getAttack(currentMonster);
		}
		else
		{
			currentMonster->newTurn();
			currentMonster->getAttack(mainCharacter);
		}
		turn = turn % 2 + 1;
	}
	if (mainCharacter->getHealth() > 0)
	{
		currentMonster->getDrop();
		return true;
	}
	return false;
}

void Story::chooseClass()
{
	string c = "1";
	char b = '0';

	while (b != '-')
	{
		c = "0";
		oS->call("Class");
		c = input::get();
		if (c == "1")
		{
			mainCharacter = new Warrior();
			b = '1';
		}
		else if (c == "2")
		{
			mainCharacter = new Mage();
			b = '2';
		}
		else if (c == "3")
		{
			mainCharacter = new Archer();
			b = '3';
		}
		else
		{
			b = '0';
			oS->clearScreen();
			oS->call("WrongInput");
		}

		if (b > '0')
		{
			string s = "Confirm";
			s += b;
			oS->call(s);
			c = input::get();
			if (c == "y" or c == "Y" or c == "у" or c == "У")
			{
				b = '-';
			}
			else
			{
				b = '0';
			}
			oS->clearScreen();
		}
	}
}
