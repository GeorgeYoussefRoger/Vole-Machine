#include "IR.h"

// Default constructor for IR class
IR::IR() {}

// Sets the current instruction by copying opCode and operand from the given Instruction object
void IR::setInstruction(Instruction inst) {
    opCode = inst.getOpCode();
    operand = inst.getOperand();
}

// Returns the full instruction (opCode + operand) as a string
string IR::getInstruction() {
    string s { "" };
    s = s + opCode + operand;
    return s;
}