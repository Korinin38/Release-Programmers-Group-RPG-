#include "ioSettings.h"

using namespace std;

Output::Output()
{
	headers.insert("PauseEN");
	headers.insert("PauseAdvancedEN");
	headers.insert("PauseRU");
	headers.insert("PauseAdvancedRU");

	phrase["PauseEN"] = "*\nPress Enter to continue\n*\n";
	phrase["PauseAdvancedEN"] = "*\nPress Enter to continue\n*\n";

	phrase["PauseRU"] = "*\n��� ����������� ������� Enter\n*\n";
	phrase["PauseAdvancedRU"] = "*\nPress Enter to continue\n*\n";
}

void Output::setLang(string lang)
{
	this->lang = lang;
}

void Output::call(string phr, int tru)
{
	string str = phr + lang;
	//cout << "\n*" << str << "\n*";
	if (headers.find(str) != headers.end())
	{
		for (int i = 0; i < phrase[str].size(); ++i)
		{
			if (_kbhit())
			{
				cout << phrase[str][i];
			}
			else
			{
				cout << phrase[str][i];
				if (tru == 0)
				{
					Sleep(30);
				}
			}
		}
		if (!_kbhit())
		{
			if (tru == 0)
			{
				Sleep(500);
			}
		}
	}
	else
	{
		cout << "ERROR";
	}
}

string Output::pause(int x)
{
	if (x == 0)
		call("Pause");
	else
		call("PauseAdvanced");
	return input::get();
}

string Output::getLang()
{
	return lang;
}


void Output::clearScreen()
{
	system("cls");
}

OutputGameManager::OutputGameManager() : Output()
{
	headers.insert("LangListEN");
	headers.insert("HeaderEN");
	headers.insert("MenuEN");
	headers.insert("WrongInputEN");

	headers.insert("LangListRU");
	headers.insert("HeaderRU");
	headers.insert("MenuRU");
	headers.insert("WrongInputRU");


	phrase["LangListEN"] = "1.�������\n2.English(coming soon)\n";

	phrase["HeaderEN"] = "Small Release Programmer Group (Small RPG)\n";

	phrase["MenuEN"] = (string)"Choose an option:\n"
		+ (string)"(1) Start New Game\n\n"
		+ (string)"(0) Exit\n";

	phrase["WrongInputEN"] = "KEK, maybe choose only 1 or 0?\n";

	phrase["LangListRU"] = phrase["LangListEN"];

	phrase["HeaderRU"] = "Small Release Programmer Group (Small RPG)\n";

	phrase["MenuRU"] = (string)"�������� �����:\n"
		+ (string)"(1) ������ ����� ����\n\n"
		+ (string)"(0) �����\n";

	phrase["WrongInputRU"] = "KEK, �����, �������� 1 ��� 0?\n";
}

OutputChapter0::OutputChapter0() : Output()
{
	headers.insert("1EN");
	headers.insert("2EN");
	headers.insert("3EN");
	headers.insert("4EN");
	headers.insert("5EN");
	headers.insert("ClassEN");
	headers.insert("Confirm1EN");
	headers.insert("Confirm2EN");
	headers.insert("Confirm3EN");
	headers.insert("WrongInputEN");

	headers.insert("1RU");
	headers.insert("2RU");
	headers.insert("3RU");
	headers.insert("4RU");
	headers.insert("5RU");
	headers.insert("ClassRU");
	headers.insert("Confirm1RU");
	headers.insert("Confirm2RU");
	headers.insert("Confirm3RU");
	headers.insert("WrongInputRU");


	phrase["1EN"] = (string)"Many ears ago...\n"
		+ (string)"Creatures of huge size lived on Earth.\n"
		+ (string)"We don't know much about them, because there hadn't been any humans yet.\n"
		+ (string)"The only thing we can be assured - that they existed.\n"
		+ (string)"And that their existence had ended swiftly.\n";

	phrase["2EN"] = (string)"At one moment something strange happened on Earth.\n"
		+ (string)"An unknown object flew into an upper atmosphere of the planet.\n"
		+ (string)"Faced with the surface, he created a destructive sound wave that split the ancient continent into pieces and almost destroyed life on earth.\n";

	phrase["3EN"] = (string)"Hot droughty day, one of the common here for this time of year.\n"
		+ (string)"The expedition found a cave in the rainforest, from where once a day or two came strange sounds.\n"
		+ (string)"It was like scream, or groan, or roar of some beast.\n"
		+ (string)"You were also in this group.\n";

	phrase["4EN"] = (string)"The researchers decided to look into the cave but made a camp at first: having a nap before exploration was a good idea.\n"
		+ (string)"However, an unknown creature attacked the camp at night. From the sounds that this creature made, one could guess that it was a cave dweller.\n"
		+ (string)"The darkness of the night forest did not allow you to understand who it was, but it was clear that it was someone or something enourmous.\n";

	phrase["5EN"] = (string)"The next morning, when the light fell on the forest thicket, you realized that most of you were badly wounded, and one person had gone.\n"
		+ (string)"The group decided to return for help, but you did not agree: the missing should be saved, and as soon as possible.\n"
		+ (string)"A little behind, you turned and headed for the cave entrance.\n"
		+ (string)"Your adventure begins here.\n";

	phrase["ClassEN"] = (string)"Choose class (1, 2, 3):\n"
		+ (string)"(1) Warrior - melee fighter. He has strong body as well as hits\n"
		+ (string)"(2) Mage - mental energy master. Despite his weak body build, his presence often leads to victory\n"
		+ (string)"(3) Archer - great ranged fighter. His keen eye allows him to find the weak spots of the enemy and deliver a deadly blow\n";

	phrase["Confirm1EN"] = (string)"Class: Warrior.\n"
		+ (string)"Characteristics: 20 health, 6 strength, 3 agility, 3 intelligence (6/3/3 s/a/i)\n"
		+ (string)"Special: damage has no scatter\n"
		+ (string)"Enter Y for choice confirmation or any key for refusal\n";

	phrase["Confirm2EN"] = (string)"Class: Mage.\n"
		+ (string)"Characteristics: 14 health, 2 strength, 2 agility, 8 intelligence (2/2/8 s/a/i)\n"
		+ (string)"Special: gain additional mana point every turn\n"
		+ (string)"Enter Y for choice confirmation or any key for refusal\n";

	phrase["Confirm3EN"] = (string)"�����: ������.\n"
		+ (string)"Characteristics: 16 health, 4 strength, 4 agility, 4 intelligence (4/4/4 s/a/i)\n"
		+ (string)"Special: gain additional upgrage point for distribution\n"
		+ (string)"Enter Y for choice confirmation or any key for refusal\n";

	phrase["WrongInputEN"] = "KEK, maybe choose 1, 2 or 3?\n";

	phrase["1RU"] = (string)"����� ��� ���� �����...\n"
		+ (string)"�� ����� ���� �������� ��������������� �������.\n"
		+ (string)"� ��� ���� ��������, ���� � �� ������� ��� �� ���� �����.\n"
		+ (string)"������������, � ��� ����� ������� � ������������, - ��� ��, ��� ��� ������������.\n"
		+ (string)"� ��� �� ������������� ������������ ������������.\n";

	phrase["2RU"] = (string)"� ���� ������ �� ����� ��������� ���-�� ��������.\n"
		+ (string)"����������� ������ ������ � ������� ���� ��������� �������.\n"
		+ (string)"������������ � ������������, �� ������ �������������� �������� �����, ��� ��������� ������� ������� �� ����� � ����������� ���������� ����� �� �����.\n";

	phrase["3RU"] = (string)"������ ���������� ����, ���� �� ������������ ����� ��� ���� ���� ����.\n"
		+ (string)"���������� ����� � ����������� ���� ������, ������ ��� � ����-��� ���������� �������� �����.\n"
		+ (string)"��� ��� �� �� ����, �� �� ����, �� �� ��� ������-�� �����.\n"
		+ (string)"����� �� ������ ���� ��.\n";

	phrase["4RU"] = (string)"������������� ������ ��������� � ������, �� ������� �������� ������: ��������� ����� ������� ���� ������� �����.\n"
		+ (string)"������ ����� �� ������ ������ ����������� ��������. �� ������, ������� ��� �������� ��������, ����� ���� ����������, ��� ��� ��� ��������� ������.\n"
		+ (string)"������� ������� ���� �� ��������� ��� ������, ��� ��� ���, �� ���� ���� - ��� ��� ���-�� ������������� �������.\n";

	phrase["5RU"] = (string)"������, ����� �� ������ ���� ��������� ����, �� ������, ��� ����������� �� ��� ������ ������, � ���� ������� ������.\n"
		+ (string)"������ ������ ��������� �� ��������, �� �� ���� �� ��������: ���������� ����� ������, � ��� ����� ������.\n"
		+ (string)"������� ������, �� ������������ � ����������� �� ����� � ������.\n"
		+ (string)"����� ���������� ���� �����������.\n";

	phrase["ClassRU"] = (string)"�������� ����� (1, 2, 3):\n"
		+ (string)"(1) ���� - ������ �������� ���. ��� ���� ��������� ��� ����������� ������ �����, � ����� ������\n"
		+ (string)"(2) ��� - ������ ������� � ���������. �������� �� ������� ������������, ��� ����������� � ����� ������ ����� �������� � ������� ������\n"
		+ (string)"(3) ������ - ������ �������. ��� ������ ���� ��������� �������� ������ ����� ���������� � �������� ������������ ����\n";

	phrase["Confirm1RU"] = (string)"�����: ����.\n"
		+ (string)"��������������: 20 ��������, 6 ����, 3 ��������, 3 ����������\n"
		+ (string)"�����������: ���� �� ���� �� ��������� ���������� ����������\n"
		+ (string)"������� Y ��� ������������� ������ ��� ����� ������ ���� ��� ������\n";

	phrase["Confirm2RU"] = (string)"�����: ���.\n"
		+ (string)"��������������: 14 ��������, 2 ����, 2 ��������, 8 ����������\n"
		+ (string)"�����������: ������ ��� ��������������� �� 1 ��. ���� ������\n"
		+ (string)"������� Y ��� ������������� ������ ��� ����� ������ ���� ��� ������\n";

	phrase["Confirm3RU"] = (string)"�����: ������.\n"
		+ (string)"��������������: 16 ��������, 4 ����, 4 ��������, 4 ����������\n"
		+ (string)"�����������: �������������� ���� ������������� �������������\n"
		+ (string)"������� Y ��� ������������� ������ ��� ����� ������ ���� ��� ������\n";

	phrase["WrongInputRU"] = "KEK, �����, �������� 1, 2 ��� 3?\n";
}

OutputChapter1::OutputChapter1()
{
	headers.insert("1EN");
	headers.insert("2EN");
	headers.insert("3EN");
	headers.insert("4EN");
	headers.insert("5EN");

	headers.insert("1RU");
	headers.insert("2RU");
	headers.insert("3RU");
	headers.insert("4RU");
	headers.insert("5RU");

	phrase["1EN"] = (string)"If you were sure in your idea before entering the cave, now, stepping inside, you stopped in doubt.\n"
		+ (string)"Possibly, it manifests a sense of fear of the unknown.\n"
		+ (string)"Possibly, The plan was not well thought out.\n"
		+ (string)"So the truth is: darkness often reigns in caves, and you do not have a single source of light with you.\n"
		+ (string)"Back at the camp site, you made a simple torch. Fortunately, there were enough materials for this.\n"
		+ (string)"Now you can go.\n";

	phrase["2EN"] = (string)"No, of course not! It is impossible to carelessly walk without a weapon in the place where the monster most likely lurked!\n"
		+ (string)"But there was no suitable weapon, any weapon.\n"
		+ (string)"You took a stick out of the fire, a little charred at the end. The corner smoldered, exuding heat.\n"
		+ (string)"Better than nothing.\n"
		+ (string)"Now you can go (for sure).\n";

	phrase["3EN"] = (string)"Armed with a torch and a stick, you headed inside the cave.\n"
		+ (string)"The abode of the monster was an ordinary cave;\n"
		+ (string)"the cold, moist clay walls reflected faintly the light of the torch.n"
		+ (string)"If you lift your head up, you will notice that the ceiling is hung with small stone stumps.\n"
		+ (string)"Apparently, someone periodically knocks down the stalactites formed here, which is why they don't grow.\n";

	phrase["4EN"] = (string)"lifeless place at first glance, it is enlivened by a quiet squeak. A pack of rats has found shelter here..\n"
		+ (string)"Although the pack itself is not visible: most likely, they live in small tunnel systems.\n"
		+ (string)"One rat crawled out into open space (if the narrow passage of the cave can be called such).\n"
		+ (string)"Her look is somehow unkindly withdrawn in your head.\n"
		+ (string)"It is unlikely that you expected to have to fight a rat.\n";

	phrase["5EN"] = (string)"To your surprise, the rat turned out to be assertive and reckless.\n"
		+ (string)"\"Amazing creature without the instinct of self-preservation,\" you thought, and went further into the depths of the cave.\n\n"
		+ (string)"Perhaps you'll meet this opponent again in the future.\n";

	phrase["1RU"] = (string)"���� �� ����� � ������ �� ���� ������� � ����� ����, �� ������, ������ ������, �� ������������ � ��������.\n"
		+ (string)"��������, ��� ����������� ������� ������ ����� ������������.\n"
		+ (string)"��������, ���� ��� ������������ ������ ��������.\n"
		+ (string)"� ������: � ������� ����� ����� ����, � � ��� � ����� ��� �� ������ ��������� �����.\n"
		+ (string)"���������� �� ����� ������, �� ���������� ������� �����. �����, ��� ����� ���� ���������� ����������.\n"
		+ (string)"������ ����� ����.\n";

	phrase["2RU"] = (string)"���, ������� ��! ������ �������� ������ ��� ������ �� �����, � �������, ������ �����, ��������� ��������!\n"
		+ (string)"�� ����������� ������ �� ����, �������� ������ �� ����.\n"
		+ (string)"�� ����� �� ������ �����, ������� ������������ �� �����. ����� ����, ������� �����.\n"
		+ (string)"�����, ��� ������.\n"
		+ (string)"������ ����� ����� ����.\n";

	phrase["3RU"] = (string)"������������ ������� � ������, �� ����������� ������ ������.\n"
		+ (string)"������� ������� ������������ �� ���� ������� ������;\n"
		+ (string)"��������, ������� �������-�������� ����� ����� �������� ���� ������.\n"
		+ (string)"���� ������� ������ �����, ����� ��������, ��� ������� ������ ���������� ��������� ��������.\n"
		+ (string)"������, ������������ ����� ���������� ���-�� ������������ �������, ��-�� ���� �� �� ������.\n";

	phrase["4RU"] = (string)"������������ �� ������ ������ ����� �������� ����� ����. ����� ����� ����� ���� ����.\n"
		+ (string)"���� ����� ���� �� �����: ������ �����, ��� ����� � ��������� ���������� ��������.\n"
		+ (string)"���� ����� �������� �� �������� ������������ (���� ����� ������ ������ ����� ������� �������).\n"
		+ (string)"Ÿ ������ ���-�� ������� ���������� � ����� ������.\n"
		+ (string)"���� �� �� �������, ��� ������� ������� � ������.\n";

	phrase["5RU"] = (string)"�� ���������, ����� ��������� ���������� � ������� �� ������.\n"
		+ (string)"\"������������ �������� ��� ��������� ��������������\", �������� �� � ����� ������ ������ ������.\n\n"
		+ (string)"��������, � ������� ��� ��� ���������� ���� ���������.\n";
}

OutputChapterFast::OutputChapterFast()
{/*
	headers.insert("1EN");
	headers.insert("2EN");
    */
	headers.insert("1RU");
	headers.insert("2RU");
/*
	phrase["1EN"] = (string)"If you were sure in your idea before entering the cave, now, stepping inside, you stopped in doubt.\n"
		+ (string)"Possibly, it manifests a sense of fear of the unknown.\n"
		+ (string)"Possibly, The plan was not well thought out.\n"
		+ (string)"So the truth is: darkness often reigns in caves, and you do not have a single source of light with you.\n"
		+ (string)"Back at the camp site, you made a simple torch. Fortunately, there were enough materials for this.\n"
		+ (string)"Now you can go.\n";

	phrase["2EN"] = (string)"No, of course not! It is impossible to carelessly walk without a weapon in the place where the monster most likely lurked!\n"
		+ (string)"But there was no suitable weapon, any weapon.\n"
		+ (string)"You took a stick out of the fire, a little charred at the end. The corner smoldered, exuding heat.\n"
		+ (string)"Better than nothing.\n"
		+ (string)"Now you can go (for sure).\n";*/

	phrase["5EN"] = (string)"To your surprise, the rat turned out to be assertive and reckless.\n"
		+ (string)"\"Amazing creature without the instinct of self-preservation,\" you thought, and went further into the depths of the cave.\n\n"
		+ (string)"Perhaps you'll meet this opponent again in the future.\n";

	phrase["1RU"] = (string)"�������� � ��� � ������ �������� �����.\n"
		+ (string)"�� ��� �� ������������ ����� ����������� ������� � �� ����� �����������.\n"
		+ (string)"\"�������, �� �� �������� ��������� � ��������� �����. ����� �������� �������\"\n"
		+ (string)"��������, �� ��������� � ������� ��������; ��� ���� ���� �������.\n"
		+ (string)"����� ���� ��������� ��� ���� �����: � ����� �� ��� ���������� ��� � ���, � ������ - ��� � ������, � ������� - ���������� �����.\n";

	phrase["2RU"] = (string)"��� ������ �� ����� ������, � �������� ��������� �������, ���� �� ������ � ���.\n"
		+ (string)"������, ������� ���������.\n"

}

string input::get()
{
	string x;
	getline(cin, x);
	for (int i = 0; i < (int)x.size(); ++i)
	{
		while (x[i] == ' ')
		{
			x.erase(i, 1);
		}
	}
	return x;
}

OutputFight::OutputFight()
{
	headers.insert("PTurnEN");
	headers.insert("MTurnEN");
	headers.insert("PTurnRU");
	headers.insert("MTurnRU");

	phrase["PTurnEN"] = (string)"You go first\n";
	phrase["MTurnEN"] = (string)"Your opponent goes first\n";
	phrase["PTurnRU"] = (string)"�� ������ ������\n";
	phrase["MTurnRU"] = (string)"��� ��������� ����� ������\n";
}

OutputCreature::OutputCreature()
{
	headers.insert("DMGRU");
	headers.insert("CritRU");
	headers.insert("PHeroListRU");
	headers.insert("PHeroAttack1RU");
	headers.insert("PHeroSuperAttack1RU");
	headers.insert("PWarriorListRU");
	headers.insert("PWarriorAttack1RU");
	headers.insert("PWarriorSuperAttack1RU");
	headers.insert("PMageListRU");
	headers.insert("PMageAttack1RU");
	headers.insert("PMageSuperAttack1RU");
	headers.insert("PArcherListRU");
	headers.insert("PArcherAttack1RU");
	headers.insert("PArcherSuperAttack1RU");
	headers.insert("WrongInputRU");
	headers.insert("NotEnoughManaRU");

    headers.insert("MRatAttack1RU");
    headers.insert("MRatAttack2RU");
    headers.insert("MRatSuperAttack1RU");
    headers.insert("MGelbinAttack1RU");
    headers.insert("MGelbinSuperAttack1RU");
    headers.insert("MSpiderAttack1RU");
    headers.insert("MSpiderSuperAttackRU");

	//phrase["DMGRU"] = (string)"�����.\n";
	//phrase["CritRU"] = (string)"(1) ����������� ����!\n";

	phrase["PHeroListRU"] = (string)"(1) ���������\n"
        + (string)"(2) ���������� (���������: 2 ����)\n";

	phrase["PHeroAttack1RU"] = (string)"�� ������� �� ����� ������ � ������� ";

	phrase["PHeroSuperAttack1RU"] = (string)"�� ������� ��� �����;"
        + (string)"�������������, �� ������� ����� ������ � ������� ";

	phrase["PWarriorListRU"] = (string)"(1) ���������\n"
        + (string)"(2) ���������� (���������: 1/2 �� ������������� ������ ����)\n";

	phrase["PWarriorAttack1RU"] = (string)"�� ������� ���������� ����� � ������� ";

	phrase["PWarriorSuperAttack1RU"] = (string)"�� ������������ � �������� ����� ����� �����;\n"
        + (string)"���� ������ �� ����� ���������� � ��� � ������� ";

	phrase["PMageListRU"] = (string)"(1) ���������\n"
        + (string)"(2) ���������� (���������: 5 ����)\n";

	phrase["PMageAttack1RU"] = (string)"�� ������� ������� ���������� ������� � ������� ";

	phrase["PMageSuperAttack1RU"] = (string)"�� ������������� ������� �������� ���;\n"
        + (string)"�� ��������������� � ������� ���������� � ���; ���� �� ������� ";

	phrase["PArcherListRU"] = (string)"(1) ���������\n";
	phrase["PArcherAttack1RU"] = (string)"�� �������� ����� ������� � ������� ";
	phrase["PArcherSuperAttack1RU"] = (string)"�� ���������������� �� ���������� � �������� ��� ������ �����;\n"
        + (string)"������, ����� ����, ������� ����������� ���� � ������� ���������� � ���; �� ������� ";

	phrase["MRatAttack1RU"] = (string)"����� ������ ��� � ������� ";
	phrase["MRatAttack2RU"] = (string)"������ ���� ��������� � ������ ����� ����� ����; ����� ������� ��� ";

	phrase["MRatSuperAttack2RU"] = (string)"����� ������ ���.\n"
        + (string)"��������, �� ����������� �����, �����, ���������, ����������� �������� � ��������� ������� ����.\n"
        + (string)"�� ������� ������� �� ���������� � ��������� ������� ����� �� ����� ������.\n"
        + (string)"����� ��� ���� (��� ���) �� ����������� ��������� �����, ��� �� ������ ������ � �������.\n"
        + (string)"���� ����, �����, ������ �� ����� �����.\n";

	phrase["MGelbinAttack1RU"] = (string)"������ ���� ��� �������� � ������� ";
	phrase["MGelbinSuperAttack1RU"] = (string)"������ ������� ��������� �����;\n"
        + (string)"�� ������� ��������� ����: �� ��������� ";

	phrase["MSpiderAttack1RU"] = (string)"���� ������ ��� � ������� ";
	phrase["MSpiderSuperAttackRU"] = (string)"���� �������� � ��� ��������;\n"
        + (string)"������� ��������� ���: �� ������� ��������!";

	//phrase["WrongInputRU"] = (string)"�� ����� �� ������ ��������������� �� �������.";

	//phrase["NotEnoughManaRU"] = (string)"(1) �� ������� ����!\n";
}

void OutputCreature::callHealth(int healthCur, int health)
{
	call("Health");
	cout << healthCur << "/" << health << endl;
}


void OutputCreature::callMana(int manaCur, int mana)
{
	call("Mana");
	cout << manaCur << "/" << mana << endl;
}

void OutputCreature::callDamage(int damage)
{
	cout << " " << damage << " ";
}

void OutputCreature::callAttack(string str, int damage, int randNumber)
{
	str += to_string(RPGUtils::getRandom(1, randNumber)) + lang;
	call(str, 1);
	callDamage(damage);
	call("DMG", 1);
}
