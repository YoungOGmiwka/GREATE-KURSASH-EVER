#pragma once
#include "Tennis.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <windows.h>

class Sportsman : public Tennis
{
	std::string Counry;
	std::string Name;
	std::string BirthDate;
	std::string WinsCount;
	std::list<Subscriber*> list_subs_;
	std::string message_;
public:
	int Speed;
	int Lucky;
	void Save(std::ofstream &fout);
	int Load(std::ifstream &fin);
	void RandomParams();
	Sportsman() {};
	virtual ~Sportsman();
	/**
	 * Методы управления подпиской.
	 */
	void Subscribe(Subscriber* observer) override;
	void Unsubscribe(Subscriber* observer) override;
	void Notify() override;
	void CreateMessage(std::string message = "Empty");
	void HowManyClient();
	Sportsman(std::string Name_, std::string Counry_, std::string BirthDate_, std::string WinsCount_);
	void getInfo();
	std::string getName();
};

