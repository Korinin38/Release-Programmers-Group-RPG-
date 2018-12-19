#include <iostream>
#include "gameManager.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	GameManager* GM = new GameManager();
	GM->chooseLang();
	GM->start();
	return 0;
}