

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Instruction {
    public:
        string instruction;
        string opcode;
        int rd;
        int rs1;
        int rs2;
        string funct3;
        string funct7;
        int imm;
        string instructionType;
};

void InstructionFetch() {

}



void InstructionDecode(Instruction &I) {
    I.opcode = I.instruction.substr(25, 7);
    I.instructionType = getInstructionType(I.opcode);
}

// Helper functions

string getInstructionType(string opcode) {
    unordered_map<string, string> opcodeMap(
        {
            {"0110011", "R"},
            {"0010011", "I"},
            {"0000011", "I"},
            {"1100111", "I"},
            {"0100011", "S"},
            {"1100011", "B"},
            {"1101111", "J"},
            {"0110111", "U"},
            {"0010111", "U"}
        }
    );

    return opcodeMap[opcode];
}

int main() {

}