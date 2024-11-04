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
    bool steps; // Indicates single-step mode
    vector <Instruction> instructions; // List of loaded instructions
    Memory memory[16][16]; // Memory array with 16x16 structure
    Register reg[16]; // Register array with 16 registers
    IR instructionReg; // Instruction register (IR)
    PC counter; // Program counter (PC)
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