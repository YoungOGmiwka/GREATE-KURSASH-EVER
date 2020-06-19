#pragma once
#include "Play.h"

class Client : public Subscriber {
public:
    Client(Sportsman& People);
    virtual ~Client();
    void Update(const std::string& message_from_subject) override;
    void RemoveMeFromTheList();
    void PrintInfo();

private:
    std::string message_from_subject_;
    Sportsman& People_;
    static int static_number_;
    int number_;
};
