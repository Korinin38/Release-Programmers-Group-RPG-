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

	phrase["PauseRU"] = "*\nДля продолжения нажмите Enter\n*\n";
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


	phrase["LangListEN"] = "1.Русский\n2.English(coming soon)\n";

	phrase["HeaderEN"] = "Small Release Programmer Group (Small RPG)\n";

	phrase["MenuEN"] = (string)"Choose an option:\n"
		+ (string)"(1) Start New Game\n\n"
		+ (string)"(0) Exit\n";

	phrase["WrongInputEN"] = "KEK, maybe choose only 1 or 0?\n";

	phrase["LangListRU"] = phrase["LangListEN"];

	phrase["HeaderRU"] = "Small Release Programmer Group (Small RPG)\n";

	phrase["MenuRU"] = (string)"Выберите опцию:\n"
		+ (string)"(1) Начать новую игру\n\n"
		+ (string)"(0) Выйти\n";

	phrase["WrongInputRU"] = "KEK, может, выберешь 1 или 0?\n";
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

	phrase["Confirm3EN"] = (string)"Класс: Лучник.\n"
		+ (string)"Characteristics: 16 health, 4 strength, 4 agility, 4 intelligence (4/4/4 s/a/i)\n"
		+ (string)"Special: gain additional upgrage point for distribution\n"
		+ (string)"Enter Y for choice confirmation or any key for refusal\n";

	phrase["WrongInputEN"] = "KEK, maybe choose 1, 2 or 3?\n";

	phrase["1RU"] = (string)"Много лет тому назад...\n"
		+ (string)"На Земле жили существа ошеломительного размера.\n"
		+ (string)"О них мало известно, ведь в те времена ещё не было людей.\n"
		+ (string)"Единственное, о чём можно сказать с уверенностью, - это то, что они существовали.\n"
		+ (string)"И что их существование прекратилось стремительно.\n";

	phrase["2RU"] = (string)"В один момент на Земле произошло что-то странное.\n"
		+ (string)"Неизвестный объект влетел в верхние слои атмосферы планеты.\n"
		+ (string)"Столкнувшись с поверхностью, он создал разрушительную звуковую волну, что расколола древний Материк на части и практически уничтожила жизнь на Земле.\n";

	phrase["3RU"] = (string)"Жаркий засушливый день, один из обыкновенных здесь для этой поры года.\n"
		+ (string)"Экспедиция нашла в тропическом лесу пещеру, откуда раз в день-два доносились странные звуки.\n"
		+ (string)"Это был не то крик, не то стон, не то рык какого-то зверя.\n"
		+ (string)"Одним из группы были Вы.\n";

	phrase["4RU"] = (string)"Исследователи решили заглянуть в пещеру, но сначала устроили привал: выспаться перед походом было хорошей идеей.\n"
		+ (string)"Однако ночью на лагерь напало неизвестное существо. По звукам, которые это существо издавало, можно было догадаться, что это был обитатель пещеры.\n"
		+ (string)"Темнота ночного леса не позволила вам понять, кто это был, но было ясно - это был кто-то действительно большой.\n";

	phrase["5RU"] = (string)"Наутро, когда на лесную чащу опустился свет, вы поняли, что большинство из вас сильно ранено, а один человек пропал.\n"
		+ (string)"Группа решила вернуться за подмогой, но Вы были не согласны: пропавшего нужно спасти, и как можно скорее.\n"
		+ (string)"Немного отстав, Вы развернулись и устремились ко входу в пещеру.\n"
		+ (string)"Здесь начинается Ваше приключение.\n";

	phrase["ClassRU"] = (string)"Выберите класс (1, 2, 3):\n"
		+ (string)"(1) Воин - мастер ближнего боя. Его тело позволяет ему выдерживать мощные атаки, а удары сильны\n"
		+ (string)"(2) Маг - умелец призыва и медитации. Несмотря на хлипкое телосложение, его присутствие в рядах группы часто приводит к быстрой победе\n"
		+ (string)"(3) Лучник - точный стрелок. Его зоркий глаз позволяет находить слабые места противника и наносить смертоносный урон\n";

	phrase["Confirm1RU"] = (string)"Класс: Воин.\n"
		+ (string)"Характеристики: 20 здоровья, 6 силы, 3 ловкости, 3 интеллекта\n"
		+ (string)"Особенность: урон от атак не подвержен случайному уменьшению\n"
		+ (string)"Введите Y для подтверждения выбора или любой другой ввод для отказа\n";

	phrase["Confirm2RU"] = (string)"Класс: Маг.\n"
		+ (string)"Характеристики: 14 здоровья, 2 силы, 2 ловкости, 8 интеллекта\n"
		+ (string)"Особенность: каждый ход восстанавливает на 1 ед. маны больше\n"
		+ (string)"Введите Y для подтверждения выбора или любой другой ввод для отказа\n";

	phrase["Confirm3RU"] = (string)"Класс: Лучник.\n"
		+ (string)"Характеристики: 16 здоровья, 4 силы, 4 ловкости, 4 интеллекта\n"
		+ (string)"Особенность: Дополнительное очко распределения характеристик\n"
		+ (string)"Введите Y для подтверждения выбора или любой другой ввод для отказа\n";

	phrase["WrongInputRU"] = "KEK, может, выберешь 1, 2 или 3?\n";
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

	phrase["1RU"] = (string)"Если до входа в пещеру Вы были уверены в своей идее, то теперь, шагнув внутрь, вы остановились в сомнении.\n"
		+ (string)"Возможно, это проявляется чувство страха перед неизведанным.\n"
		+ (string)"Возможно, план был недостаточно хорошо продуман.\n"
		+ (string)"И правда: в пещерах часто царит тьма, а у Вас с собой нет ни одного источника света.\n"
		+ (string)"Вернувшись на место лагеря, Вы смастерили простой факел. Благо, для этого было достаточно материалов.\n"
		+ (string)"Теперь можно идти.\n";

	phrase["2RU"] = (string)"Нет, конечно же! Нельзя беспечно гулять без оружия по месту, в котором, скорее всего, затаилось чудовище!\n"
		+ (string)"Но подходящего оружия не было, никакого оружия не было.\n"
		+ (string)"Вы взяли из костра палку, немного обуглившуюся на конце. Уголёк тлел, источая тепло.\n"
		+ (string)"Лучше, чем ничего.\n"
		+ (string)"Теперь точно можно идти.\n";

	phrase["3RU"] = (string)"Вооружившись факелом и палкой, Вы направились внутрь пещеры.\n"
		+ (string)"Обитель монстра представляла из себя обычную пещеру;\n"
		+ (string)"холодные, влажные каменно-глиняные стены слабо отражали свет факела.\n"
		+ (string)"Если поднять голову вверх, можно заметить, что потолок увешан небольшими каменными пеньками.\n"
		+ (string)"Видимо, образующиеся здесь сталактиты кто-то периодически сбивает, из-за чего те не растут.\n";

	phrase["4RU"] = (string)"Безжизненное на первый взгляд место оживляет тихий писк. Здесь нашла приют стая крыс.\n"
		+ (string)"Хотя самой стаи не видно: скорее всего, они живут в небольших тоннельных системах.\n"
		+ (string)"Одна крыса выползла на открытое пространство (если узкий проход пещеры можно назвать таковым).\n"
		+ (string)"Её взгляд как-то недобро отзывается в вашей голове.\n"
		+ (string)"Вряд ли Вы ожидали, что придётся драться с крысой.\n";

	phrase["5RU"] = (string)"На удивление, крыса оказалась напористой и отбитой на голову.\n"
		+ (string)"\"Удивительное существо без инстинкта самосохранения\", подумали Вы и пошли дальше вглубь пещеры.\n\n"
		+ (string)"Возможно, в будущем вам ещё встретится этот противник.\n";
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
	headers.insert("PTurnRU");
	headers.insert("MTurnRU");
	headers.insert("VictoryRU");
	headers.insert("DeathRU");

	phrase["PTurnRU"] = (string)"Вы ходите первым\n";
	phrase["MTurnRU"] = (string)"Ваш противник ходит первым\n";
	phrase["VictoryRU"] = (string)"Вы победили в схватке!\n";
	phrase["DeathRU"] = (string)"Вы погибли.\n";
}

OutputCreature::OutputCreature()
{
	headers.insert("DMGRU");
	headers.insert("CritRU");
	headers.insert("HealthRU");
	headers.insert("ManaRU");
	headers.insert("MTurnRU");
	headers.insert("PTurnRU");
	headers.insert("PHeroListRU");
	headers.insert("PHeroAttack1RU");
	headers.insert("PWarriorListRU");
	headers.insert("PWarriorAttackRU");
	headers.insert("PMageListRU");
	headers.insert("PMageAttackRU");
	headers.insert("PAracherListRU");
	headers.insert("PAracherAttackRU");
	headers.insert("WrongInputRU");
	headers.insert("NotEnoughManaRU"); 

	headers.insert("MRatAttackRU");


	phrase["DMGRU"] = (string)"урона.\n";
	phrase["CritRU"] = (string)" Критический урон!\n";
	phrase["HealthRU"] = (string)"Здоровье: ";
	phrase["ManaRU"] = (string)"Мана: ";
	phrase["MTurnRU"] = (string)"Ход противника\n";
	phrase["PTurnRU"] = (string)"Ваш ход\n";

	phrase["PHeroListRU"] = (string)"(1) Атаковать\n";
	phrase["PHeroAttack1RU"] = (string)"(1) Вы тыкнули во врага палкой и нанесли ";

	phrase["PWarriorListRU"] = (string)"(1) Атаковать\n";
	phrase["PWarriorAttack1RU"] = (string)"Вы тыкнули во врага палкой и нанесли ";

	phrase["PMageListRU"] = (string)"(1) Атаковать\n";
	phrase["PMageAttack1RU"] = (string)"Вы тыкнули во врага палкой и нанесли ";

	phrase["PArcherListRU"] = (string)"(1) Атаковать\n";
	phrase["PArcherAttack1RU"] = (string)"Вы тыкнули во врага палкой и нанесли ";

	phrase["WrongInputRU"] = (string)"Вы никак не можете сосредоточиться на схватке.\n"
		+(string)"Необходимо выбрать один из возможных вариантов:\n";

	phrase["NotEnoughManaRU"] = (string)"(1) Не хватает маны!\n";

	phrase["MRatAttackRU"] = (string)"Крыса атакует и наносит";
}

void OutputCreature::callHealth(int healthCur, int health)
{
	call("Health", 1);
	cout << healthCur << "/" << health << endl;
}


void OutputCreature::callMana(int manaCur, int mana)
{
	call("Mana", 1);
	cout << manaCur << "/" << mana << endl;
}

void OutputCreature::callDamage(int damage)
{
	cout << " " << damage << " ";
}

void OutputCreature::callAttack(string str, int damage, int randNumber)
{
	str += to_string(RPGUtils::getRandom(1, randNumber));
	call(str, 1);
	callDamage(damage);
	call("DMG", 1);
}
