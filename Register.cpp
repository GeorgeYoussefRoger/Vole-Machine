#include "Register.h"

// Default constructor for Register class
Register::Register() { address = "", value = ""; } // Initialize address & value to an empty string

// Sets the value of this register
void Register::setValue(string v) {
    value = v;
}

// Retrieves the current value of this register
string Register::getValue() {
    return value;
}

// Sets the address of this register
void Register::setAddress(string a) {
    address = a;
}

// Retrieves the address of this register
string Register::getAddress() {
    return address;
}

// Clears the register by setting its value to "00"
void Register::clearRegister() {
    value = "00";
}