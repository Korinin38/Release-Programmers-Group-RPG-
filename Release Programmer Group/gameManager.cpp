#include "gameManager.h"

GameManager::GameManager()
{
	oG = new OutputGameManager();
}

void GameManager::chooseLang()
{
	string c = "1";
	oG->setLang("RU");
	/*
	while (c != "0")
	{
		c = "0";
		oG->call("LangList");

		c = input::get();

		if (c == "0")
		{
			return;
		}
		else if (c == "1")
		{
			oG->setLang("RU");
			c = "0";
		}
		else if (c == "2")
		{
			//oG->setLang("RU");
			oG->setLang("EN");
			c = "0";
		}
		else
		{
			oG->clearScreen();
			oG->call("WrongInput");
			c = "1";
		}
	}
	oG->clearScreen();
	*/
}

void GameManager::start()
{
	string c = "1";

	while (c != "0")
	{
		c = "0";
		oG->call("Header");
		oG->call("Menu");

        c = input::get();

        if (c == "0")
        {
            return;
        }
		else if (c == "1")
		{
			Story* story = new Story(oG->getLang());
			oG->clearScreen();
			story->start();
			c = "0";
			break;
        }
		/*else if (c == "2")
		{
			//load file
		}*/
		else
		{
            oG->clearScreen();
            oG->call("WrongInput");
			c = "1";
		}
	}
}
