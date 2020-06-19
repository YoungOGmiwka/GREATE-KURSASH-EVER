#pragma once
#include "Sportsman.h"

class Play{
public:
    Play();
    ~Play();
    void Add();
    void Del();
    void Load();
private:
    std::list<Sportsman*> list_sportsmans_;
};