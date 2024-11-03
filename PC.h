#ifndef COUNTER_H
#define COUNTER_H

#include <string>
using namespace std;

class PC {
    string currentAddress;
public:
    PC();
    void setCounterAddress(string curAddressIn);
    string getCounterAddress();
    void incrementCounter();
};

#endif