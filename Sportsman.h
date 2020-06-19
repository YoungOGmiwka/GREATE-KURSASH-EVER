#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Tennis.h"

class Sportsman : public Tennis
{
	std::string counry;
	std::string Name;
	std::string BirthDate;
	std::string WinsCount;
	int Speed;
	int Lucky;
    std::list<Subscriber*> list_subs_;
    std::string message_;
public:
	void Save();
	void Load(std::ifstream fin);
    virtual ~Sportsman();
    /**
     * Методы управления подпиской.
     */
    void Subscribe(Subscriber* observer) override;
    void Unsubscribe(Subscriber* observer) override;
    void Notify() override;
    void CreateMessage(std::string message = "Empty");
    void HowManyClient();
};

