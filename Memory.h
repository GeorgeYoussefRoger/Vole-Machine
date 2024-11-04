#ifndef MEMORY_H
#define MEMORY_H

#include <string>
using namespace std;

class Memory {
    string value; // The value stored in this memory cell
    string address; // The address of this memory cell
public:
    Memory();
    void setValue(string v);
    string getValue();
    void setAddress(string a);
    string getAddress();
    void clearMemory();
};

#endif