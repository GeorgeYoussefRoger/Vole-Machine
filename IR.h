#ifndef IR_H
#define IR_H

#include "Instruction.h"

class IR : public Instruction { // IR class inherits from Instruction class
public:
    IR();
    void setInstruction(Instruction inst);
    string getInstruction();
};

#endif