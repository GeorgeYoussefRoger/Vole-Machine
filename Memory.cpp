#include "Memory.h"

Memory::Memory() = default;

void Memory::setValue(string v) {
    value = v;
}

string Memory::getValue() {
    return value;
}

void Memory::setAddress(string a) {
    address = a;
}

string Memory::getAddress() {
    return address;
}

void Memory::clearMemory() {
    value = "00";
}