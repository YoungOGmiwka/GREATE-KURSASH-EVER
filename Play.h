#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Sportsman.h"
#include <fstream>

class Play{
public:
    Play();
    ~Play();
    void Add();
    void Del();
    void Load();
    void Save();
    void Print();
    void Start();
    Sportsman& getSportsman();
private:
    std::list<Sportsman*> list_sportsmans_;
    std::string logFile;
};