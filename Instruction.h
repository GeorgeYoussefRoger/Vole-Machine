#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <regex>
#include <iostream>
using namespace std;

class Instruction {
protected:
    char opCode; // Operation code for the instruction
    string operand; // Operand associated with the instruction
    string address; // Address where the instruction is located
public:
    Instruction();
    Instruction(string instIn,string a);
    bool validateInstruction();
    string getCode();
    char getOpCode();
    string getOperand();
};

#endif