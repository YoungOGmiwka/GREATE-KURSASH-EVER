#include "Client.h"

Client::Client(Sportsman& People) : People_(People) {
    this->People_.Subscribe(this);
    std::cout << "[��������], � ������ \"" << ++Client::static_number_ << "\".\n";
    this->number_ = Client::static_number_;
}

Client::~Client()
{
    std::cout << "[����], � ������ \"" << this->number_ << "\".\n";
}

void Client::Update(const std::string& message_from_subject)
{
    message_from_subject_ = message_from_subject;
    PrintInfo();
}

void Client::RemoveMeFromTheList()
{
    People_.Unsubscribe(this);
    std::cout << "������ \"" << number_ << "\" ����� ���� �� ������ ��������.\n";
}

void Client::PrintInfo()
{
    std::cout << "������ \"" << this->number_ << "\": ������� ��������� --> " << this->message_from_subject_ << "\n";
}