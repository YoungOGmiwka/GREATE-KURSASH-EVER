#include "Client.h"

Client::Client(Sportsman& People) : People_(People) {
    this->People_.Subscribe(this);
    std::cout << "[Подписка], я клиент \"" << ++Client::static_number_ << "\".\n";
    this->number_ = Client::static_number_;
}

Client::~Client()
{
    std::cout << "[Уход], я клиент \"" << this->number_ << "\".\n";
}

void Client::Update(const std::string& message_from_subject)
{
    message_from_subject_ = message_from_subject;
    PrintInfo();
}

void Client::RemoveMeFromTheList()
{
    People_.Unsubscribe(this);
    std::cout << "Клиент \"" << number_ << "\" убрал себя из списка подписок.\n";
}

void Client::PrintInfo()
{
    std::cout << "Клиент \"" << this->number_ << "\": получил сообщение --> " << this->message_from_subject_ << "\n";
}