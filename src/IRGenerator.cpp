#include "IRGenerator.h"

using namespace std;

IRGenerator::IRGenerator(IRProgram *newIR) {
    ir = newIR;
    currentIRFunc = nullptr;
    targetCodes->clear();
}