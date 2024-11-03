#ifndef IR_H
#define IR_H

#include "Instruction.h"

class IR : public Instruction {
public:
    IR();
    void setInstruction(Instruction inst);
    string getInstruction();
};

#endif