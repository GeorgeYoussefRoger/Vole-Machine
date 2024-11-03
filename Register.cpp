#include "Register.h"

Register::Register() { address = "", value = ""; }

void Register::setValue(string v) {
    value = v;
}

string Register::getValue() {
    return value;
}

void Register::setAddress(string a) {
    address = a;
}

string Register::getAddress() {
    return address;
}

void Register::clearRegister() {
    value = "00";
}