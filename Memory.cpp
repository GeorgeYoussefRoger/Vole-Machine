#include "Memory.h"

// Default constructor for Memory class
Memory::Memory() = default;

// Sets the value of this memory cell
void Memory::setValue(string v) {
    value = v;
}

// Retrieves the current value of this memory cell
string Memory::getValue() {
    return value;
}

// Sets the address of this memory cell
void Memory::setAddress(string a) {
    address = a;
}

// Retrieves the address of this memory cell
string Memory::getAddress() {
    return address;
}

// Clears the memory cell by setting its value to "00"
void Memory::clearMemory() {
    value = "00";
}