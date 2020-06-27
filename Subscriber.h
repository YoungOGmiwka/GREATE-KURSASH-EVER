#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>

class Subscriber {
public:
    virtual ~Subscriber() {};
    virtual void Update(const std::string& message_from_subject) = 0;
};
