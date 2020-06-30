<<<<<<< HEAD
#pragma once
#include "Subscriber.h"

class Tennis {
public:
	virtual ~Tennis() {};
	virtual void Subscribe(Subscriber* observer) = 0;
	virtual void Unsubscribe(Subscriber* observer) = 0;
	virtual void Notify() = 0;
=======
#pragma once
#include "Subscriber.h"

class Tennis {
public:
    virtual ~Tennis() {};
    virtual void Subscribe(Subscriber* observer) = 0;
    virtual void Unsubscribe(Subscriber* observer) = 0;
    virtual void Notify() = 0;
>>>>>>> 096d3fce3232ecc076225a7272ea14301bc6b53d
};