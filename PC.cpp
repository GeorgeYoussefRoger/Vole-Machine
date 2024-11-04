#include "PC.h"
#include "Machine.h"

// Constructor initializes the program counter to "00"
PC::PC(): currentAddress("00") {}

// Sets the program counter to a specified address
void PC::setCounterAddress(string curAddressIn) {
    currentAddress = curAddressIn;
}

// Retrieves the current address of the program counter
string PC::getCounterAddress() {
    return currentAddress;
}

// Increments the program counter by 2 in hexadecimal format
void PC::incrementCounter() {
    string x = Machine::toHex(Machine::toDec(currentAddress) + 2);
    if (x.size() == 1) {
        currentAddress = '0' + x;
    }
    else {
        currentAddress = x;
    }
}