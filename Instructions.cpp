#include "Instruction.h"

// Default constructor for Instruction class
Instruction::Instruction() {}

// Constructor initializes instruction using a provided instruction string and address
Instruction::Instruction(string instIn, string a) :operand("") {
    address = a;
    // Remove "0x" prefix
    regex pattern("0x");
    string result = regex_replace(instIn, pattern, "");
    // Set opCode and extract specific characters for operand
    opCode = result[0];
    operand = operand + result[2] + result[4] + result[5];
}

// Validates the instruction by checking if opCode and operand characters are within valid ranges
bool Instruction::validateInstruction() {
    bool isValid { false };

    if ((opCode > '0' && opCode <= '9') || (toupper(opCode) >= 'A' && toupper(opCode) < 'D')) {
        isValid = true;
    }
    else {
        return 0;
    }

    for (size_t i = 0; i < 3; i++) {
        if (operand[i] >= '0' && (operand[i] <= '9' || toupper(operand[i]) <= 'F')) {
            isValid = true;
        }
        else {
            return 0;
        }
    }
    return isValid;
}

// Returns the full instruction as one string (opCode + operand)
string Instruction::getCode() {
    return (opCode + operand);
}

// Gets the opcode of the instruction
char Instruction::getOpCode() {
    return opCode;
}

// Gets the operand of the instruction
string Instruction::getOperand() {
    return operand;
}