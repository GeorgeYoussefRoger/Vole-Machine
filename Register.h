#ifndef REGISTER_H
#define REGISTER_H

#include <string>
using namespace std;

class Register {
    string value;
    string address;
public:
    Register();
    void setValue(string v);
    void setAddress(string a);
    string getValue();
    string getAddress();
    void clearRegister();
};

#endif