#ifndef MEMORY_H
#define MEMORY_H

#include <string>
using namespace std;

class Memory {
    string value;
    string address;
public:
    Memory();
    void setValue(string v);
    string getValue();
    void setAddress(string a);
    string getAddress();
    void clearMemory();
};

#endif
