#include "Play.h"

Play::Play()
{
	std::cout << "Подготовка к началу забега\n";
}

Play::~Play()
{
	std::cout << "Конец забега\n";
}

void Play::Add()
{
	std::string tmp[4];
	std::cout << "Введите имя: ";
	std::cin >> tmp[0];
	std::cout << "Введите страну: ";
	std::cin >> tmp[1];
	std::cout << "Введите дату рождения: ";
	std::cin >> tmp[2];
	std::cout << "Введите число побед: ";
	std::cin >> tmp[3];
	list_sportsmans_.push_back(new Sportsman(tmp[0], tmp[1], tmp[2], tmp[3]));
}

void Play::Del()
{
	if (!list_sportsmans_.size())
	{
		std::cout << "Sportsman's is ZERO" << std::endl;
		return;
	}
	std::list<Sportsman*>::iterator iterator = list_sportsmans_.begin();
	int i = 0;
	int index;
	while (iterator != list_sportsmans_.end()) {
		std::cout << '[' << ++i << ']';
		(*iterator)->getInfo();
		++iterator;
	}
	std::cin >> index;
	iterator = list_sportsmans_.begin();
	for (size_t i = 0; i < index - 1; i++, iterator++);
	list_sportsmans_.remove(*iterator);
}

void Play::Load()
{
	std::ifstream file("Sportsmans.txt");
	Sportsman* sTmp;
	while (!file.eof())
	{
		sTmp = new Sportsman;
		if (sTmp->Load(file) != -1)
			list_sportsmans_.push_back(sTmp);
		else
			delete sTmp;
	}
	file.close();
	std::cout << "Загрузка прошла успешно!" << std::endl;
}

void Play::Save()
{
	std::ofstream file("Sportsmans.txt");
	std::list<Sportsman*>::iterator iterator = list_sportsmans_.begin();
	while (iterator != list_sportsmans_.end()) {
		(*iterator)->Save(file);
		++iterator;
	}
	file.close();
}

void Play::Print()
{
	std::list<Sportsman*>::iterator iterator = list_sportsmans_.begin();
	while (iterator != list_sportsmans_.end()) {
		(*iterator)->getInfo();
		++iterator;
	}
}

void Play::Start()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	logFile = std::to_string(1970 + ltm->tm_year) + "-" + std::to_string(1 + ltm->tm_mon) + "-" + std::to_string(ltm->tm_mday) + "_" + std::to_string(ltm->tm_hour) + "-" + std::to_string(ltm->tm_min) + "-" + std::to_string(ltm->tm_sec) + ".log";
	std::list<Sportsman*>::iterator iterator;
	float max = 0.0;
	Sportsman* sMax = nullptr;
	for (size_t i = 0; i < 5; i++)
	{
		iterator = list_sportsmans_.begin();
		while (iterator != list_sportsmans_.end()) {
			(*iterator)->RandomParams();
			++iterator;
		}
		iterator = list_sportsmans_.begin();
		max = 0.0;
		sMax = nullptr;
		while (iterator != list_sportsmans_.end()) {
			max < (*iterator)->Speed* (*iterator)->Lucky ? max = (*iterator)->Speed * (*iterator)->Lucky , sMax = *(iterator) : NULL;
			++iterator;
		}
		iterator = list_sportsmans_.begin();
		while (iterator != list_sportsmans_.end()) {
			*iterator == sMax ? sMax->CreateMessage("Ваш спортсмен победил!") : (*iterator)->CreateMessage("Ваш спортсмен проиграл!");
			++iterator;
		}
		Sleep(1000);
	}	
	/* Дописать выбор победителя */
}

Sportsman& Play::getSportsman()
{
	std::list<Sportsman*>::iterator iterator = list_sportsmans_.begin();
	int i = 0;
	int index;
	while (iterator != list_sportsmans_.end()) {
		std::cout << '[' << ++i << ']';
		(*iterator)->getInfo();
		++iterator;
	}
	std::cin >> index;
	iterator = list_sportsmans_.begin();
	for (size_t i = 0; i < index-1; i++, iterator++);
	return **iterator;
}
