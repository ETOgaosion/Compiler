#include "IRContainers.h"
#include "tools.h"

#include <utility>
#include <fstream>
#include <cstdio>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;

IRFunction::IRFunction(string newFunctionName, SymbolTable *newFunctionTable) {
    functionName = move(newFunctionName);
    localVariables.clear();
    tempVariables.clear();
    codes.clear();
    labels.clear();
    tempCount = 0;
    labelCount = 0;
    frameSize = 8;
    functionTable = newFunctionTable;
}

bool IRFunction::addParamVariable(IRSymbolVariable *newVariable) {
    paramVariables.emplace(newVariable->getSymbolName(), newVariable);
    return true;
}

bool IRFunction::addLocalVariable(int block, IRSymbolVariable *newVariable) {
    localVariables.emplace(newVariable->getSymbolName()+to_string(block), newVariable);
    return true;
}


IRValue* IRFunction::immAddSub(IROperand* op1, IROperand* op2, IROperation op){
    MetaDataType type1 = op1->getMetaDataType();
    MetaDataType type2 = op2->getMetaDataType();
    IRValue* retVal = nullptr;
    if(type1 == MetaDataType::INT){
        int val_a = stoi(op1->getValue());
        switch(type2){
            case MetaDataType::INT: {
                int val_b_i = stoi(op2->getValue());
                if(op == IROperation::ADD) {
                    retVal = new IRValue(MetaDataType::INT, to_string(val_a + val_b_i), {}, false);
                }
                else if (op == IROperation::SUB) {
                    retVal = new IRValue(MetaDataType::INT, to_string(val_a - val_b_i), {}, false);
                }
            }
                break;
            case MetaDataType::FLOAT: {
                float val_b_f = stof(op2->getValue());
                if(op == IROperation::ADD) {
                    retVal = ir->addImmValue(MetaDataType::FLOAT, to_string(val_a + val_b_f));
                }
                else if (op == IROperation::SUB) {
                    retVal = ir->addImmValue(MetaDataType::FLOAT, to_string(val_a - val_b_f));
                }
            }
                break;
            case MetaDataType::DOUBLE: {
                double val_b_d = stod(op2->getValue());
                if(op == IROperation::ADD) {
                    retVal = ir->addImmValue(MetaDataType::DOUBLE, to_string(val_a + val_b_d));
                }
                else if (op == IROperation::SUB) {
                    retVal = ir->addImmValue(MetaDataType::DOUBLE, to_string(val_a - val_b_d));
                }
            }
                break;
            default:
                break;
        }
    } else if (type1 == MetaDataType::FLOAT){
        float val_a = stof(op1->getValue());
        switch(type2){
           case MetaDataType::INT: {
                int val_b_i = stoi(op2->getValue());
                if(op == IROperation::ADD)
                    retVal = ir->addImmValue(MetaDataType::FLOAT, to_string(val_a + val_b_i));
                else if (op == IROperation::SUB)
                    retVal = ir->addImmValue(MetaDataType::FLOAT, to_string(val_a - val_b_i));
           }
                break;
            case MetaDataType::FLOAT: {
                float val_b_f = stof(op2->getValue());
                if(op == IROperation::ADD)
                    retVal = ir->addImmValue(MetaDataType::FLOAT, to_string(val_a + val_b_f));
                else if (op == IROperation::SUB)
                    retVal = ir->addImmValue(MetaDataType::FLOAT, to_string(val_a - val_b_f));
            }
                break;
            case MetaDataType::DOUBLE: {
                double val_b_d = stod(op2->getValue());
                if(op == IROperation::ADD)
                    retVal = ir->addImmValue(MetaDataType::DOUBLE, to_string(val_a + val_b_d));
                else if (op == IROperation::SUB)
                    retVal = ir->addImmValue(MetaDataType::DOUBLE, to_string(val_a - val_b_d));
            }
                break;
            default:
                break;
        }
    } else if (type1 == MetaDataType::DOUBLE){
        double val_a = stod(op1->getValue());
        switch(type2){
            case MetaDataType::INT: {
                int val_b_i = stoi(op2->getValue());
                if(op == IROperation::ADD)
                    retVal = ir->addImmValue(MetaDataType::DOUBLE, to_string(val_a + val_b_i));
                else if (op == IROperation::SUB)
                    retVal = ir->addImmValue(MetaDataType::DOUBLE, to_string(val_a - val_b_i));
            }
                break;
            case MetaDataType::FLOAT: {
                float val_b_f = stof(op2->getValue());
                if(op == IROperation::ADD)
                    retVal = ir->addImmValue(MetaDataType::DOUBLE, to_string(val_a + val_b_f));
                else if (op == IROperation::SUB)
                    retVal = ir->addImmValue(MetaDataType::DOUBLE, to_string(val_a - val_b_f));
            }
                break;
            case MetaDataType::DOUBLE: {
                double val_b_d = stod(op2->getValue());
                if(op == IROperation::ADD)
                    retVal = ir->addImmValue(MetaDataType::DOUBLE, to_string(val_a + val_b_d));
                else if (op == IROperation::SUB)
                    retVal = ir->addImmValue(MetaDataType::DOUBLE, to_string(val_a - val_b_d));
            }
                break;
            default:
                break;
        }
    }
    return retVal;
}

IRValue* IRFunction::immMul(IROperand* op1, IROperand* op2){
    MetaDataType type1 = op1->getMetaDataType();
    MetaDataType type2 = op2->getMetaDataType();
    IRValue* retVal = nullptr;
    if(type1 == MetaDataType::INT){
        int val_a = stoi(op1->getValue());
        int val_b = stoi(op2->getValue());
        retVal = new IRValue(MetaDataType::INT, to_string(val_a * val_b), {}, false);
    } else if (type1 == MetaDataType::FLOAT){
        float val_a = stof(op1->getValue());
        float val_b = stof(op2->getValue());
        retVal = ir->addImmValue(MetaDataType::FLOAT, to_string(val_a * val_b));
    } else if (type1 == MetaDataType::DOUBLE){
        double val_a = stod(op1->getValue());
        double val_b = stod(op2->getValue());
        retVal = ir->addImmValue(MetaDataType::DOUBLE, to_string(val_a * val_b));
    }
    return retVal;
}

IRValue* IRFunction::immDiv(IROperand* op1, IROperand* op2){
    MetaDataType type1 = op1->getMetaDataType();
    MetaDataType type2 = op2->getMetaDataType();
    IRValue* retVal = nullptr;
    if(type1 == MetaDataType::INT){
        int val_a = stoi(op1->getValue());
        int val_b = stoi(op2->getValue());
        retVal = new IRValue(MetaDataType::INT, to_string(val_a / val_b), {}, false);
    } else if (type1 == MetaDataType::FLOAT){
        float val_a = stof(op1->getValue());
        float val_b = stof(op2->getValue());
        retVal = ir->addImmValue(MetaDataType::FLOAT, to_string(val_a / val_b));
    } else if (type1 == MetaDataType::DOUBLE){
        double val_a = stod(op1->getValue());
        double val_b = stod(op2->getValue());
        retVal = ir->addImmValue(MetaDataType::DOUBLE, to_string(val_a / val_b));
    }
    return retVal;
}

IRValue* IRFunction::immCmp(IROperand* op1, IROperand* op2, IROperation op){
    MetaDataType type = op1->getMetaDataType();
    IRValue* retVal = nullptr;
    if (type == MetaDataType::INT) {
        int val_a = stoi(op1->getValue());
        int val_b = stoi(op2->getValue());
        switch(op){
            case IROperation::SLT:
                if(val_a < val_b)
                    retVal = new IRValue(MetaDataType::BOOL, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::BOOL, "0", {}, false);
                break;
            case IROperation::SGT:
                if(val_a > val_b)
                    retVal = new IRValue(MetaDataType::BOOL, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::BOOL, "0", {}, false);
                break;
            case IROperation::SLEQ:
                if(val_a <= val_b)
                    retVal = new IRValue(MetaDataType::BOOL, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::BOOL, "0", {}, false);
                break;
            case IROperation::SGEQ:
                if(val_a >= val_b)
                    retVal = new IRValue(MetaDataType::BOOL, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::BOOL, "0", {}, false);
                break;
            default:
                break;
        }
    } else if (type == MetaDataType::FLOAT) {
        float val_a = stof(op1->getValue());
        float val_b = stof(op2->getValue());
        switch(op){
            case IROperation::SLT:
                if(val_a < val_b)
                    retVal = new IRValue(MetaDataType::BOOL, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::BOOL, "0", {}, false);
                break;
            case IROperation::SGT:
                if(val_a > val_b)
                    retVal = new IRValue(MetaDataType::BOOL, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::BOOL, "0", {}, false);
                break;
            case IROperation::SLEQ:
                if(val_a <= val_b)
                    retVal = new IRValue(MetaDataType::BOOL, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::BOOL, "0", {}, false);
                break;
            case IROperation::SGEQ:
                if(val_a >= val_b)
                    retVal = new IRValue(MetaDataType::BOOL, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::BOOL, "0", {}, false);
                break;
            default:
                break;
        }
    } else if (type == MetaDataType::DOUBLE) {
        double val_a = stod(op1->getValue());
        double val_b = stod(op2->getValue());
        switch(op){
            case IROperation::SLT:
                if(val_a < val_b)
                    retVal = new IRValue(MetaDataType::BOOL, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::BOOL, "0", {}, false);
                break;
            case IROperation::SGT:
                if(val_a > val_b)
                    retVal = new IRValue(MetaDataType::BOOL, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::BOOL, "0", {}, false);
                break;
            case IROperation::SLEQ:
                if(val_a <= val_b)
                    retVal = new IRValue(MetaDataType::BOOL, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::BOOL, "0", {}, false);
                break;
            case IROperation::SGEQ:
                if(val_a >= val_b)
                    retVal = new IRValue(MetaDataType::BOOL, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::BOOL, "0", {}, false);
                break;
            default:
                break;
        }
    }
}

void IRFunction::substituteUseOp(IRCode* code, IROperand* dst_op, IROperand* cmp_op, IROperation op){
    IROperand* arg1 = code->getArg1();
    IROperand* arg2 = code->getArg2();

    if(IRCode::isTwoArgAssignmentOperation(op)){
        if(arg1 == cmp_op){
            code->setArg1(dst_op);
        } else if (arg2 == cmp_op){
            code->setArg2(dst_op);
        }
    } else if (op == IROperation::BEQZ || op == IROperation::NEG || op == IROperation::NOT || op == IROperation::ASSIGN || op == IROperation::ADD_PARAM || op == IROperation::RETURN) {
        if(arg1 == cmp_op)
            code->setArg1(dst_op);
    } else if (op == IROperation::FETCH_ARRAY_ELEM || op == IROperation::ASSIGN_ARRAY_ELEM) {
        if(arg2 == cmp_op)
            code->setArg2(dst_op);
    }
}

void IRFunction::constFolding() {
    for(int bnum = 0; bnum < basicBlocks.size(); bnum++) {
        auto block = basicBlocks[bnum]; 
        for(int i = 0; i < block.size(); i++){
            IRCode *code = block[i];
            IROperand* res = code->getResult();
            IROperand* arg1 = code->getArg1();
            IROperand* arg2 = code->getArg2();
            IROperation op = code->getOperation();

            if(!IRCode::isAssignmentOperation(op) || op == IROperation::PHI)
                continue;    
            else if (op == IROperation::ASSIGN){
                if(arg1->getOperandType() != OperandType::VALUE)
                    continue;
                // code->setResult(arg1);

                for(int j = i + 1; j < block.size(); j++){
                        IRCode* new_code = block[j];
                        IROperation new_op = new_code->getOperation();
                        // break at next def
                        if(new_op == IROperation::CALL)
                            continue;
                        if(new_op == IROperation::ASSIGN_ARRAY_ELEM && res == new_code->getArg1())
                            continue;
                        if(new_op == IROperation::REPLACE && res == new_code->getArg1())
                            break;
                        if(new_code->getResult()!=nullptr && new_code->getResult() == res){
                            break;
                        }
                        // substitute res to arg1 (immValue)
                        substituteUseOp(new_code, arg1, res, new_op);
                }
                // block.erase(block.begin() + i);
                // codes.erase(codes.begin() + entrances[bnum] + i);
                // for(int k = bnum + 1; k < basicBlocks.size(); k++)
                //     entrances[k]--;
                // delete code;
                // i--;
                continue;
            } else if (op == IROperation::NOT) {
                IRValue* new_value = nullptr;
                if(arg1->getValue() == "1")
                    new_value = new IRValue(MetaDataType::BOOL, "0", {}, false);
                else if(arg1->getValue() == "0")
                    new_value = new IRValue(MetaDataType::BOOL, "1", {}, false);

                if(new_value){
                    for(int j = i + 1; j < block.size(); j++){
                        IRCode* new_code = block[j];
                        IROperation new_op = new_code->getOperation();
                        // break at next def
                        if(new_op == IROperation::ASSIGN_ARRAY_ELEM && res == new_code->getArg1())
                            continue;
                        if(new_op == IROperation::REPLACE && res == new_code->getArg1())
                            break;
                        if(new_code->getResult() == res){
                            break;
                        }
                        // substitute res to new_value
                        substituteUseOp(new_code, new_value, res, new_op);
                    }
                }
                // block.erase(block.begin() + i);
                // codes.erase(codes.begin() + entrances[bnum] + i);
                // for(int k = bnum + 1; k < basicBlocks.size(); k++)
                //     entrances[k]--;
                // delete code;
                // i--;
                continue;
            } else if (op == IROperation::NEG) {
                IRValue* new_value = nullptr;
                switch(arg1->getMetaDataType()){
                    case MetaDataType::INT:{
                        int val = stoi(arg1->getValue());
                        new_value = new IRValue(MetaDataType::INT, std::to_string(0 - val), {}, false);
                        break;
                    }
                    case MetaDataType::FLOAT:{
                        float val = stof(arg1->getValue());
                        new_value = ir->addImmValue(MetaDataType::FLOAT, std::to_string(0 - val));
                        break;
                    }
                    case MetaDataType::DOUBLE:{
                        double val = stod(arg1->getValue());
                        new_value = ir->addImmValue(MetaDataType::DOUBLE, std::to_string(0 - val));
                        break;
                    }
                }

                if(new_value){
                    for(int j = i + 1; j < block.size(); j++){
                        IRCode* new_code = block[j];
                        IROperation new_op = new_code->getOperation();
                        // break at next def
                        if(new_op == IROperation::ASSIGN_ARRAY_ELEM && res == new_code->getArg1())
                            continue;
                        if(new_op == IROperation::REPLACE && res == new_code->getArg1())
                            break;
                        if(new_code->getResult() == res){
                            break;
                        }
                        // substitute res to new_value
                        substituteUseOp(new_code, new_value, res, new_op);
                    }
                }
                // block.erase(block.begin() + i);
                // codes.erase(codes.begin() + entrances[bnum] + i);
                // for(int k = bnum + 1; k < basicBlocks.size(); k++)
                //     entrances[k]--;
                // delete code;
                // i--;
                continue;
            }

            // arg1 and arg2 both exists
            if(arg1 && arg2 && arg1->getOperandType() == OperandType::VALUE && arg2->getOperandType() == OperandType::VALUE){
                // arg1 and arg2 are both immValues
                IRValue* new_value = nullptr;
                if(op == IROperation::ADD || op == IROperation::SUB){
                    new_value = immAddSub(arg1, arg2, op);
                } else if (op == IROperation::MUL) {
                    new_value = immMul(arg1, arg2);
                } else if (op == IROperation::DIV) {
                    new_value = immDiv(arg1, arg2);
                } else if (op == IROperation::MOD) {
                    int val_a = stoi(arg1->getValue());
                    int val_b = stoi(arg2->getValue());
                    new_value = new IRValue(MetaDataType::INT, to_string(val_a % val_b), {}, false);
                } else if (op == IROperation::OR) {
                    if(arg1->getValue() == "1" || arg2->getValue() == "1")
                        new_value = new IRValue(MetaDataType::BOOL, "1", {}, false);
                    else 
                        new_value = new IRValue(MetaDataType::BOOL, "0", {}, false);
                } else if (op == IROperation::AND) {
                    if(arg1->getValue() == "1" && arg2->getValue() == "1")
                        new_value = new IRValue(MetaDataType::BOOL, "1", {}, false);
                    else 
                        new_value = new IRValue(MetaDataType::BOOL, "0", {}, false);
                } else if (op == IROperation::SEQ) {
                    if(arg1->getValue() == arg2->getValue())
                        new_value = new IRValue(MetaDataType::BOOL, "1", {}, false);
                    else   
                        new_value = new IRValue(MetaDataType::BOOL, "0", {}, false);
                } else if (op == IROperation::SNE) {
                    if(arg1->getValue() != arg2->getValue())
                        new_value = new IRValue(MetaDataType::BOOL, "1", {}, false);
                    else   
                        new_value = new IRValue(MetaDataType::BOOL, "0", {}, false);
                } else {
                    new_value = immCmp(arg1, arg2, op);
                }

                if(new_value){
                    for(int j = i + 1; j < block.size(); j++){
                        IRCode* new_code = block[j];
                        IROperation new_op = new_code->getOperation();
                        // break at next def
                        if(new_op == IROperation::ASSIGN_ARRAY_ELEM && res == new_code->getArg1())
                            continue;
                        if(new_op == IROperation::REPLACE && res == new_code->getArg1())
                            break;
                        if(new_code->getResult() == res){
                            break;
                        }
                        // substitute
                        substituteUseOp(new_code, new_value, res, new_op);
                    }
                }

                switch(new_value->getMetaDataType()){
                    case MetaDataType::BOOL:
                        codes[entrances[bnum] + i] = new IRAssignB(res, new_value);
                        break;
                    case MetaDataType::INT:
                        codes[entrances[bnum] + i] = new IRAssignI(res, new_value);
                        break;
                    case MetaDataType::FLOAT:
                        codes[entrances[bnum] + i] = new IRAssignF(res, new_value);
                        break;
                    case MetaDataType::DOUBLE:
                        codes[entrances[bnum] + i] = new IRAssignD(res, new_value);
                        break;
                }
                // block.erase(block.begin() + i);
                // codes.erase(codes.begin() + entrances[bnum] + i);
                // for(int k = bnum + 1; k < basicBlocks.size(); k++)
                //     entrances[k]--;
                // delete code;
                // i--;

            } else if (arg1->getOperandType() == OperandType::VALUE || arg2->getOperandType() == OperandType::VALUE) {
                if(op != IROperation::ADD && op != IROperation::SUB && op != IROperation::MUL)
                    continue;

                IROperand* imm_arg = arg1->getOperandType() == OperandType::VALUE ? code->getArg1() : code->getArg2();
                IROperand* var_arg = arg1->getOperandType() == OperandType::VALUE ? code->getArg2() : code->getArg1();
                                
                for(int j = i + 1; j < block.size(); j++){
                    IRCode *new_code = block[j];
                    IROperation new_op = new_code->getOperation();
                    
                    if(!IRCode::isAssignmentOperation(new_op) || new_op == IROperation::PHI)
                        continue;
                    if(new_op == IROperation::NEG || new_op == IROperation::NOT || new_op == IROperation::ASSIGN)
                        continue;
                    
                    if(new_code->getArg1() == res && new_code->getArg2()->getOperandType() == OperandType::VALUE){
                    // new_code: arg1 is Var, arg2 is immVal
                        if(op == IROperation::ADD){
                            IRValue* new_value = immAddSub(imm_arg, new_code->getArg2(), new_op);
                            switch(var_arg->getMetaDataType()){
                                case MetaDataType::INT:
                                    codes[entrances[bnum] + j] = new IRAddI(new_code->getResult(), var_arg, new_value);
                                    break;
                                case MetaDataType::FLOAT:
                                    codes[entrances[bnum] + j] = new IRAddF(new_code->getResult(), var_arg, new_value);
                                    break;
                                case MetaDataType::DOUBLE:
                                    codes[entrances[bnum] + j] = new IRAddD(new_code->getResult(), var_arg, new_value);
                                    break;
                            }
                            
                        } else if (op == IROperation::SUB) {
                            if(arg2->getOperandType() == OperandType::VALUE){ // origin code: arg1 is var
                                IRValue* new_value = immAddSub(imm_arg, new_code->getArg2(), new_op == IROperation::ADD ? IROperation::SUB : IROperation::ADD);
                                switch(var_arg->getMetaDataType()){
                                case MetaDataType::INT:
                                    codes[entrances[bnum] + j] = new IRSubI(new_code->getResult(), var_arg, new_value);
                                    break;
                                case MetaDataType::FLOAT:
                                    codes[entrances[bnum] + j] = new IRSubF(new_code->getResult(), var_arg, new_value);
                                    break;
                                case MetaDataType::DOUBLE:
                                    codes[entrances[bnum] + j] = new IRSubD(new_code->getResult(), var_arg, new_value);
                                    break;
                                }
                            } else { // origin code: arg2 is var
                                IRValue* new_value = immAddSub(imm_arg, new_code->getArg2(), new_op);
                                switch(var_arg->getMetaDataType()){
                                case MetaDataType::INT:
                                    codes[entrances[bnum] + j] = new IRSubI(new_code->getResult(), new_value, var_arg);
                                    break;
                                case MetaDataType::FLOAT:
                                    codes[entrances[bnum] + j] = new IRSubF(new_code->getResult(), new_value, var_arg);
                                    break;
                                case MetaDataType::DOUBLE:
                                    codes[entrances[bnum] + j] = new IRSubD(new_code->getResult(), new_value, var_arg);
                                    break;
                                }                          
                            }
                        } else if (op == IROperation::MUL) {
                            if(new_op == IROperation::MUL) {
                                IRValue* new_value = immMul(imm_arg, new_code->getArg2());
                                new_code->setArg1(var_arg);
                                new_code->setArg2(new_value);
                            }
                        }
                    } else if (new_code->getArg1()->getOperandType() == OperandType::VALUE && new_code->getArg2() == res) {
                        // new_code: arg2 is Var, arg1 is immVal
                        if (op == IROperation::ADD) {
                            IRValue* new_value = immAddSub(new_code->getArg1(), imm_arg, new_op);
                            new_code->setArg1(new_value);
                            new_code->setArg2(var_arg);
                        } else if (op == IROperation::SUB) {
                            if(arg2->getOperandType() == OperandType::VALUE){ // origin code: arg1 is var
                                new_code->setArg2(var_arg);
                                IRValue* new_value = immAddSub(new_code->getArg1(), imm_arg, new_op == IROperation::ADD ? IROperation::SUB : IROperation::ADD);
                                new_code->setArg1(new_value);
                            } else { // origin code: arg2 is var
                                IRValue* new_value = immAddSub(new_code->getArg1(), imm_arg, new_op);
                                switch(var_arg->getMetaDataType()){
                                case MetaDataType::INT:
                                    if(new_op == IROperation::ADD)
                                        codes[entrances[bnum] + j] = new IRSubI(new_code->getResult(), new_value, var_arg);
                                    else
                                        codes[entrances[bnum] + j] = new IRAddI(new_code->getResult(), new_value, var_arg);
                                    break;
                                case MetaDataType::FLOAT:
                                    if(new_op == IROperation::ADD)
                                        codes[entrances[bnum] + j] = new IRSubF(new_code->getResult(), new_value, var_arg);
                                    else
                                        codes[entrances[bnum] + j] = new IRAddF(new_code->getResult(), new_value, var_arg);
                                    break;
                                case MetaDataType::DOUBLE:
                                    if(new_op == IROperation::ADD)
                                        codes[entrances[bnum] + j] = new IRSubD(new_code->getResult(), new_value, var_arg);
                                    else
                                        codes[entrances[bnum] + j] = new IRAddD(new_code->getResult(), new_value, var_arg);
                                    break;
                                } 
                            }
                        } else if (op == IROperation::MUL) {
                            if(new_op == IROperation::MUL) {
                                IRValue* new_value = immMul(imm_arg, new_code->getArg1());
                                new_code->setArg1(new_value);
                                new_code->setArg2(var_arg);                            
                            }
                        }
                    }
                }
            }
        }
    }
}

void IRFunction::delOperandInVec(vector<IROperand*>& vars, IROperand* op){
    auto it = find(vars.begin(), vars.end(), op);
    if(it != vars.end())
        vars.erase(it);
}

void IRFunction::addOperandToVec(vector<IROperand*>& vars, IROperand* op){
    auto it = find(vars.begin(), vars.end(), op);
    if(it == vars.end())
        vars.push_back(op);
}

void IRFunction::usedefVarsAnalysis() {
    for(int i = 0; i < basicBlocks.size(); i++) {
        auto block = basicBlocks[i];
        std::vector<IROperand*> use;
        std::vector<IROperand*> def;
        use.clear();
        def.clear();

        for(int j = block.size() - 1; j >= 0; j--){
            IRCode* code = block[j];
            IROperand* res = code->getResult();
            IROperand* arg1 = code->getArg1();
            IROperand* arg2 = code->getArg2();
            IROperation op = code->getOperation();

            if(op == IROperation::ADD_LABEL || op == IROperation::GOTO || op == IROperation::CALL)
                continue;
            else if(op == IROperation::RETURN || op == IROperation::ADD_PARAM || op == IROperation::BEQZ){
                if(arg1){
                    addOperandToVec(use, arg1);
                    delOperandInVec(def, arg1);
                }
            } else if (op == IROperation::GET_PARAM || op == IROperation::GET_RETURN) {
                if(res && (res->getOperandType() == OperandType::SYMBOLVAR || res->getOperandType() == OperandType::TEMPVAR)){
                    delOperandInVec(use, res);
                    addOperandToVec(def, res);
                }
            } else if (op == IROperation::REPLACE) {
                if(res){
                    delOperandInVec(use, res);
                    addOperandToVec(def, res);
                }
                if(arg1){
                    delOperandInVec(use, arg1);
                    addOperandToVec(def, arg1);
                }
            } else if (op == IROperation::ASSIGN_ARRAY_ELEM) {
                if(arg2 && arg2->getOperandType() != OperandType::VALUE){
                    addOperandToVec(use, arg2);
                    delOperandInVec(def, arg2);
                }
                if(res && res->getOperandType() != OperandType::VALUE){ // src operand
                    delOperandInVec(def, res);
                    addOperandToVec(use, res);
                }
            } else if (op == IROperation::PHI) {
                
            } else {
                if(res && (res->getOperandType() == OperandType::SYMBOLVAR || res->getOperandType() == OperandType::TEMPVAR)){
                    addOperandToVec(def, res);
                    delOperandInVec(use, res);
                }
                if(arg1 && (arg1->getOperandType() == OperandType::SYMBOLVAR || arg1->getOperandType() == OperandType::TEMPVAR)){
                    delOperandInVec(def, arg1);
                    addOperandToVec(use, arg1);
                }
                if(arg2 && (arg2->getOperandType() == OperandType::SYMBOLVAR || arg2->getOperandType() == OperandType::TEMPVAR)){
                    delOperandInVec(def, arg2);
                    addOperandToVec(use, arg2);
                }
            }
        }
        useVars.emplace_back(use.begin(), use.end());
        defVars.emplace_back(def.begin(), def.end());
    }
}


// vec1 is old, vec 2 is new
bool IRFunction::cmpTwoInVars(vector<IROperand*> & vec1, vector<IROperand*> & vec2){
    for(IROperand* var : vec2){
        auto it = find(vec1.begin(), vec1.end(), var);
        if(it == vec1.end()){ // var is not in vec1
            return true;
        }
        vec1.erase(it);
    }
    if(vec1.empty())
        return false;
    else return true;
} 

void IRFunction::liveVarAnalysis() {
    bool changed;
    usedefVarsAnalysis();

    do{
        changed = false;
        for(int i = basicBlocks.size() - 1; i >= 0; i--){ // i for block number
            bool ichanged = false;
            auto out = useVars[i];
            vector<IROperand*> newin;
            // update out vars
            vector<int> ctrlflow = controlFlow[i];
            for(int & back : ctrlflow){
                for(auto & var :inVars[back])
                    addOperandToVec(newin, var);
            }
            // add global variables to the last block's out vars 
            if(i == basicBlocks.size() - 1){
                auto outVar = outVars.back();
                auto glbVars = ir->getGlobalVariables();
                for(auto gblvar = glbVars.cbegin(); gblvar != glbVars.cend(); gblvar++) {
                    IRSymbolVariable* var = gblvar->second;
                    outVar.push_back(var);
                }           
            }
            // delete DEF variables
            for(auto & var : defVars[i])
                delOperandInVec(newin, var);
            // add USE variables
            for(auto & var : useVars[i])
                addOperandToVec(newin, var);
            
            ichanged = cmpTwoInVars(inVars[i], newin);
            if(ichanged){
                // update inVar
                inVars[i].clear();
                for(auto & var : newin)
                    inVars[i].push_back(var);  
            }  
            if(ichanged)
                changed = true;        
        }
    } while (changed);
}

void IRFunction::delDeadCode() {
    for(int i = basicBlocks.size() - 1; i >= 0; i--){
        auto block = basicBlocks[i];
        // set out vars to alive
        for(auto & var : outVars[i])
            var->setAlive(true);
        // delete dead codes
        for(int j = block.size() - 1; j >= 0; j--){
            IRCode* code = block[j];
            IROperand* res = code->getResult();
            IROperand* arg1 = code->getArg1();
            IROperand* arg2 = code->getArg2();
            IROperation op = code->getOperation();

            if(op == IROperation::ADD_LABEL || op == IROperation::GOTO || op == IROperation::CALL)
                continue;
            else if(op == IROperation::RETURN || op == IROperation::ADD_PARAM || op == IROperation::BEQZ){
                arg1->setAlive(true);
                continue;
            } else if (op == IROperation::GET_PARAM || op == IROperation::GET_RETURN) {
                if(res && (res->getOperandType() == OperandType::SYMBOLVAR || res->getOperandType() == OperandType::TEMPVAR))
                    if(res->getIsAlive() == false) {
                        block.erase(block.begin() + j);
                        codes.erase(codes.begin() + entrances[i] + j);
                        for(int k = i + 1; k < basicBlocks.size(); k++)
                            entrances[k]--;
                        delete code;
                        continue;
                    }
            } else if (op == IROperation::REPLACE) {
                if(res && res->getIsAlive() == false) {
                    block.erase(block.begin() + j);
                    codes.erase(codes.begin() + entrances[i] + j);
                    for(int k = i + 1; k < basicBlocks.size(); k++)
                        entrances[k]--;
                    delete code;
                    continue;
                }

                if(res)
                    res->setAlive(false);
                if(arg1)
                    arg1->setAlive(false);
            } else if (op == IROperation::ASSIGN_ARRAY_ELEM) {
                if(arg1 && arg1->getIsAlive() == false){ // a[t_0] = b, but a is not alive
                    block.erase(block.begin() + j);
                    codes.erase(codes.begin() + entrances[i] + j);
                    for(int k = i + 1; k < basicBlocks.size(); k++)
                        entrances[k]--;
                    delete code;
                    continue;
                }

                // if index is not immval, set it alive
                if(arg2 && arg2->getOperandType() != OperandType::VALUE){
                    arg2->setAlive(true);
                }
                // if src if not immval, set it alive
                if(res && res->getOperandType() != OperandType::VALUE){
                    res->setAlive(true);
                }
                continue;
            } else if (op == IROperation::PHI) {
                
            } else {
                if(res){
                    if(!res->getIsAlive()){ // dead code
                        block.erase(block.begin() + j);
                        codes.erase(codes.begin() + entrances[i] + j);
                        for(int k = i + 1; k < basicBlocks.size(); k++)
                            entrances[k]--;
                        delete code;
                        continue;
                    }
                }

                if(res && (res->getOperandType() == OperandType::SYMBOLVAR || res->getOperandType() == OperandType::TEMPVAR))
                    res->setAlive(false);
                if(arg1 && (arg1->getOperandType() == OperandType::SYMBOLVAR || arg1->getOperandType() == OperandType::TEMPVAR))
                    arg1->setAlive(true);
                if(arg2 && (arg2->getOperandType() == OperandType::SYMBOLVAR || arg2->getOperandType() == OperandType::TEMPVAR))
                    arg2->setAlive(true);
            }
        }
        // set inVars to be not alive
        for(auto & var : inVars[i])
            var->setAlive(false);
    }
}

void IRFunction::basicBlockDivision() {
    entrances.clear();
    entrances.push_back(0);
    for (int i = 0; i < codes.size(); i++) {
        if (codes[i]->getOperation() == IROperation::ADD_LABEL) {
            entrances.push_back(i);
        }
        if (codes[i]->getOperation() == IROperation::BEQZ || codes[i]->getOperation() == IROperation::GOTO) {
            entrances.push_back(i + 1);
        }
    }
    entrances.push_back(codes.size());
    for (int i = 0; i < entrances.size() - 1; i++) {
        basicBlocks.emplace_back(codes.begin() + entrances[i], codes.begin() + entrances[i + 1]);
    }
    entrances.pop_back();
    for (int i = 0; i < basicBlocks.size(); i++) {
        controlFlow.emplace_back(1, i + 1);
        for (auto & j : basicBlocks[i]) {
            if (j->getOperation() == IROperation::BEQZ || j->getOperation() == IROperation::GOTO) {
                for (int k = 0; k < entrances.size(); k++) {
                    if (codes[entrances[k]]->getOperation() != IROperation::ADD_LABEL) {
                        continue;
                    }
                    if (j->getOperation() == IROperation::BEQZ && codes[entrances[k]]->getArg1()->getSymbolName() == j->getArg2()->getSymbolName()) {
                        controlFlow.back().push_back(k);
                    }
                    else if (j->getOperation() == IROperation::GOTO && codes[entrances[k]]->getArg1()->getSymbolName() == j->getArg1()->getSymbolName()) {
                        controlFlow.back().push_back(k);
                    }
                }
            }
        }
    }
    cycleNum = vector<int>(entrances.size(), 0);
    for (int i = 0; i < controlFlow.size(); i++) {
        for (int j : controlFlow[i]) {
            if (j <= i) {
                for (int k = j; k <= i; k++) {
                    cycleNum[k]++;
                }
            }
        }
    }
}

void IRFunction::calVarActiveRegions() {
    unordered_map<IROperand *, vector<int>> definitions;
    unordered_map<IROperand *, vector<int>> uses;
    for (int i = 0; i < basicBlocks.size(); i++) {
        for (int j = 0; j < basicBlocks[i].size(); j++) {
            if (!IRCode::isAssignmentOperation(basicBlocks[i][j]->getOperation())) {
                continue;
            }
            IROperand *res = basicBlocks[i][j]->getResult();
            IROperand *arg1 = basicBlocks[i][j]->getArg1();
            IROperand *arg2 = basicBlocks[i][j]->getArg2();
            if (res->getIsArray()) {
                continue;
            }
            if (res->getOperandType() == OperandType::TEMPVAR && res->getAliasToSymbol()) {
                 res = res->getSymbolVariable();
            }
            if (arg1->getOperandType() == OperandType::TEMPVAR && arg1->getAliasToSymbol()) {
                arg1 = arg1->getSymbolVariable();
            }
            if (arg2 && arg2->getOperandType() == OperandType::TEMPVAR && arg2->getAliasToSymbol()) {
                arg2 = arg2->getSymbolVariable();
            }
            if (!res->getIsGlobalSymbolVar() && (res->getOperandType() == OperandType::SYMBOLVAR || res->getOperandType() == OperandType::TEMPVAR)) {
                if (definitions.find(res) != definitions.end()) {
                    definitions[res].push_back(entrances[i] + j);
                }
                else {
                    definitions[res] = vector<int>(1, entrances[i] + j);
                }
                for (int k : controlFlow[i]) {
                    if (k <= i) {
                        definitions[res].push_back(entrances[k]);
                    }
                }
            }
            if (!arg1->getIsGlobalSymbolVar() && (arg1->getOperandType() == OperandType::SYMBOLVAR || arg1->getOperandType() == OperandType::TEMPVAR)) {
                if (uses.find(arg1) != uses.end()) {
                    uses[arg1].push_back(entrances[i] + j);
                }
                else {
                    uses[arg1] = vector<int>(1, entrances[i] + j);
                }
            }
            if (!arg2) {
                continue;
            }
            if (!arg2->getIsGlobalSymbolVar() && (arg2->getOperandType() == OperandType::SYMBOLVAR || arg2->getOperandType() == OperandType::TEMPVAR)) {
                if (uses.find(arg2) != uses.end()) {
                    uses[arg2].push_back(entrances[i] + j);
                }
                else {
                    uses[arg2] = vector<int>(1, entrances[i] + j);
                }
            }
        }
    }
    for (int i = 0; i < basicBlocks.size(); i++) {
        for (int j = 0; j < basicBlocks[i].size(); j++) {
            if (IRCode::isAssignmentOperation(basicBlocks[i][j]->getOperation())) {
                continue;
            }
            IROperand *res = basicBlocks[i][j]->getResult();
            IROperand *arg1 = basicBlocks[i][j]->getArg1();
            IROperand *arg2 = basicBlocks[i][j]->getArg2();
            if (res) {
                if (res->getIsArray()) {
                    continue;
                }
                if (res->getOperandType() == OperandType::TEMPVAR && res->getAliasToSymbol()) {
                    res = res->getSymbolVariable();
                }
                if (!res->getIsGlobalSymbolVar() && (res->getOperandType() == OperandType::SYMBOLVAR || res->getOperandType() == OperandType::TEMPVAR)) {
                    if (definitions.find(res) != definitions.end()) {
                        definitions[res].push_back(entrances[i] + j);
                    }
                    else {
                        definitions[res] = vector<int>(1, entrances[i] + j);
                    }
                    for (int k : controlFlow[i]) {
                        if (k <= i) {
                            definitions[res].push_back(entrances[k]);
                        }
                    }
                }
            }
            if (arg1) {
                if (arg1->getOperandType() == OperandType::TEMPVAR && arg1->getAliasToSymbol()) {
                    arg1 = arg1->getSymbolVariable();
                }
                if (!arg1->getIsGlobalSymbolVar() && (arg1->getOperandType() == OperandType::SYMBOLVAR || arg1->getOperandType() == OperandType::TEMPVAR)) {
                    if (uses.find(arg1) != uses.end()) {
                        uses[arg1].push_back(entrances[i] + j);
                    }
                    else {
                        uses[arg1] = vector<int>(1, entrances[i] + j);
                    }
                }
            }
            if (arg2) {
                if (arg2->getOperandType() == OperandType::TEMPVAR && arg2->getAliasToSymbol()) {
                    arg2 = arg2->getSymbolVariable();
                }
                if (!arg2) {
                    continue;
                }
                if (!arg2->getIsGlobalSymbolVar() && (arg2->getOperandType() == OperandType::SYMBOLVAR || arg2->getOperandType() == OperandType::TEMPVAR)) {
                    if (uses.find(arg2) != uses.end()) {
                        uses[arg2].push_back(entrances[i] + j);
                    }
                    else {
                        uses[arg2] = vector<int>(1, entrances[i] + j);
                    }
                }
            }
        }
    }
    vector<int> activeRegions;
    for (const auto& it : uses) {
        activeRegions.clear();
        sort(definitions[it.first].begin(), definitions[it.first].end());
        for (auto ui : it.second) {
            int di = 0;
            for (di = 0; di < definitions[it.first].size(); di++) {
                if (definitions[it.first][di] > ui) {
                    break;
                }
            }
            if (di > 0) {
                for (int i = definitions[it.first][di - 1]; i <= ui; i++) {
                    activeRegions.push_back(i);
                }
            }
            else {
                for (int i = 0; i < ui; i++) {
                    activeRegions.push_back(i);
                }
            }
        }
        it.first->setActiveRegions(activeRegions);
    }
}

bool IRFunction::vectorOverlap(const vector<int>& a, const vector<int>& b) {
    if (a.empty() || b.empty()) {
        return true;
    }
    for (auto a_it : a) {
        for (auto b_it : b) {
            if (a_it == b_it) {
                return true;
            }
        }
    }
    return false;
}

unordered_map<IROperand *, vector<IROperand *>> IRFunction::calConflictVarRelations() {
    unordered_map<IROperand *, vector<IROperand *>> ret;
    if (localVariables.size() > 1) {
        for (auto it = localVariables.begin(); next(it) != localVariables.end(); it++) {
            if ((*it).second->getIsArray()) {
                continue;
            }
            ret[(*it).second] = vector<IROperand *>();
            for (auto in_it = next(it); in_it != localVariables.end(); in_it++) {
                if ((*in_it).second->getIsArray()) {
                    continue;
                }
                if (vectorOverlap((*it).second->getActiveRegions(), (*in_it).second->getActiveRegions())) {
                    ret[(*it).second].push_back((*in_it).second);
                }
            }
            for (auto & paramVariable : paramVariables) {
                if (paramVariable.second->getIsArray()) {
                    continue;
                }
                if (vectorOverlap((*it).second->getActiveRegions(), paramVariable.second->getActiveRegions())) {
                    ret[(*it).second].push_back(paramVariable.second);
                }
            }
            for (auto & tempVariable : tempVariables) {
                if (tempVariable.second->getIsArray() || tempVariable.second->getAliasToSymbol()) {
                    continue;
                }
                if (vectorOverlap((*it).second->getActiveRegions(), tempVariable.second->getActiveRegions())) {
                    ret[(*it).second].push_back(tempVariable.second);
                }
            }
        }
    }
    else if (localVariables.size() == 1) {
        auto it = localVariables.begin();
        for (auto & paramVariable : paramVariables) {
            if (paramVariable.second->getIsArray()) {
                continue;
            }
            if (vectorOverlap((*it).second->getActiveRegions(), paramVariable.second->getActiveRegions())) {
                ret[(*it).second].push_back(paramVariable.second);
            }
        }
        for (auto & tempVariable : tempVariables) {
            if (tempVariable.second->getIsArray() || tempVariable.second->getAliasToSymbol()) {
                continue;
            }
            if (vectorOverlap((*it).second->getActiveRegions(), tempVariable.second->getActiveRegions())) {
                ret[(*it).second].push_back(tempVariable.second);
            }
        }
    }
    if (paramVariables.size() > 1) {
        for (auto it = paramVariables.begin(); next(it) != paramVariables.end(); it++) {
            if ((*it).second->getIsArray()) {
                continue;
            }
            ret[(*it).second] = vector<IROperand *>();
            for (auto in_it = next(it); in_it != paramVariables.end(); in_it++) {
                if ((*in_it).second->getIsArray()) {
                    continue;
                }
                if (vectorOverlap((*it).second->getActiveRegions(), (*in_it).second->getActiveRegions())) {
                    ret[(*it).second].push_back((*in_it).second);
                }
            }
            for (auto & localVariable : localVariables) {
                if (localVariable.second->getIsArray()) {
                    continue;
                }
                if (vectorOverlap((*it).second->getActiveRegions(), localVariable.second->getActiveRegions())) {
                    ret[(*it).second].push_back(localVariable.second);
                }
            }
            for (auto & tempVariable : tempVariables) {
                if (tempVariable.second->getAliasToSymbol() || tempVariable.second->getIsArray()) {
                    continue;
                }
                if (vectorOverlap((*it).second->getActiveRegions(), tempVariable.second->getActiveRegions())) {
                    ret[(*it).second].push_back(tempVariable.second);
                }
            }
        }
    }
    else if (paramVariables.size() == 1) {
        auto it = paramVariables.begin();
        for (auto & localVariable : localVariables) {
            if (localVariable.second->getIsArray()) {
                continue;
            }
            if (vectorOverlap((*it).second->getActiveRegions(), localVariable.second->getActiveRegions())) {
                ret[(*it).second].push_back(localVariable.second);
            }
        }
        for (auto & tempVariable : tempVariables) {
            if (tempVariable.second->getAliasToSymbol() || tempVariable.second->getIsArray()) {
                continue;
            }
            if (vectorOverlap((*it).second->getActiveRegions(), tempVariable.second->getActiveRegions())) {
                ret[(*it).second].push_back(tempVariable.second);
            }
        }
    }
    if (tempVariables.size() > 1) {
        for (auto it = tempVariables.begin(); next(it) != tempVariables.end(); it++) {
            if ((*it).second->getIsArray() || (*it).second->getAliasToSymbol()) {
                continue;
            }
            ret[(*it).second] = vector<IROperand *>();
            for (auto in_it = next(it); in_it != tempVariables.end(); in_it++) {
                if ((*in_it).second->getIsArray() || (*in_it).second->getAliasToSymbol()) {
                    continue;
                }
                if (vectorOverlap((*it).second->getActiveRegions(), (*in_it).second->getActiveRegions())) {
                    ret[(*it).second].push_back((*in_it).second);
                }
            }
            for (auto & paramVariable : paramVariables) {
                if (paramVariable.second->getIsArray()) {
                    continue;
                }
                if (vectorOverlap((*it).second->getActiveRegions(), paramVariable.second->getActiveRegions())) {
                    ret[(*it).second].push_back(paramVariable.second);
                }
            }
            for (auto & localVariable : localVariables) {
                if (localVariable.second->getIsArray()) {
                    continue;
                }
                if (vectorOverlap((*it).second->getActiveRegions(), localVariable.second->getActiveRegions())) {
                    ret[(*it).second].push_back(localVariable.second);
                }
            }
        }
    }
    else if (tempVariables.size() == 1) {
        auto it = tempVariables.begin();
        if (!(*it).second->getAliasToSymbol() && !(*it).second->getIsArray()) {
            for (auto & paramVariable : paramVariables) {
                if (paramVariable.second->getIsArray()) {
                    continue;
                }
                if (vectorOverlap((*it).second->getActiveRegions(), paramVariable.second->getActiveRegions())) {
                    ret[(*it).second].push_back(paramVariable.second);
                }
            }
            for (auto & localVariable : localVariables) {
                if (localVariable.second->getIsArray()) {
                    continue;
                }
                if (vectorOverlap((*it).second->getActiveRegions(), localVariable.second->getActiveRegions())) {
                    ret[(*it).second].push_back(localVariable.second);
                }
            }
        }
    }
    return ret;
}

vector<vector<IROperand *>> IRFunction::calRegisterGraph(unordered_map<IROperand *, vector<IROperand *>> conflictVar) {
    vector<vector<IROperand *>> ret;
    vector<IROperand *> nodes;
    vector<IROperand *> sortedNodes;
    vector<int> degrees;
    for (auto i : conflictVar) {
        nodes.push_back(i.first);
        degrees.push_back(i.second.size());
    }
    for (auto i : Tools::sort_indexes(degrees)) {
        sortedNodes.push_back(nodes[i]);
    }
    for (int i = sortedNodes.size() - 1; i >= 0; i--) {
        if (sortedNodes[i]->getWasColored()) {
            continue;
        }
        sortedNodes[i]->setWasColored(true);
        ret.push_back(vector<IROperand *>(1, sortedNodes[i]));
        for (int j = i - 1; j >= 0; j--) {
            if (find(conflictVar[sortedNodes[i]].begin(), conflictVar[sortedNodes[i]].end(), sortedNodes[j]) == conflictVar[sortedNodes[i]].end()) {
                if (sortedNodes[j]->getWasColored()) {
                    continue;
                }
                sortedNodes[j]->setWasColored(true);
                ret.back().push_back(sortedNodes[j]);
            }
        }
    }
    return ret;
}

unordered_map<IROperand *, int> IRFunction::calVarCosts() {
    unordered_map<IROperand *, int> ret;
    for (int i = 0; i < basicBlocks.size(); i++) {
        for (auto j : basicBlocks[i]) {
            if (!IRCode::isAssignmentOperation(j->getOperation())) {
                continue;
            }
            IROperand *res = j->getResult();
            if (res->getIsArray()) {
                continue;
            }
            IROperand *arg1 = j->getArg1();
            IROperand *arg2 = j->getArg2();
            if (res->getOperandType() == OperandType::TEMPVAR && res->getAliasToSymbol()) {
                res = res->getSymbolVariable();
            }
            if ((res->getOperandType() == OperandType::SYMBOLVAR || res->getOperandType() == OperandType::TEMPVAR) && !res->getIsGlobalSymbolVar()) {
                if (ret.find(res) == ret.end()) {
                    ret[res] = cycleNum[i] * 10;
                }
                else {
                    ret[res] += cycleNum[i] * 10;
                }
            }
            if (arg1->getOperandType() == OperandType::TEMPVAR && arg1->getAliasToSymbol()) {
                arg1 = arg1->getSymbolVariable();
            }
            if ((arg1->getOperandType() == OperandType::SYMBOLVAR || arg1->getOperandType() == OperandType::TEMPVAR) && !arg1->getIsGlobalSymbolVar()) {
                if (ret.find(arg1) == ret.end()) {
                    ret[arg1] = cycleNum[i] * 10;
                }
                else {
                    ret[arg1] += cycleNum[i] * 10;
                }
            }
            if (arg2 && arg2->getOperandType() == OperandType::TEMPVAR && arg2->getAliasToSymbol()) {
                arg2 = arg2->getSymbolVariable();
            }
            if (arg2 && (arg2->getOperandType() == OperandType::SYMBOLVAR || arg2->getOperandType() == OperandType::TEMPVAR) && !arg2->getIsGlobalSymbolVar()) {
                if (ret.find(arg2) == ret.end()) {
                    ret[arg2] = cycleNum[i] * 10;
                }
                else {
                    ret[arg2] += cycleNum[i] * 10;
                }
            }
        }
    }
    return ret;
}

void IRFunction::varBindRegisters(TargetCodes *t) {
    calVarActiveRegions();
    unordered_map<IROperand *, vector<IROperand *>> conflictVar = calConflictVarRelations();
    vector<vector<IROperand *>> registerGraph = calRegisterGraph(conflictVar);
    unordered_map<IROperand *, int> varCosts = calVarCosts();
    vector<IROperand *> operands;
    vector<IROperand *> sortedOperands;
    vector<int> costs;
    for (auto it : varCosts) {
        operands.emplace_back(it.first);
        costs.emplace_back(it.second);
    }
    for (auto i : Tools::sort_indexes(costs)) {
        sortedOperands.push_back(operands[i]);
    }
    int numGenPurposeRegAlloc = 0;
    int maxGenPurposeRegAlloc = 26;
    int numFloatPointRegAlloc = 0;
    int maxFloatPointRegAlloc = 30;
    bool hasFreeRegister;
    for (int i = 0; i < sortedOperands.size(); i++) {
        if (sortedOperands[i]->getBindRegister()) {
            continue;
        }
        if (sortedOperands[i]->getMetaDataType() == MetaDataType::BOOL || sortedOperands[i]->getMetaDataType() == MetaDataType::INT) {
            if (numGenPurposeRegAlloc >= maxGenPurposeRegAlloc) {
                if (numFloatPointRegAlloc < maxFloatPointRegAlloc) {
                    continue;
                }
                else {
                    break;
                }
            }
            sortedOperands[i]->setBindRegister(true);
            Register *toBindReg = t->getNextAvailableRegister(true, false, FloatPointType::NONE, hasFreeRegister);
            sortedOperands[i]->setTargetBindRegister(toBindReg);
            toBindReg->setTmpStoreOffset(sortedOperands[i]->getMemOffset());
            functionTable->insertBindRegisters(toBindReg);
            vector<IROperand *> historySymbol;
            bool conflict = false;
            for (auto it : registerGraph) {
                if (find(it.begin(), it.end(), sortedOperands[i]) != it.end()) {
                    for (auto in_it : it) {
                        in_it->setBindRegister(true);
                        in_it->setTargetBindRegister(toBindReg);
                    }
                }
            }
            if (sortedOperands[i]->getOperandType() == OperandType::SYMBOLVAR) {
                for (auto it : sortedOperands[i]->getHistorySymbols()) {
                    if (it == sortedOperands[i]) {
                        continue;
                    }
                    else {
                        it->setBindRegister(true);
                        it->setTargetBindRegister(toBindReg);
                    }
                }
            }
            numGenPurposeRegAlloc++;
        }
        else {
            if (numFloatPointRegAlloc >= maxFloatPointRegAlloc) {
                if (numGenPurposeRegAlloc < maxGenPurposeRegAlloc) {
                    continue;
                }
                else {
                    break;
                }
            }
            sortedOperands[i]->setBindRegister(true);
            Register *toBindReg = t->getNextAvailableRegister(false, false, FloatPointType::NONE, hasFreeRegister);
            sortedOperands[i]->setTargetBindRegister(toBindReg);
            toBindReg->setTmpStoreOffset(sortedOperands[i]->getMemOffset());
            functionTable->insertBindRegisters(toBindReg);
            for (auto it : registerGraph) {
                if (find(it.begin(), it.end(), sortedOperands[i]) != it.end()) {
                    for (auto in_it : it) {
                        in_it->setBindRegister(true);
                        in_it->setTargetBindRegister(toBindReg);
                    }
                }
            }
            if (sortedOperands[i]->getOperandType() == OperandType::SYMBOLVAR) {
                for (auto it : sortedOperands[i]->getHistorySymbols()) {
                    if (it == sortedOperands[i]) {
                        continue;
                    }
                    else {
                        it->setBindRegister(true);
                        it->setTargetBindRegister(toBindReg);
                    }
                }
            }
            numFloatPointRegAlloc++;
        }
    }
}



void IRFunction::optimize(TargetCodes *t, int inOptimizeLevel) {
    switch (inOptimizeLevel) {
        case 1:
            basicBlockDivision();
            constFolding();
            break;
        case 2:
            basicBlockDivision();
            constFolding();
            liveVarAnalysis();
            break;
        case 3:
            basicBlockDivision();
            // liveVarAnalysis();
            varBindRegisters(t);
            break;
    }
}


IRTempVariable* IRFunction::addTempVariable(MetaDataType newMetaDataType) {
    string newTempVariableName = string("t_") + to_string(tempCount++);
    auto *newIRTempVar = new IRTempVariable(newTempVariableName, newMetaDataType);
    tempVariables.emplace(newTempVariableName, newIRTempVar);
    return newIRTempVar;
}

IRTempVariable* IRFunction::addTempVariable(IROperand *parentSymbolVariable) {
    string newTempVariableName = string("t_") + to_string(tempCount++);
    auto *newIRTempVar = new IRTempVariable(newTempVariableName, parentSymbolVariable->getMetaDataType(), parentSymbolVariable);
    tempVariables.emplace(newTempVariableName, newIRTempVar);
    return newIRTempVar;
}

IRSymbolVariable* IRFunction::addSymbolVariable(int block, AbstractSymbol *newSymbol, IRValue *initVal) {
    auto *newSymVar = new IRSymbolVariable(newSymbol, initVal, false);
    addLocalVariable(block,newSymVar);
    return newSymVar;
}

bool IRFunction::addCode(IRCode *newCode) {
    codes.emplace_back(newCode);
}

bool IRFunction::addCodes(const vector<IRCode *>& newCodes){
    for (auto code : newCodes){
        codes.emplace_back(code);
    }
}


IRLabel* IRFunction::addLabel() {
    string newLabelName = string("L_") + to_string(labelCount++) + string("_") + functionName;
    auto *newLabel = new IRLabel(newLabelName);
    labels.emplace(newLabelName, newLabel);
    return newLabel;
}

int IRFunction::calFrameSize() {
    frameSize = 8;
    int varSize = 0;
    for (const auto& it : paramVariables) {
        varSize = AbstractSymbol::getOffsetFromDataType(it.second->getMetaDataType());
        it.second->setMemOffset(frameSize + varSize);
        frameSize += varSize;
    }
    for (const auto& it : localVariables) {
        varSize = AbstractSymbol::getOffsetFromDataType(it.second->getMetaDataType());
        if (it.second->getIsArray()) {
            varSize *= it.second->getArraySize();
        }
        it.second->setMemOffset(frameSize + varSize);
        frameSize += varSize;
    }
    for (const auto& it : tempVariables) {
        if (!it.second->getAliasToSymbol()) {
            varSize = AbstractSymbol::getOffsetFromDataType(it.second->getMetaDataType());
            if (it.second->getIsArray()) {
                varSize *= it.second->getArraySize();
            }
            it.second->setMemOffset(frameSize + varSize);
            frameSize += varSize;
        }
        else if (!it.second->getSymbolVariable()->getIsGlobalSymbolVar()){
            it.second->setMemOffset(it.second->getSymbolVariable()->getMemOffset());
        }
    }
    if (frameSize % 8) {
        frameSize += (frameSize % 8);
    }
    functionTable->setFrameSize(frameSize);
}

string IRFunction::getFunctionName() const {
    return functionName;
}

bool IRFunction::getFunctionInLib() const {
    if (functionName == "get_int" ||
        functionName == "get_float" ||
        functionName == "get_double" ||
        functionName == "print_bool" ||
        functionName == "print_int" ||
        functionName == "print_float" ||
        functionName == "print_double") {
        return true;
    }
    else {
        return false;
    }
}

IRSymbolVariable *IRFunction::getLocalVariable(int block, const string& varName){
    for(int i = block; i >= 0; i--){
        if(localVariables.find(varName + to_string(i)) != localVariables.end())
            return localVariables[varName+ to_string(i)];
    }
    return nullptr;
}

IRSymbolVariable *IRFunction::getParamVariable(const string& varName){
    auto iter = paramVariables.find(varName);
    if(iter != paramVariables.end())
        return iter->second;
    return nullptr;
}

IRTempVariable *IRFunction::getTempVariable(const string& varName){
    return tempVariables.at(varName);
}

IRCode *IRFunction::getCode(int cnt){
    return codes[cnt];
}

vector<IRCode *> &IRFunction::getCodes(){
    return codes;
}

IRLabel *IRFunction::getLabel(const string& labelName){
    return labels.at(labelName);
}

int IRFunction::getFrameSize() const {
    return frameSize;
}

vector<Register *> IRFunction::getBindRegisters() const {
    return functionTable->getBindRegisters();
}

void IRFunction::print(SymbolTable *globalSymbolTable) const {
    auto functionTable = globalSymbolTable->lookUpFuncSymbolTable(functionName);
    cout << "----------- funcDef -----------" << endl;
    cout << functionTable->getFuncName() << "(";
    auto paramTypeList = functionTable->getParamDataTypeList();
    if (!paramTypeList.empty()) {
        for (auto param : vector<tuple<MetaDataType, bool, size_t>>(paramTypeList.begin(), paramTypeList.end() - 1)) {
            cout << static_cast<int>(get<0>(param));
            if (get<1>(param)) {
                cout << "[" << get<2>(param) << "]";
            }
            cout << ",";
        }
        auto param = paramTypeList.back();
        cout << static_cast<int>(get<0>(param));
        if (get<1>(param)) {
            cout << "[" << get<2>(param) << "]";
        }
    }
    cout << ") => " << static_cast<int>(functionTable->getReturnType()) << ":\n";
    cout << "----------- paramVars -----------" << endl;
    for (auto &symbolVar : paramVariables) {
        symbolVar.second->print();
    }
    cout << "----------- localVars -----------" << endl;
    for (auto &symbolVar : localVariables) {
        symbolVar.second->print();
    }
    cout << "----------- tempVars ------------" << endl;
    for (auto &symbolVar : tempVariables) {
        symbolVar.second->print();
    }
    cout << "----------- Codes ------------" << endl;
    cout << functionName << ":" << endl;
    for (auto &code : codes) {
        code->print();
    }
    cout << endl;
}

void IRFunction::targetCodeGen(TargetCodes *t) {
    t->addCodeDirectives(".text");
    t->addCodeDirectives(".align 1");
    t->addCodeDirectives(".globl\t" + functionName);
    t->addCodeDirectives(".type\t" + functionName + ", @function");
    t->addCodeLabel(functionName);
    bool hasFreeRegister;
    Register *ra = t->tryGetCertainRegister(true, "ra", hasFreeRegister);
    Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
    t->addCodeSd(sp, ra, -8);
    t->setRegisterFree(ra);
    for (auto it : getBindRegisters()) {
        if (it->getRegisterType() == RegisterType::GENERAL_PURPOSE && it->getAliasName()[0] == 's') {
            t->addCodeSw(sp, it, -it->getTmpStoreOffset());
        }
        else if (it->getRegisterType() == RegisterType::FLOAT_POINT && it->getAliasName()[0] == 'fs') {
            if (it->getFloatPointType() == FloatPointType::SINGLE) {
                t->addCodeSw(sp, it, -it->getTmpStoreOffset());
            }
            else {
                t->addCodeSd(sp, it, -it->getTmpStoreOffset());
            }
        }
    }
    t->setRegisterFree(sp);
    for (auto &code : codes) {
        code->genTargetCode(t);
    }
    if (codes.back()->getOperation() != IROperation::RETURN) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        Register *ra = t->tryGetCertainRegister(true, "ra", hasFreeRegister);
        for (auto it : getBindRegisters()) {
            if (it->getRegisterType() == RegisterType::GENERAL_PURPOSE && it->getAliasName()[0] == 's') {
                t->addCodeLw(it, sp, -it->getTmpStoreOffset());
            }
            else if (it->getRegisterType() == RegisterType::FLOAT_POINT && it->getAliasName()[0] == 'fs') {
                if (it->getFloatPointType() == FloatPointType::SINGLE) {
                    t->addCodeLw(it, sp, -it->getTmpStoreOffset());
                }
                else {
                    t->addCodeLd(it, sp, -it->getTmpStoreOffset());
                }
            }
        }
        t->addCodeLd(ra, sp, -8);
        t->addCodeRet();
        t->setRegisterFree(sp);
    }
}

IRProgram::IRProgram() {}

IRProgram *IRProgram::getIRProgram(string newProgramName, SymbolTable *newGlobalSymbolTable) {
    // singleton
    static IRProgram instance;
    static bool initialized = false;
    if (!initialized) {
        instance.initializeFileds(newProgramName, newGlobalSymbolTable);
        initialized = true;
    }
    return &instance;
}

void IRProgram::initializeFileds(string newProgramName, SymbolTable *newGlobalSymbolTable) {
    programName = move(newProgramName);
    globalSymbolTable = newGlobalSymbolTable;
    globalVariables.clear();
    functions.clear();
    funcSymbols.clear();
    immValues.clear();
    valueCount = 0;
}

IRSymbolVariable* IRProgram::addGlobalVariable(AbstractSymbol* symbol, IRValue *newValue) {
    string valueKey = {};
    for (const auto &val : newValue->getValues()) {
        valueKey += (val + ",");
    }
    immValues.erase(valueKey);
    newValue = new IRValue(newValue->getMetaDataType(), newValue->getValues(), symbol->getSymbolName(), false);
    auto glbSymVar = new IRSymbolVariable(symbol, newValue, true);
    globalVariables.emplace(glbSymVar->getSymbolName(), glbSymVar);
    return glbSymVar;
}

bool IRProgram::addFunction(IRFunction *newFunction) {
    functions.emplace(newFunction->getFunctionName(), newFunction);
}

bool IRProgram::addSymbolFunction(IRSymbolFunction *funcSymbol) {
    funcSymbols.emplace(funcSymbol->getFunctionName(), funcSymbol);
}

IRValue *IRProgram::addImmValue(MetaDataType inMetaDataType, const string &inValue) {
    if (immValues.find(inValue) != immValues.end()) {
        return immValues[inValue];
    }
    auto *newValue = new IRValue(inMetaDataType, inValue, "ImmValue_" + to_string(valueCount++), false);
    immValues[inValue] = newValue;
    return newValue;
}

IRValue *IRProgram::addImmValue(const string &inLabel, MetaDataType inMetaDataType, const string &inValue) {
    if (immValues.find(inValue) != immValues.end()) {
        return immValues[inValue];
    }
    auto *newValue = new IRValue(inMetaDataType, inValue, inLabel, false);
    immValues[inValue] = newValue;
    return newValue;
}

IRValue *IRProgram::addMulSameImmValue(MetaDataType inMetaDataType, const string &inValue, int num) {
    string valueKey = {};
    vector<string> values;
    for (int i = 0; i < num; i++) {
        valueKey += (inValue + ",");
        values.push_back(inValue);
    }
    if (immValues.find(valueKey) != immValues.end()) {
        return immValues[valueKey];
    }
    auto *newValue = new IRValue(inMetaDataType, values, "ImmValue_" + to_string(valueCount++), true);
    immValues[valueKey] = newValue;
    return newValue;
}

IRValue *IRProgram::addMulImmValue(MetaDataType inMetaDataType, vector<string> &inValues) {
    string valueKey = {};
    for (auto &value : inValues) {
        valueKey += (value + ",");
    }
    if (immValues.find(valueKey) != immValues.end()) {
        return immValues[valueKey];
    }
    auto *newValue = new IRValue(inMetaDataType, inValues, "ImmValue_" + to_string(valueCount++), true);
    immValues[valueKey] = newValue;
    return newValue;
}

IRSymbolVariable *IRProgram::getGlobalVariable(const string& varName){
    auto iter = globalVariables.find(varName);
    if(iter != globalVariables.end())
        return iter->second;
    return nullptr;
}

IRFunction *IRProgram::getFunction(const string& functionName){
    return functions.at(functionName);
}

IRSymbolFunction *IRProgram::getSymbolFunction(const string& functionName){
    return funcSymbols.at(functionName);
}

IRValue *IRProgram::getImmValue(const string &inImmValue) {
    return immValues.at(inImmValue);
    return nullptr;
}

IRValue *IRProgram::getImmValue(const vector<string>& inImmValues) {
    string valueKey = {};
    for (auto &value : inImmValues) {
        valueKey += value;
    }
    return immValues.at(valueKey);
}

void IRProgram::print() {
    cout << "============ global var ================" << endl;
    for (auto &symbol : globalVariables) {
        symbol.second->print();
    }
    cout << "============ imm value ================" << endl;
    for (auto &imm : immValues) {
        imm.second->print();
    }
    cout << "============ functions ================" << endl;
    for (const auto& func : functions) {
        if (!func.second->getFunctionInLib()) {
            func.second->print(globalSymbolTable);
        }
    }
}

void IRProgram::write(const string &path) {
    ofstream out;
    out.open(path, ios_base::out);
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    print();
    cout.rdbuf(coutbuf);
}

void IRProgram::targetGen(TargetCodes *t, int inOptimizeLevel) {
    for (auto &globalVar : globalVariables) {
        t->addCodeDirectives(".data");
        t->addCodeDirectives(".globl\t" + globalVar.first);
        t->addCodeDirectives(".type\t" + globalVar.first + ", @object");
        globalVar.second->genTargetGlobalValue(t);
    }
    for (auto &imm : immValues) {
        imm.second->genTargetValue(t);
    }
    for (const auto& func : functions) {
        if (!func.second->getFunctionInLib()) {
            func.second->calFrameSize();
            func.second->optimize(t, inOptimizeLevel);
            func.second->targetCodeGen(t);
            t->setAllRegistersFree();
            t->setAllRegistersAvailable();
        }
    }
}

void IRProgram::targetCodePrint(TargetCodes *t) {
    t->printCode();
}

void IRProgram::targetCodeWrite(TargetCodes *t, string path) {
    t->codeWrite(path);
}
