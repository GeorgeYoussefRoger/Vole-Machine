#include "IR.h"

void IR::setInstruction(Instruction inst) {
    opCode = inst.getOpCode();
    operand = inst.getOperand();
}

IR::IR() {}

string IR::getInstruction() {
    string s { "" };
    s = s + opCode + operand;
    return s;
}