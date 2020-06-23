#include "Sportsman.h"

void Sportsman::Save()
{
}

void Sportsman::Load(std::ifstream &fin)
{

}

void Sportsman::RandomParams()
{
    srand(time(NULL));
    Speed = rand() % 20 + 80;
    Lucky = rand() % 100;
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

Sportsman::Sportsman(std::string Name_, std::string Counry_, std::string BirthDate_, std::string WinsCount_)
    : Counry(Counry_), Name(Name_), BirthDate(BirthDate_), WinsCount(WinsCount_) 
{
    std::cout << "Добавление спортсмена" << std::endl;
}

void Sportsman::getInfo()
{
    std::cout << std::setw(5) << Counry << std::setw(10)<< Name << std::setw(20) << BirthDate << std::setw(10) << WinsCount <<std::endl;
}
