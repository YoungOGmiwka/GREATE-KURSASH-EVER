<<<<<<< HEAD
#include "Client.h"

Client::Client(Sportsman& People) : People_(People) {
	this->People_.Subscribe(this);
	std::cout << "[Клиент подписался]\n";
}

Client::~Client()
{
	std::cout << "[Клиент отключился]\n";
}

void Client::Update(const std::string& message_from_subject)
{
	message_from_subject_ = message_from_subject;
	PrintInfo();
}

void Client::RemoveMeFromTheList()
{
	People_.Unsubscribe(this);
	std::cout << "Клиент убрал себя из списка подписок.\n";
}

void Client::PrintInfo()
{
	std::cout << "Клиент: получил сообщение --> " << this->message_from_subject_ << "\n";
}

void Client::Subscribe(Sportsman& People)
{
	People_.Unsubscribe(this);
	People_ = People;
	this->People_.Subscribe(this);
	std::cout << "[Подписка]\n";
}
=======
#include "Client.h"

Client::Client(Sportsman& People) : People_(People) {
    this->People_.Subscribe(this);
    std::cout << "[Подписка]\n";
}

Client::~Client()
{
    std::cout << "[Уход]\n";
}

void Client::Update(const std::string& message_from_subject)
{
    message_from_subject_ = message_from_subject;
    PrintInfo();
}

void Client::RemoveMeFromTheList()
{
    People_.Unsubscribe(this);
    std::cout << "Клиент убрал себя из списка подписок.\n";
}

void Client::PrintInfo()
{
    std::cout << "Клиент: получил сообщение --> " << this->message_from_subject_ << "\n";
}

void Client::Subscribe(Sportsman& People)
{
    People_.Unsubscribe(this);
    People_ = People;
    this->People_.Subscribe(this);
    std::cout << "[Подписка]\n";
}
>>>>>>> 096d3fce3232ecc076225a7272ea14301bc6b53d
