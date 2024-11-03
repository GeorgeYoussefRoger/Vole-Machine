#include "PC.h"
#include "Machine.h"

PC::PC(): currentAddress("00") {}

void PC::setCounterAddress(string curAddressIn) {
    currentAddress = curAddressIn;
}

string PC::getCounterAddress() {
    return currentAddress;
}

void PC::incrementCounter() {
    string x = Machine::toHex(Machine::toDec(currentAddress) + 2);
    if (x.size() == 1) {
        currentAddress = '0' + x;
    }
    else {
        currentAddress = x;
    }
}