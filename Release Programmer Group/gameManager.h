#pragma once
#include "ioSettings.h"
#include "story.h"
class GameManager
{
private:
	OutputGameManager * oG = nullptr;
public:
	GameManager();
	void chooseLang();
	void start();
};
