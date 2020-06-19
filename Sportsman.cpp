#include "Sportsman.h"

void Sportsman::Save()
{
}

void Sportsman::Load(std::ifstream fin)
{
}

Sportsman::~Sportsman()
{
    std::cout << "Спорсмен закончил забег\n";
}

void Sportsman::Subscribe(Subscriber* observer)
{
    list_subs_.push_back(observer);
}

void Sportsman::Unsubscribe(Subscriber* observer)
{
    list_subs_.remove(observer);
}

void Sportsman::Notify()
{
    std::list<Subscriber*>::iterator iterator = list_subs_.begin();
    HowManyClient();
    while (iterator != list_subs_.end()) {
        (*iterator)->Update(message_);
        ++iterator;
    }
}

void Sportsman::CreateMessage(std::string message)
{
    this->message_ = message;
    Notify();
}

void Sportsman::HowManyClient()
{
    std::cout << "На данный матч подписано " << list_subs_.size() << " клиентов.\n";
}
