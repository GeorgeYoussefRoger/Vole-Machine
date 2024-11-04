#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <regex>
#include <iostream>
using namespace std;

class Instruction {
protected:
    char opCode;
    string operand;
    string address;
public:
    Instruction();
    Instruction(string instIn,string a);
    bool validateInstruction();
    string getCode();
    char getOpCode();
    string getOperand();
};

#endif