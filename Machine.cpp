#include "Machine.h"

// Constructor initializes registers and memory with default values and addresses
Machine::Machine() {
    short count = 0;
    for (auto& i : reg) {
        i.setAddress('0' + toHex(count++));
        i.setValue("00");
    }
    count = 0;
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            string address = toHex(i) + toHex(j);
            memory[i][j].setAddress(address);
            memory[i][j].setValue("00");
        }
    }
}

// Sets the machine to single-step mode based on input parameter
void Machine:: singleStep(bool s) {
    steps = s;
}

// Converts a decimal fraction to binary
string Machine::fractionToBin(float fraction, int numBits) {
    string binaryFraction = "";
    for (int i = 0; i < numBits; ++i) {
        fraction *= 2;
        int intPart = static_cast<int>(fraction);
        binaryFraction += to_string(intPart);
        fraction -= intPart;
    }
    return binaryFraction;
}

// Converts a float value to a binary
string Machine::floatToBin(float value) {
    string ans = "";
    if (value < 0) {
        ans += "1";
    }
    else {
        ans += "0";
    }
    int real = value;
    float frac = value - real;
    string realb = intToBin(real), fracb = fractionToBin(frac, 4);
    while (realb[0] == '0') {
        realb.erase(0,1);
    }
    string ex = intToBin(((int) realb.size() + 4));
    while(ex[0] == '0') {
        ex.erase(0,1);
    }
    ans += ex;
    if (realb.size() < 4) {
        for (int i = 0; i < fracb.size(); ++i) {
            realb += fracb[i];
            if (realb.size() == 4) {
                break;
            }
        }
    }
    ans += realb;
    return ans;
}

// Converts decimal to hexadecimal
string Machine::toHex(int dec) {
    string result;
    if (dec < 10) {
        result += static_cast<char>('0' + dec);
    }
    else {
        while (dec > 0) {
            int remainder = dec % 16;
            if (remainder < 10) {
                result = static_cast<char>('0' + remainder) + result;
            }
            else {
                result = static_cast<char>('A' + remainder - 10) + result;
            }
            dec /= 16;
        }
    }
    return result;
}

// Converts a hexadecimal string to a decimal
unsigned short Machine::toDec(string hexString) {
    int result = 0;
    for (char x : hexString) {
        if (isdigit(x)) {
            result = result * 16 + (x - '0');
        }
        else if (isxdigit(x)) {
            if (isupper(x)) {
                result = result * 16 + (x - 'A' + 10);
            }
            else {
                result = result * 16 + (x - 'a' + 10);
            }
        }
    }
    return result;
}

// Converts a single hexadecimal character to decimal
unsigned short Machine::toDec(char& hexChar) {
    int result = hexChar - '0';
    if (result <= 9) {
        return result;
    }
    else {
        return result - 7;
    }
}

// Converts binary string to integer
long Machine::binToInt(string Binary_num) {
    long ans{ 0 };
    for (int i = 0; i < (int)Binary_num.size(); ++i) if (Binary_num[i] == '1') ans += (1 << (Binary_num.size() - i - 1));
    return ans;
}

// Converts integer to binary string
string Machine::intToBin(long long num) {
    string binary_num{ "" };
    while (num >= 1) {
        if ((num & 1)) binary_num = "1" + binary_num;
        else binary_num = "0" + binary_num;
        num /= 2;
    }
    while (binary_num.size() < 8) {
        binary_num = "0" + binary_num;
    }
    return binary_num;
}

// Adds two binary strings and returns the result
string Machine::addBin(string a, string b) {
    bitset<8> bitsetA(a);
    bitset<8> bitsetB(b);
    bitset<8> result = bitsetA.to_ulong() + bitsetB.to_ulong();
    return result.to_string();
}

// Converts binary string to hexadecimal
string Machine::binaryToHex(const string& binaryString) {
    bitset<32> bitset(binaryString);
    unsigned long long decimalValue = bitset.to_ullong();
    ostringstream stream;
    stream << hex << decimalValue;
    return stream.str();
}

// Converts binary string to floating-point decimal value
float Machine::floatToDec(string binary) {
    string expo = binary.substr(1, 3);
    int Expo = binToInt(expo);
    Expo -= 4;
    string mantessa = binary.substr(4);
    string realPart = "";
    if (Expo < 0) {
        Expo = abs(Expo);
        while (Expo) {
            mantessa = "0" + mantessa;
            Expo--;
        }
    }
    else {
        for (int i = 0; i < Expo; ++i) {
            realPart += mantessa[0];
            mantessa.erase(0, 1);
        }
    }
    float ans = 0.0;
    if (realPart.size()) {
        ans = binToInt(realPart);
    }
    for (int i = 1; i <= (int)mantessa.size(); ++i) {
        if (mantessa[i - 1] == '1') ans += pow(2, -i);
    }
    return ans;
}

// Executes a single instruction, performs action based on opcode
void Machine::executeOne(Instruction instr, short x) {
    cout << "\n=======================[Executing of " << instr.getCode() << "]=========================\n";
    cout << "\n=====[PC: " << counter.getCounterAddress() << "]=====\n";
    string XY{ instructions[x].getOperand().substr(1, 2) };
    unsigned short R { toDec(instructions[x].getOperand()[0]) }, X { toDec(XY[0]) }, Y { toDec(XY[1]) };
    string s, t;
    int S, T;
    instructionReg.setInstruction(instructions[x]);
    cout << "\nIR: " << instructionReg.getInstruction() << endl;
    s = reg[X].getValue();
    t = reg[Y].getValue();
    cout << "\n=======================[Decoding of " << instr.getCode() << "]==========================\nOpcode: "
    << instr.getOpCode() << "\nR: " << instr.getOperand()[0] << "\nX: " << XY[0] << "\nY: " << XY[1] << endl;
    switch (instructions[x].getOpCode()) {
        case('1'):
            reg[R].setValue(memory[X][Y].getValue());
            counter.incrementCounter();
            break;
        case('2'):
            reg[R].setValue(XY);
            counter.incrementCounter();
            break;
        case('3'):
            if (XY == "00") {
                memory[0][0].setValue(reg[R].getValue());
                cout << "\n(DISPLAY: " << memory[0][0].getValue() << ")\n";
            }
            else {
                memory[X][Y].setValue(reg[R].getValue());
            }
            counter.incrementCounter();
            break;
        case('4'):
            reg[Y].setValue(reg[X].getValue());
            counter.incrementCounter();
            break;
        case('5'):
            S = toDec(s), T = toDec(t);
            s = intToBin(S); t = intToBin(T);
            reg[R].setValue(binaryToHex(addBin(s, t)));
            counter.incrementCounter();
            break;
        case('6'):
            float x;
            S = toDec(s);
            T = toDec(t);
            x = floatToDec(intToBin(S)) + floatToDec(intToBin(T));
            reg[R].setValue(toHex(binToInt(floatToBin(x))));
            counter.incrementCounter();
            break;
        case('B'):
            if (reg[R].getValue() == reg[0].getValue()) {
                counter.setCounterAddress(XY);
                string inst{ "" };
                inst = inst + memory[toDec(XY[0])][toDec(XY[1])].getValue() + memory[toDec(XY[0])][(toDec(XY[1])) + 1].getValue();
                x = toDec(counter.getCounterAddress());
            }
            else {
                counter.incrementCounter();
            }
            break;
        case('C'):
            counter.incrementCounter();
            cout << "HALTED\n";
            return;
        default:
            cout << "Invalid opcode\n";
    }
}

// Fetches and executes instructions in single-step mode
void Machine::fetch() {
    if (instructions.empty()) {
        cout << "Please input file first.\n";
        exit(404);
    }
    unsigned short x { 0 };
    singleStep:
    if (instructions[x].getCode() == "C000") {
        cout << "HALT\n\n";
        this->print();
        exit(0);
    }
    if (steps) {
        x++;
        executeOne(instructions[x], x);
    }
    cout << "\nContinue Y/N ?\n";
    char in;
    cin >> in;
    in = tolower(in);
    if (in == 'y') {
        goto singleStep;
    }
    else {
        return;
    }
}

// Loads instructions from a file into the instruction vector
void Machine::loadInstructions() {
    cout << "\n=============================[Loading File]=============================\n";
    cout << "Enter Filename (with extension .txt):";
    string f;
    cin >> f;
    string g;
    ifstream file(f);
    if (file.fail()) {
        cout << f << " is not found!\n";
        return;
    }
    else
        cout << f << " is opened\n";
    while (getline(file, g)) {
        unsigned short x { 0 };
        if (Instruction(g, toHex(x)).validateInstruction()) {
            x++;
            instructions.push_back(Instruction(g,toHex(x)));
        }
        else {
            cout << "Instructions failed to load, Please make sure of the format!\n";
            exit(500);
        }
    }
    cout << "-----------------\n";
    for (size_t i = 0, j = 0, y = 0; i < instructions.size() * 2; i++, y++, j++) {
        if (y == 16)
            y = 0;
        string opCode{ instructions[i / 2].getCode() };
        if (!(j & 1))
            memory[j / 16][y].setValue(opCode.substr(0, 2));
        else
            memory[j / 16][y].setValue(opCode.substr(2, 2));
    }
}

// Executes all instructions starting from a user-defined Program Counter (PC) address
void Machine::execute() {
    cout << "Enter counter (Hex) to start from: ";
    string cAddress;
    cin >> cAddress;
    counter.setCounterAddress(cAddress);
    cout << "\n==================================[Executing]==================================\n";
    for (size_t i = toDec(counter.getCounterAddress()); i < instructions.size(); i++) {
        cout << "\n=====[PC: " << counter.getCounterAddress()<<"]=====\n";
        string XY{ instructions[i].getOperand().substr(1, 2) };
        unsigned short R{ toDec(instructions[i].getOperand()[0]) },
        X{toDec(XY[0])}, Y{ toDec(XY[1]) };
        string s,t;
        int S,T;
        instructionReg.setInstruction(instructions[i]);
        cout << "\nIR: " << instructionReg.getInstruction() << endl;
        s = reg[X].getValue();
        t  = reg[Y].getValue();
        switch (instructions[i].getOpCode()) {
            case('1'):
                reg[R].setValue(memory[X][Y].getValue());
                counter.incrementCounter();
                break;
            case('2'):
                reg[R].setValue(XY);
                counter.incrementCounter();
                break;
            case('3'):
                if (XY == "00") {
                    memory[0][0].setValue(reg[R].getValue());
                    cout << "(DISPLAY: "<< memory[0][0].getValue() <<")\n";
                }
                else
                    memory[X][Y].setValue(reg[R].getValue());
                counter.incrementCounter();
                break;
            case('4'):
                reg[Y].setValue(reg[X].getValue());
                counter.incrementCounter();
                break;
            case('5'):
                S = toDec(s) ,  T = toDec(t);
                s= intToBin(S); t = intToBin(T);
                reg[R].setValue(binaryToHex(addBin(s, t)));
                counter.incrementCounter();
                break;
            case('6'):
                float x;
                S = toDec(s);
                T = toDec(t);
                x = floatToDec(intToBin(S)) + floatToDec(intToBin(T));
                reg[R].setValue(toHex(binToInt(floatToBin(x))));
                counter.incrementCounter();
                break;
            case('B'):
                if (reg[R].getValue() == reg[0].getValue()) {
                    counter.setCounterAddress(XY);
                    string inst{""};
                    inst = inst + memory[toDec(XY[0])][toDec(XY[1])].getValue() + memory[toDec(XY[0])][(toDec(XY[1]))+1].getValue();
                    i = toDec(counter.getCounterAddress());
                }
                else {
                    counter.incrementCounter();
                }
                break;
            case('C'):
                counter.incrementCounter();
                cout << "HALTED\n";
                this->print();
                return;
            default:
                cout << "Invalid opcode\n";
        }
    }
}

// Prints the current status of registers and memory
void Machine::print() {
    cout << "\nRegister:\n";
    for (auto i : reg) {
        cout << i.getAddress() << " : " << i.getValue() << endl;
    }
    cout <<"\nMemory:\n";
    for (const auto& i : memory) {
        for (auto j : i)
            cout << j.getAddress() << ':' << j.getValue() << "  ";
        cout << endl;
    }
}

// Clears memory and registers to reset machine state
void Machine::clear() {
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            memory[i][j].clearMemory();
        }
    }
    for (auto& i : reg) {
        i.clearRegister();
    }
}