#ifndef REGISTER_H
#define REGISTER_H

#include <string>
using namespace std;

class Register {
    string value; // The value stored in this register
    string address; // The address of this register
public:
    Register();
    void setValue(string v);
    void setAddress(string a);
    string getValue();
    string getAddress();
    void clearRegister();
};

#endif