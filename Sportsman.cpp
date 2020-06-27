#include "Sportsman.h"

void Sportsman::Save(std::ofstream& fout)
{
    fout << this->Name << std::endl
        << this->BirthDate << std::endl
        << this->Counry << std::endl
        << this->WinsCount << std::endl;
}

int Sportsman::Load(std::ifstream &fin)
{
    getline(fin, this->Name);
    if (this->Name.empty())
        return -1;
    getline(fin, this->BirthDate);
    getline(fin, this->Counry);
    getline(fin, this->WinsCount);
    return 0;
}

void Sportsman::RandomParams()
{
    Speed = rand() % 20 + 80;
    Lucky = rand() % 100;
}

Sportsman::~Sportsman()
{
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
   // HowManyClient();
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
    std::cout << Counry << std::setw(15)<< Name << std::setw(20) << BirthDate << std::setw(10) << WinsCount <<std::endl;
}
