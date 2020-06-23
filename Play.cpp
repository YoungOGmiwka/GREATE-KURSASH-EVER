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
	std::cin >> tmp[0];
	std::cin >> tmp[1];
	std::cin >> tmp[2];
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
	std::string tmp[4];
	Sportsman* sTmp;
	while (!file.eof())
	{
		sTmp = new Sportsman;
		sTmp->Load(file);
		list_sportsmans_.push_back(sTmp);
	}
	file.close();
}

void Play::Start()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	logFile = std::to_string(1970 + ltm->tm_year) + "-" + std::to_string(1 + ltm->tm_mon) + "-" + std::to_string(ltm->tm_mday) + "_" + std::to_string(ltm->tm_hour) + "-" + std::to_string(ltm->tm_min) + "-" + std::to_string(ltm->tm_sec) + ".log";
	std::list<Sportsman*>::iterator iterator = list_sportsmans_.begin();
	while (iterator != list_sportsmans_.end()) {
		(*iterator)->RandomParams();
		++iterator;
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
