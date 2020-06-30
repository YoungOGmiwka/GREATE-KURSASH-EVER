<<<<<<< HEAD
#include "Client.h"

Client::Client(Sportsman& People) : People_(People) {
	this->People_.Subscribe(this);
	std::cout << "[������ ����������]\n";
}

Client::~Client()
{
	std::cout << "[������ ����������]\n";
}

void Client::Update(const std::string& message_from_subject)
{
	message_from_subject_ = message_from_subject;
	PrintInfo();
}

void Client::RemoveMeFromTheList()
{
	People_.Unsubscribe(this);
	std::cout << "������ ����� ���� �� ������ ��������.\n";
}

void Client::PrintInfo()
{
	std::cout << "������: ������� ��������� --> " << this->message_from_subject_ << "\n";
}

void Client::Subscribe(Sportsman& People)
{
	People_.Unsubscribe(this);
	People_ = People;
	this->People_.Subscribe(this);
	std::cout << "[��������]\n";
}
=======
#include "Client.h"

Client::Client(Sportsman& People) : People_(People) {
    this->People_.Subscribe(this);
    std::cout << "[��������]\n";
}

Client::~Client()
{
    std::cout << "[����]\n";
}

void Client::Update(const std::string& message_from_subject)
{
    message_from_subject_ = message_from_subject;
    PrintInfo();
}

void Client::RemoveMeFromTheList()
{
    People_.Unsubscribe(this);
    std::cout << "������ ����� ���� �� ������ ��������.\n";
}

void Client::PrintInfo()
{
    std::cout << "������: ������� ��������� --> " << this->message_from_subject_ << "\n";
}

void Client::Subscribe(Sportsman& People)
{
    People_.Unsubscribe(this);
    People_ = People;
    this->People_.Subscribe(this);
    std::cout << "[��������]\n";
}
>>>>>>> 096d3fce3232ecc076225a7272ea14301bc6b53d
