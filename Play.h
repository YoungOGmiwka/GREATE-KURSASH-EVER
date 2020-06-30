<<<<<<< HEAD
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Sportsman.h"
#include <fstream>

class Play {
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
=======
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
>>>>>>> 096d3fce3232ecc076225a7272ea14301bc6b53d
};