#pragma once
#include "Subscriber.h"

class Tennis {
public:
    virtual ~Tennis() {};
    virtual void Subscribe(Subscriber* observer) = 0;
    virtual void Unsubscribe(Subscriber* observer) = 0;
    virtual void Notify() = 0;
};