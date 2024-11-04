#ifndef MACHINE_H
#define MACHINE_H

#include "Memory.h"
#include "Register.h"
#include "Instruction.h"
#include "PC.h"
#include "IR.h"
#include <fstream>
#include <cmath>
using namespace std;

class Machine {
    bool steps;
    vector <Instruction> instructions;
    Memory memory[16][16];
    Register reg[16];
    IR instructionReg;
    PC counter;
public:
    Machine();
    ~Machine();
    void execute();
    void singleStep(bool s);
    void print();
    void loadInstructions();
    void clear();
    static string toHex(int dec);
    static unsigned short toDec(string hexString);
    static unsigned short toDec(char& hexChar);
    string fractionToBin(float fraction, int numBits);
    string floatToBin(float value);
    string binaryToHex(const string& binaryString);
    string addBin(string a, string b);
    string intToBin(long long num);
    long binToInt(string Binary_num);
    void executeOne(Instruction instr, short x);
    float floatToDec(string binary);
    void fetch();
};

#endif