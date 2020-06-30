<<<<<<< HEAD
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
=======
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
>>>>>>> 096d3fce3232ecc076225a7272ea14301bc6b53d
