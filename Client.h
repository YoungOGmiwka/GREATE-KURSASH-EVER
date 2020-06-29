#pragma once
#include "Play.h"

class Client : public Subscriber {
public:
	Client(Sportsman& People);
	virtual ~Client();
	void Update(const std::string& message_from_subject) override;
	void RemoveMeFromTheList();
	void PrintInfo();
	void Subscribe(Sportsman& People);
private:
	std::string message_from_subject_;
	Sportsman& People_;
	int number_;
};
