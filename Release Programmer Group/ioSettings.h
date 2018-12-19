#pragma once
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "utils.h"
//#include <fstream>
using namespace std;

class Output
{
protected:
    map<string, string> phrase;
    set<string> headers;
	string lang = "RU";
    //ostream cin;
public:
	Output();
    void clearScreen();
    void setLang(string lang);
    void call(string phr, int tru = 0);
	string pause(int x = 1);
	string getLang();
};

class OutputGameManager : public Output
{
public:
    OutputGameManager();
};

class OutputChapter0 : public Output
{
public:
    OutputChapter0();
};
class OutputChapter1 : public Output
{
public:
	OutputChapter1();
};

class OutputFight : public Output
{
public:
    OutputFight();
};

class OutputCreature : public Output
{
public:
	OutputCreature();
	void callHealth(int healthCur, int health);
	void callMana(int manaCur, int mana);
	void callDamage(int damage);
	void callAttack(string str, int damage, int randomNumber = 1);
};

class input
{
protected:
    //istream cin;
public:
    static string get(/*istream*/);
};
