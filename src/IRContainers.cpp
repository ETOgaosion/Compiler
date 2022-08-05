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
                    retVal = new IRValue(MetaDataType::INT, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::INT, "0", {}, false);
                break;
            case IROperation::SGT:
                if(val_a > val_b)
                    retVal = new IRValue(MetaDataType::INT, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::INT, "0", {}, false);
                break;
            case IROperation::SLEQ:
                if(val_a <= val_b)
                    retVal = new IRValue(MetaDataType::INT, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::INT, "0", {}, false);
                break;
            case IROperation::SGEQ:
                if(val_a >= val_b)
                    retVal = new IRValue(MetaDataType::INT, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::INT, "0", {}, false);
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
                    retVal = new IRValue(MetaDataType::INT, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::INT, "0", {}, false);
                break;
            case IROperation::SGT:
                if(val_a > val_b)
                    retVal = new IRValue(MetaDataType::INT, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::INT, "0", {}, false);
                break;
            case IROperation::SLEQ:
                if(val_a <= val_b)
                    retVal = new IRValue(MetaDataType::INT, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::INT, "0", {}, false);
                break;
            case IROperation::SGEQ:
                if(val_a >= val_b)
                    retVal = new IRValue(MetaDataType::INT, "1", {}, false);
                else
                    retVal = new IRValue(MetaDataType::INT, "0", {}, false);
                break;
            default:
                break;
        }
    }
    return retVal;
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

void IRFunction::def_use_list(){
    for (int i = 0; i < codes.size(); i++) {
            IRCode *code = codes[i];
            code->use.clear();
            IROperand *res = code->getResult();
            for (int j = i + 1; j < codes.size(); j++)
                if(codes[j]->getArg1() == res || codes[j]->getArg2() == res)
                    code->use.push_back(codes[j]);
    }
}

int IRFunction::Replacewith(IRCode* I, IROperand* val){
    //int count = 0;
    if (I->use.empty())
    {
        ;
    }
    else
    {
        IROperand *res = I->getResult();
        for (int i = 0; i < I->use.size(); i++)
        {
            IRCode* UI = I->use[i];
            if(UI->getOperation() == IROperation::CALL)
                continue;
            if(UI->getOperation() == IROperation::ASSIGN_ARRAY_ELEM && res == UI->getArg1())
                continue;
            if(UI->getOperation() == IROperation::REPLACE){
                //count++;
                continue;
            }

            if(UI->getArg1() == res)
                UI->setArg1(val);
            if(UI->getArg2() == res)
                UI->setArg2(val);
        }
    }
    return 0;
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

            if(op != IROperation::BEQZ && (!IRCode::isAssignmentOperation(op) || op == IROperation::PHI))
                continue;    
            else if (op == IROperation::ASSIGN){
                if(arg1->getOperandType() != OperandType::VALUE)
                    continue;

                /*for(int j = i + 1; j < block.size(); j++){
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
                }*/
                Replacewith(code, arg1);
                block.erase(block.begin() + i);
                basicBlocks[bnum].erase(basicBlocks[bnum].begin() + i);
                codes.erase(codes.begin() + entrances[bnum] + i);
                for(int k = bnum + 1; k < basicBlocks.size(); k++)
                    entrances[k]--;
                // delete code;
                i--;

                continue;
            } else if (op == IROperation::NOT) {
                if(arg1->getOperandType() != OperandType::VALUE)
                    continue;
                IRValue* new_value = nullptr;
                if(arg1->getValue() == "1")
                    new_value = new IRValue(MetaDataType::INT, "0", {}, false);
                else if(arg1->getValue() == "0")
                    new_value = new IRValue(MetaDataType::INT, "1", {}, false);

                /*if(new_value){
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
                }*/
                if(new_value){
                    Replacewith(code, new_value);
                    block.erase(block.begin() + i);
                    basicBlocks[bnum].erase(basicBlocks[bnum].begin() + i);
                    codes.erase(codes.begin() + entrances[bnum] + i);
                    for(int k = bnum + 1; k < basicBlocks.size(); k++)
                        entrances[k]--;
                    // delete code;
                    i--;
                }

                continue;
            } else if (op == IROperation::NEG) {
                if(arg1->getOperandType() != OperandType::VALUE)
                    continue;
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
                }

                /*if(new_value){
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
                }*/
                if(new_value){
                    Replacewith(code, new_value);
                    block.erase(block.begin() + i);
                    basicBlocks[bnum].erase(basicBlocks[bnum].begin() + i);
                    codes.erase(codes.begin() + entrances[bnum] + i);
                    for(int k = bnum + 1; k < basicBlocks.size(); k++)
                        entrances[k]--;
                    // delete code;
                    i--;
                }

                continue;
            } else if (op == IROperation::BEQZ) {
                if(arg1->getOperandType() != OperandType::VALUE)
                    continue;
                int beqzArg = stoi(arg1->getValue());
                if (beqzArg == 0) {
                    code = new IRGoto(arg2);
                    block[i] = code;
                    basicBlocks[bnum][i] = code;
                    codes[entrances[bnum] + i] = code;
                    controlFlow[i].erase(controlFlow[i].begin());
                }
                else {
                    block.erase(block.begin() + i);
                    basicBlocks[bnum].erase(basicBlocks[bnum].begin() + i);
                    codes.erase(codes.begin() + entrances[bnum] + i);
                    for(int k = bnum + 1; k < basicBlocks.size(); k++)
                        entrances[k]--;
                    controlFlow[i].erase(controlFlow[i].begin() + 1);
                    delete code;
                }
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
                        new_value = new IRValue(MetaDataType::INT, "1", {}, false);
                    else 
                        new_value = new IRValue(MetaDataType::INT, "0", {}, false);
                } else if (op == IROperation::AND) {
                    if(arg1->getValue() == "1" && arg2->getValue() == "1")
                        new_value = new IRValue(MetaDataType::INT, "1", {}, false);
                    else 
                        new_value = new IRValue(MetaDataType::INT, "0", {}, false);
                } else if (op == IROperation::SEQ) {
                    if(arg1->getValue() == arg2->getValue())
                        new_value = new IRValue(MetaDataType::INT, "1", {}, false);
                    else   
                        new_value = new IRValue(MetaDataType::INT, "0", {}, false);
                } else if (op == IROperation::SNE) {
                    if(arg1->getValue() != arg2->getValue())
                        new_value = new IRValue(MetaDataType::INT, "1", {}, false);
                    else   
                        new_value = new IRValue(MetaDataType::INT, "0", {}, false);
                } else {
                    new_value = immCmp(arg1, arg2, op);
                }

                if(new_value){
                    /*for(int j = i + 1; j < block.size(); j++){
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

                    switch(new_value->getMetaDataType()){
                        case MetaDataType::INT:
                            codes[entrances[bnum] + i] = new IRAssignI(res, new_value);
                            break;
                        case MetaDataType::FLOAT:
                            codes[entrances[bnum] + i] = new IRAssignF(res, new_value);
                            break;
                    }*/
                    
                    Replacewith(code, new_value);
                    block.erase(block.begin() + i);
                    basicBlocks[bnum].erase(basicBlocks[bnum].begin() + i);
                    codes.erase(codes.begin() + entrances[bnum] + i);
                    for(int k = bnum + 1; k < basicBlocks.size(); k++)
                        entrances[k]--;
                    // delete code;
                    i--;
                
                }

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

void IRFunction::CSE(){
    def_use_list();
    for(int i = 0;i < basicBlocks.size();i ++){
        for(int j = 0;j < basicBlocks[i].size();j ++){
            if(basicBlocks[i][j]->getResult()){
                basicBlocks[i][j]->getResult()->which_bb = i;
            }
        }
    }

    dom.clear();
    dom.emplace_back(1, 0);

    std::vector<int> all;
    all.clear();
    for (int i = 0; i < basicBlocks.size(); i++)
        all.push_back(i);
    
    for (int i = 1; i < basicBlocks.size(); i++)
        dom.push_back(all);

    bool change = true;
    while(change){
        change = false;
        for (int i = 1; i < basicBlocks.size(); i++)
        {
            if (Pred[i].size() == 1)
            {
                dom[i].clear();
                std::vector<int> tmp = vector<int>(1, i);
                std::vector<int> res;
                set_union(dom[Pred[i][0]].begin(), dom[Pred[i][0]].end(), tmp.begin(), tmp.end(), back_inserter(res));
                sort(res.begin(), res.end());
                sort(dom[i].begin(), dom[i].end());
                if(res != dom[i]){
                    dom[i].assign(res.begin(), res.end());
                    change = true;
                }
            }
            else if (Pred[i].size() > 1)
            {
                std::vector<int> tmp = dom[Pred[i][0]];
                std::vector<int> res;
                for (int j = 1; j < Pred[i].size(); j++)
                {
                    res.clear();
                    set_intersection(tmp.begin(), tmp.end(), dom[Pred[i][j]].begin(), dom[Pred[i][j]].end(), back_inserter(res));
                    tmp.assign(res.begin(), res.end());
                }

                std::vector<int> tmp2 = vector<int>(1, i);
                res.clear();
                set_union(tmp.begin(), tmp.end(), tmp2.begin(), tmp2.end(), back_inserter(res));
                sort(res.begin(), res.end());
                sort(dom[i].begin(), dom[i].end());
                if(res != dom[i]){
                    dom[i].assign(res.begin(), res.end());
                    change = true;
                }

            }
        }
    }

    std::vector<IRCode *> record;
    record.clear();
    for (int i = 0; i < codes.size(); i++)
    {
        IRCode *I = codes[i];
        IRCode *toRep = nullptr;
        int match = 0;
        IROperand* op1 = I->getArg1();
        IROperand* op2 = I->getArg2();
        IROperand *re = I->getResult();
        IROperation op = I->getOperation();
        if (record.empty())
            ;
        else
            for (int j = 0; j < record.size(); j++)
            {
                IROperand* ar1 = record[j]->getArg1();
                IROperand* ar2 = record[j]->getArg2();
                IROperand* res = record[j]->getResult();
                IROperation opr = record[j]->getOperation();
                auto pos = std::find(dom[re->which_bb].begin(), dom[re->which_bb].end(), res->which_bb);
                if(pos == dom[re->which_bb].end())
                    continue;
                if (op == opr && IRCode::isTwoArgAssignmentOperation(op))
                    if(op1 == ar1 && op2 == ar2)
                        match = 1;
                    else if(IRCode::isOrderIndependentOperation(op) && op1 == ar2 && op2 == ar1)
                        match = 1;
                if(match){
                    toRep = record[j];
                    break;
                }
            }
        
        if(match){
            Replacewith(I, toRep->getResult());
            int bnum;
            for (bnum = 0; bnum < basicBlocks.size(); bnum++)
                if(entrances[bnum]> i){
                    bnum--;
                    break;
                }
            auto block = basicBlocks[bnum];
            block.erase(block.begin() + i - entrances[bnum]);
            codes.erase(codes.begin() + i);
            for(int k = bnum + 1; k < basicBlocks.size(); k++)
                entrances[k]--;
        }else if(IRCode::isTwoArgAssignmentOperation(op)){
            record.push_back(I);
        }
    }
}

void IRFunction::delOperandInVec(vector<IROperand*>& vars, IROperand* op){
    if(!op)
        return;
    auto it = find(vars.begin(), vars.end(), op);
    if(it != vars.end())
        vars.erase(it);
}

void IRFunction::addOperandToVec(vector<IROperand*>& vars, IROperand* op){
    if(!op)
        return;
    auto it = find(vars.begin(), vars.end(), op);
    if(it == vars.end())
        vars.push_back(op);
}

void IRFunction::useDefVarsAnalysis() {
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
                if(res && (res->getOperandType() == OperandType::SYMBOLVAR || res->getOperandType() == OperandType::TEMPVAR) && !res->getIsGlobalSymbolVar()){
                    delOperandInVec(use, res);
                    addOperandToVec(def, res);
                }
            } else if (op == IROperation::REPLACE) {
                if(res){
                    delOperandInVec(use, res);
                    addOperandToVec(def, res);
                }
                if(arg1 && !arg1->getIsGlobalSymbolVar()){
                    delOperandInVec(use, arg1);
                    addOperandToVec(def, arg1);
                }
            } else if (op == IROperation::ASSIGN_ARRAY_ELEM) {
                if(res && res->getOperandType() != OperandType::VALUE && !res->getIsGlobalSymbolVar()){ // src operand
                    delOperandInVec(def, res);
                    addOperandToVec(use, res);
                }
                if(arg1 && arg1->getOperandType() != OperandType::VALUE){
                    addOperandToVec(use, arg2);
                    delOperandInVec(def, arg2);
                }
                if(arg2 && arg2->getOperandType() != OperandType::VALUE){
                    addOperandToVec(use, arg2);
                    delOperandInVec(def, arg2);
                }
            } else if (op == IROperation::PHI) {
                if (res && res->getOperandType() != OperandType::VALUE && !res->getIsGlobalSymbolVar()) {
                    delOperandInVec(def, res);
                    addOperandToVec(use, res);
                }
                vector<IROperand *> args = code->getArgs();
                for (auto arg : args) {
                    if (arg->getOperandType() != OperandType::VALUE) {
                        addOperandToVec(use, arg);
                        delOperandInVec(def, arg);
                    }
                }
            } else {
                if(res && (res->getOperandType() == OperandType::SYMBOLVAR || res->getOperandType() == OperandType::TEMPVAR) && !res->getIsGlobalSymbolVar()){
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
    if (vec1.size() != vec2.size()) {
        return false;
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    return vec1 == vec2;
} 

void IRFunction::liveVarAnalysis() {
    bool changed;
    useDefVarsAnalysis();
    inVars = std::vector<std::vector<IROperand*>>(basicBlocks.size(), std::vector<IROperand*>());
    outVars = std::vector<std::vector<IROperand*>>(basicBlocks.size(), std::vector<IROperand*>());

    do{
        changed = false;
        for(int i = basicBlocks.size() - 1; i >= 0; i--){ // i for block number
            auto out = useVars[i];
            std::vector<IROperand*> newin;
            std::vector<IROperand*> newOut;
            // update out vars
            vector<int> ctrlflow = controlFlow[i];
            for(int back : ctrlflow){
                if (back >= inVars.size()) {
                    continue;
                }
                for(auto var : inVars[back])
                    addOperandToVec(newOut, var);
            }
            
            // IN = use U (out - def)
            // add OUT variables
            for(auto & var : newOut)
                addOperandToVec(newin, var);
            // delete DEF variables
            for(auto & var : defVars[i])
                delOperandInVec(newin, var);
            // add USE variables
            for(auto & var : useVars[i])
                addOperandToVec(newin, var);
            
            if(!cmpTwoInVars(inVars[i], newin)){
                // update inVar
                changed = true;       
                inVars[i].clear();
                for(auto & var : newin)
                    inVars[i].push_back(var);
            }
            if(!cmpTwoInVars(outVars[i], newOut)){
                // update inVar
                changed = true;
                outVars[i].clear();
                for(auto & var : newOut)
                    outVars[i].push_back(var);
            }
        }
    } while (changed);
}

// algorithm only works in Basic Block
void IRFunction::delDeadCode() {
    for(int i = basicBlocks.size() - 1; i >= 0; i--){
        for (int i = 0; i < basicBlocks.size(); i++) {
            if (basicBlocks[i].empty()) {
                basicBlocks.erase(basicBlocks.begin() + i);
                controlFlow.erase(controlFlow.begin() + i);
                Pred.erase(Pred.begin() + i);
                entrances.erase(entrances.begin() + i);
                cycleNum.erase(cycleNum.begin() + i);
                for(int j;j < controlFlow.size();j ++){
                    for(int k;k < controlFlow[j].size();k ++){
                        if(controlFlow[j][k] > i){
                            controlFlow[j][k] --;
                        }
                    }
                }
                for(int j;j < Pred.size();j ++){
                    for(int k;k < Pred[j].size();k ++){
                        if(Pred[j][k] >= i){
                            Pred[j][k] --;
                        }
                    }
                }
            }
        }
        auto block = basicBlocks[i];
        // set out vars to alive
        if (i == basicBlocks.size() - 1 || cycleNum[i] != 0) {
            for(auto & var : outVars[i]) {
                var->setAlive(true);
            }
        }
        // delete dead codes
        for(int j = block.size() - 1; j >= 0; j--){
            IRCode* code = block[j];
            IROperand* res = code->getResult();
            IROperand* arg1 = code->getArg1();
            IROperand* arg2 = code->getArg2();
            IROperation op = code->getOperation();

            if(op == IROperation::ADD_LABEL) {
                // can optimize
                if (block.size() == 1 && i < basicBlocks.size() - 1 && basicBlocks[i + 1][0]->getOperation() == IROperation::ADD_LABEL) {
                    for (auto it : basicBlocks) {
                        for (auto in_it : it) {
                            if (in_it->getOperation() == IROperation::GOTO) {
                                in_it->setArg1(basicBlocks[i + 1][0]->getArg1());
                            }
                            else if (in_it->getOperation() == IROperation::BEQZ) {
                                in_it->setArg2(basicBlocks[i + 1][0]->getArg1());
                            }
                        }
                    }
                    block.erase(block.begin() + j);
                    basicBlocks[i].erase(basicBlocks[i].begin() + j);
                    codes.erase(codes.begin() + entrances[i] + j);
                    for(int k = i + 1; k < basicBlocks.size(); k++)
                        entrances[k]--;
                    delete code;
                    continue;
                }
                continue;
            } else if (op == IROperation::GOTO) {
                if (j == block.size() - 1) {
                    if (basicBlocks[i + 1][0]->getOperation() == IROperation::ADD_LABEL) {
                        if (basicBlocks[i + 1][0]->getArg1() == arg1) {
                            block.erase(block.begin() + j);
                            basicBlocks[i].erase(basicBlocks[i].begin() + j);
                            codes.erase(codes.begin() + entrances[i] + j);
                            for(int k = i + 1; k < basicBlocks.size(); k++)
                                entrances[k]--;
                            delete code;
                            bool hasReference = false;
                            for (auto it : basicBlocks) {
                                for (auto in_it : it) {
                                    if (in_it->getOperation() == IROperation::GOTO) {
                                        if (in_it->getArg1() == arg1) {
                                            hasReference = true;
                                            break;
                                        }
                                    }
                                    else if (in_it->getOperation() == IROperation::BEQZ) {
                                        if (in_it->getArg2() == arg1) {
                                            hasReference = true;
                                            break;
                                        }
                                    }
                                }
                            }
                            if (!hasReference) {
                                basicBlocks[i + 1].erase(basicBlocks[i + 1].begin());
                                codes.erase(codes.begin() + entrances[i + 1]);
                                for(int k = i + 2; k < basicBlocks.size(); k++)
                                    entrances[k]--;
                                continue;
                            }
                        }
                    }
                    else if (basicBlocks[i + 1][0]->getOperation() == IROperation::GOTO) {
                        block.erase(block.begin() + j);
                        basicBlocks[i].erase(basicBlocks[i].begin() + j);
                        codes.erase(codes.begin() + entrances[i] + j);
                        for(int k = i + 1; k < basicBlocks.size(); k++)
                            entrances[k]--;
                        delete code;
                        bool hasReference = false;
                        bool findDef = false;
                        int block_i = 0, in_i = 0;
                        int block_i_def = 0, in_i_def = 0;
                        for (; block_i < basicBlocks.size(); block_i++) {
                            for (; in_i < basicBlocks[block_i].size(); in_i++) {
                                auto in_it = basicBlocks[block_i][in_i];
                                if (in_it->getOperation() == IROperation::GOTO) {
                                    if (in_it->getArg1() == arg1) {
                                        hasReference = true;
                                        if (findDef) {
                                            break;
                                        }
                                    }
                                }
                                else if (in_it->getOperation() == IROperation::BEQZ) {
                                    if (in_it->getArg2() == arg1) {
                                        hasReference = true;
                                        if (findDef) {
                                            break;
                                        }
                                    }
                                }
                                else if (in_it->getOperation() == IROperation::ADD_LABEL) {
                                    if (in_it->getArg1() == arg1) {
                                        findDef = true;
                                        block_i_def = block_i;
                                        in_i_def = in_i;
                                        if (hasReference) {
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        if (!hasReference) {
                            basicBlocks[block_i_def].erase(basicBlocks[block_i_def].begin() + in_i_def);
                            codes.erase(codes.begin() + entrances[block_i_def] + in_i_def);
                            for(int k = block_i_def + 1; k < basicBlocks.size(); k++)
                                entrances[k]--;
                            continue;
                        }
                    }
                }
            } else if (op == IROperation::CALL) {
                continue;
            } else if (op == IROperation::RETURN || op == IROperation::ADD_PARAM){
                if (arg1 && arg1->getOperandType() != OperandType::VALUE) {
                    arg1->setAlive(true);
                }
            } else if (op == IROperation::BEQZ) {
                if (block.size() == 1 && i < basicBlocks.size() - 1) {
                    if (basicBlocks[i + 1][0]->getOperation() == IROperation::ADD_LABEL) {
                        if (basicBlocks[i + 1][0]->getArg1() == arg2) {
                            block.erase(block.begin() + j);
                            basicBlocks[i].erase(basicBlocks[i].begin() + j);
                            codes.erase(codes.begin() + entrances[i] + j);
                            for(int k = i + 1; k < basicBlocks.size(); k++)
                                entrances[k]--;
                            delete code;
                            bool hasReference = false;
                            for (auto it : basicBlocks) {
                                for (auto in_it : it) {
                                    if (in_it->getOperation() == IROperation::GOTO) {
                                        if (in_it->getArg1() == arg2) {
                                            hasReference = true;
                                            break;
                                        }
                                    }
                                    else if (in_it->getOperation() == IROperation::BEQZ) {
                                        if (in_it->getArg2() == arg2) {
                                            hasReference = true;
                                            break;
                                        }
                                    }
                                }
                            }
                            if (!hasReference) {
                                basicBlocks[i + 1].erase(basicBlocks[i + 1].begin());
                                codes.erase(codes.begin() + entrances[i + 1]);
                                for(int k = i + 2; k < basicBlocks.size(); k++)
                                    entrances[k]--;
                                continue;
                            }
                        }
                    }
                }
            } else if (op == IROperation::GET_PARAM || op == IROperation::GET_RETURN) {
                if(res && (res->getOperandType() == OperandType::SYMBOLVAR || res->getOperandType() == OperandType::TEMPVAR))
                    if(res->getIsAlive() == false) {
                        block.erase(block.begin() + j);
                        basicBlocks[i].erase(basicBlocks[i].begin() + j);
                        codes.erase(codes.begin() + entrances[i] + j);
                        for(int k = i + 1; k < basicBlocks.size(); k++)
                            entrances[k]--;
                        delete code;
                        continue;
                    }
            } else if (op == IROperation::REPLACE) {
                if(res && res->getIsAlive() == false) {
                    block.erase(block.begin() + j);
                    basicBlocks[i].erase(basicBlocks[i].begin() + j);
                    codes.erase(codes.begin() + entrances[i] + j);
                    for(int k = i + 1; k < basicBlocks.size(); k++)
                        entrances[k]--;
                    if(arg1)
                        arg1->setAlive(false);
                    delete code;
                    continue;
                }
                if(arg1)
                    arg1->setAlive(true);
            } else if (op == IROperation::PHI) {
                if(res && res->getIsAlive() == false) {
                    block.erase(block.begin() + j);
                    basicBlocks[i].erase(basicBlocks[i].begin() + j);
                    codes.erase(codes.begin() + entrances[i] + j);
                    for(int k = i + 1; k < basicBlocks.size(); k++)
                        entrances[k]--;
                    for (auto it : code->getArgs()) {
                        it->setAlive(false);
                    }
                    delete code;
                    continue;
                }
                for (auto it : code->getArgs()) {
                    it->setAlive(true);
                }
            } else if (op == IROperation::ASSIGN_ARRAY_ELEM) {
                if(arg1 && arg1->getIsAlive() == false){ // a[t_0] = b, but a is not alive
                    block.erase(block.begin() + j);
                    basicBlocks[i].erase(basicBlocks[i].begin() + j);
                    codes.erase(codes.begin() + entrances[i] + j);
                    for(int k = i + 1; k < basicBlocks.size(); k++)
                        entrances[k]--;
                    if(arg1 && arg1->getOperandType() != OperandType::VALUE){
                        arg1->setAlive(false);
                    }
                    if(arg2 && arg2->getOperandType() != OperandType::VALUE){
                        arg2->setAlive(false);
                    }
                    delete code;
                    continue;
                }

                // if index is not immval, set it alive
                if(arg1 && arg1->getOperandType() != OperandType::VALUE){
                    arg1->setAlive(true);
                }
                if(arg2 && arg2->getOperandType() != OperandType::VALUE){
                    arg2->setAlive(true);
                }
                continue;
            } else {
                if(res){
                    if(!res->getIsAlive()){ // dead code
                        block.erase(block.begin() + j);
                        basicBlocks[i].erase(basicBlocks[i].begin() + j);
                        codes.erase(codes.begin() + entrances[i] + j);
                        for(int k = i + 1; k < basicBlocks.size(); k++)
                            entrances[k]--;
                        if(arg1 && (arg1->getOperandType() == OperandType::SYMBOLVAR || arg1->getOperandType() == OperandType::TEMPVAR))
                            arg1->setAlive(false);
                        if(arg2 && (arg2->getOperandType() == OperandType::SYMBOLVAR || arg2->getOperandType() == OperandType::TEMPVAR))
                            arg2->setAlive(false);
                        delete code;
                        continue;
                    }
                }
                if(arg1 && (arg1->getOperandType() == OperandType::SYMBOLVAR || arg1->getOperandType() == OperandType::TEMPVAR))
                    arg1->setAlive(true);
                if(arg2 && (arg2->getOperandType() == OperandType::SYMBOLVAR || arg2->getOperandType() == OperandType::TEMPVAR))
                    arg2->setAlive(true);
            }
        }
    }
}

void IRFunction::basicBlockDivision() {
    entrances.clear();
    entrances.push_back(0);
    for (int i = 0; i < codes.size(); i++) {
        if (find(entrances.begin(), entrances.end(), i) != entrances.end()) {
            continue;
        }
        if (codes[i]->getOperation() == IROperation::ADD_LABEL) {
            entrances.push_back(i);
        }
        if (codes[i]->getOperation() == IROperation::BEQZ || codes[i]->getOperation() == IROperation::GOTO) {
            entrances.push_back(i + 1);
        }
    }
    entrances.push_back(codes.size());
    for (int i = 0; i < entrances.size() - 1; i++) {
        /*
        for(int j = entrances[i];j < entrances[i+1];j++){
            codes[j]->getResult()->which_bb = i;
        }
        */
        basicBlocks.emplace_back(codes.begin() + entrances[i], codes.begin() + entrances[i + 1]);
    }
    entrances.pop_back();

    for(int i = 0; i < basicBlocks.size(); i++){
        if(i > 0 && codes[entrances[i] - 1]->getOperation() != IROperation::GOTO && codes[entrances[i] - 1]->getOperation() != IROperation::BEQZ)
            Pred.emplace_back(1, i - 1);
        else
            Pred.push_back(vector<int>());
    }

    for (int i = 0; i < basicBlocks.size(); i++)
    {
        if(i < basicBlocks.size() - 1 && codes[entrances[i+1]-1]->getOperation() != IROperation::GOTO)
            controlFlow.emplace_back(1, i + 1);
        else
            controlFlow.push_back(vector<int>());
            
        for (auto &j : basicBlocks[i])
        {
            if (j->getOperation() == IROperation::BEQZ || j->getOperation() == IROperation::GOTO) {
                for (int k = 0; k < entrances.size(); k++) {
                    if (codes[entrances[k]]->getOperation() != IROperation::ADD_LABEL) {
                        continue;
                    }
                    if (j->getOperation() == IROperation::BEQZ && codes[entrances[k]]->getArg1()->getSymbolName() == j->getArg2()->getSymbolName()) {
                        controlFlow.back().push_back(k);
                        Pred[k].push_back(i);
                    }
                    else if (j->getOperation() == IROperation::GOTO && codes[entrances[k]]->getArg1()->getSymbolName() == j->getArg1()->getSymbolName()) {
                        controlFlow.back().push_back(k);
                        Pred[k].push_back(i);
                    }
                }
            }
        }
    }

    /*sure.clear();
    for (int i = 0; i < controlFlow.size(); i++)
        sure.push_back(0);
    
    sure[0] = 1;
    for (int i = 0; i < controlFlow.size(); i++)
    {
        if(controlFlow[i].size == 1)
            sure[controlFlow[i][0]] |= sure[i];
        else if(controlFlow[i].size > 1)
            for (int j : controlFlow[i])
            {
                sure[controlFlow[i][j]] |= 0;
            }
    }*/
}

struct loopinfo* IRFunction::updateloop(int first, int end, int base){
    int now = base;
    for (int i = first; i < end; i++)
    {
        int layer = cycleNum[i];
        if (layer > now && layer == base + 1)
        {
            now = cycleNum[i];
            struct loopinfo in;
            in.subloop.clear();
            in.cyclelayer = cycleNum[i];
            in.handled = 0;
            in.start = i;
            for (int j = i; j < end; j++){
                if(cycleNum[j] > now)
                    in.subloop.push_back(updateloop(j, end, now));
                else if (cycleNum[j] < now)
                {
                    in.end = j - 1;
                    break;
                }
                else if (j == end - 1)
                    in.end = j;
            }

            in.pred = Pred[i];
            for (int k = in.start; k <= in.end; k++){
                auto pos = std::find(in.pred.begin(), in.pred.end(), k);
                while(pos != in.pred.end()){
                    in.pred.erase(pos);
                    pos = std::find(in.pred.begin(), in.pred.end(), k);
                }
            }

            loop.push_back(in);
        }else if(base && layer <= base)
            break;
        else if(layer < now)
            now = layer;
    }
    if(!loop.empty())
        return &loop.back();
    else
        return nullptr;
}

bool IRFunction::BBisinvalid(int i){
    if(basicBlocks[i].empty())
        return true;
    for (auto &j : basicBlocks[i])
    {
        IROperation op = j->getOperation();
        if (op != IROperation::ADD_LABEL && op != IROperation::GOTO && op != IROperation::BEQZ)
            return false;
    }

    return true;
}

void IRFunction::EraseBB(int i){
    codes.erase(codes.begin() + entrances[i], codes.begin() + entrances[i + 1]);
    for (int j = i + 1; j < entrances.size(); j++)
        entrances[j] -= basicBlocks[i].size();
    entrances.erase(entrances.begin() + i);

    for(int j = 0; j < controlFlow.size(); j++){
        if(j == i)
            continue;
        for(int k = 0; k < controlFlow[j].size(); k++)
            if(controlFlow[j][k] > i)
                controlFlow[j][k]--;
            else if(controlFlow[j][k] == i)
                controlFlow[j].erase(controlFlow[j].begin() + k);
    }

    for (int j = 0; j < Pred.size(); j++){
        if(j == i)
            continue;
        for(int k = 0; k < Pred[j].size(); k++)
            if(Pred[j][k] > i)
                Pred[j][k]--;
            else if(Pred[j][k] == i)
                Pred[j].erase(Pred[j].begin() + k);
    }

    controlFlow.erase(controlFlow.begin() + i);
    Pred.erase(Pred.begin() + i);

    basicBlocks.erase(basicBlocks.begin() + i);
}

void IRFunction::JumpThreading(){
    for (int i = 0; i < basicBlocks.size() - 1; i++) {
        printf("%d", i);
        IRCode *I = basicBlocks[i].back();
        if(i > 0 && codes[entrances[i] - 1]->getOperation() == IROperation::GOTO && codes[entrances[i]]->getOperation() != IROperation::ADD_LABEL){
            EraseBB(i);
            i--;
            continue;
        }

        if(codes[entrances[i]]->getOperation() == IROperation::ADD_LABEL && Pred[i].size() == 1){
            if(i > 0 && Pred[i][0] == i - 1){
                if((i == 1 || basicBlocks[i - 1].size() > 1) && codes[entrances[i] - 1]->getOperation() == IROperation::GOTO && codes[entrances[i] - 1]->getArg1()->getSymbolName() == codes[entrances[i]]->getArg1()->getSymbolName()){
                    basicBlocks[i - 1].erase(basicBlocks[i - 1].end() - 1);
                    codes.erase(codes.begin() + entrances[i] - 1);
                    for(int k = i; k < basicBlocks.size(); k++)
                        entrances[k]--;
                    if(BBisinvalid(i - 1)){
                        EraseBB(i - 1);
                        i--;
                    }
                }
                basicBlocks[i].erase(basicBlocks[i].begin());
                codes.erase(codes.begin() + entrances[i]);
                for(int k = i; k < basicBlocks.size(); k++)
                    entrances[k]--;
            }
        }

        if(I->getOperation() == IROperation::BEQZ && codes[entrances[i + 1]]->getArg1()->getSymbolName() == I->getArg2()->getSymbolName()){
            basicBlocks[i].erase(basicBlocks[i].end() - 1);
            codes.erase(codes.begin() + entrances[i + 1] - 1);
            for(int k = i + 1; k < basicBlocks.size(); k++)
                entrances[k]--;
        }

        if(I->getOperation() == IROperation::BEQZ && I->getArg1()->getOperandType() == OperandType::VALUE){
            if(stoi(I->getArg1()->getValue()) == 0){
                IRGoto* newcode = new IRGoto(I->getArg2());
                basicBlocks[i].pop_back();
                codes.erase(codes.begin() + entrances[i + 1] - 1);
                basicBlocks[i].push_back(newcode);
                codes.insert(codes.begin() + entrances[i + 1] - 1, newcode);

                auto pos = std::find(controlFlow[i].begin(),controlFlow[i].end(), i + 1);
                while( pos  != controlFlow[i].end()){
                    controlFlow[i].erase(pos);
                    pos = std::find(controlFlow[i].begin(), controlFlow[i].end(), i + 1);
                }
                pos = std::find(Pred[i + 1].begin(),Pred[i + 1].end(), i);
                while( pos  != Pred[i + 1].end()){
                    Pred[i + 1].erase(pos);
                    pos = std::find(Pred[i + 1].begin(), Pred[i + 1].end(), i);
                }
            }
            else
            {
                basicBlocks[i].erase(basicBlocks[i].end() - 1);
                codes.erase(codes.begin() + entrances[i + 1] - 1);
                for(int k = i + 1; k < basicBlocks.size(); k++)
                    entrances[k]--;

                int tar;
                for (int j = 0; j < controlFlow[i].size(); j++)
                {
                    tar = controlFlow[i][j];
                    if (codes[entrances[tar]]->getArg1()->getSymbolName() == I->getArg2()->getSymbolName())
                        break;
                    else
                        tar = -1;
                }

                if(tar >= 0){
                    auto pos = std::find(controlFlow[i].begin(),controlFlow[i].end(), tar);
                    while( pos  != controlFlow[i].end()){
                        controlFlow[i].erase(pos);
                        pos = std::find(controlFlow[i].begin(), controlFlow[i].end(), tar);
                    }
                    pos = std::find(Pred[tar].begin(), Pred[tar].end(), i);
                    while( pos  != Pred[tar].end()){
                        Pred[i + 1].erase(pos);
                        pos = std::find(Pred[tar].begin(), Pred[tar].end(), i);
                    }
                }
            }
        }

        if(I->getOperation() != IROperation::GOTO && I->getOperation() != IROperation::BEQZ){
            
            if(Pred[i + 1].size() == 1 && Pred[i+1].back() == i){
                if(codes[entrances[i + 1]]->getOperation() == IROperation::ADD_LABEL){
                    basicBlocks[i + 1].erase(basicBlocks[i + 1].begin());
                    codes.erase(codes.begin() + entrances[i + 1]);
                    for(int k = i + 1; k < basicBlocks.size(); k++)
                        entrances[k]--;
                }
                /*
                for(int k = entrances[i+1];k < codes.size();k++){
                    if(codes[k]->getResult())
                        codes[k]->getResult()->which_bb --;
                }
                */
                basicBlocks[i].insert(basicBlocks[i].end(), basicBlocks[i + 1].begin(), basicBlocks[i + 1].end());
                basicBlocks.erase(basicBlocks.begin() + i + 1);
                entrances.erase(entrances.begin() + i + 1);
                Pred.erase(Pred.begin() + i + 1);
                controlFlow[i].erase(controlFlow[i].begin());
                controlFlow[i].insert(controlFlow[i].end(), controlFlow[i + 1].begin(), controlFlow[i + 1].end());
                controlFlow.erase(controlFlow.begin() + i + 1);
            }
        }else if(I->getOperation() == IROperation::GOTO){
            int tar = -1;
            int tmp = controlFlow[i].back();
            if (codes[entrances[tmp]]->getArg1()->getSymbolName() == I->getArg1()->getSymbolName())
            {
                tar = tmp;
            }

            if(tar >= 0 && Pred[tar].size() == 1 && Pred[tar].back() == i && basicBlocks[tar].back()->getOperation() == IROperation::GOTO){
                if(codes[entrances[tar]]->getOperation() == IROperation::ADD_LABEL){
                    basicBlocks[tar].erase(basicBlocks[tar].begin());
                    codes.erase(codes.begin() + entrances[tar]);
                    for(int k = i + 1; k < basicBlocks.size(); k++)
                        entrances[k]--;
                }
                //delete GOTO
                basicBlocks[i].erase(basicBlocks[i].begin() + basicBlocks[i].size() - 1);
                codes.erase(codes.begin() + entrances[i] + basicBlocks[i].size() - 1);
                for(int k = i + 1; k < basicBlocks.size(); k++)
                    entrances[k]--;
                //move code
                /*
                for(int k = 0; k < basicBlocks[tar].size(); k++)
                {
                    if(basicBlocks[tar][k]->getResult()){
                        basicBlocks[tar][k]->getResult()->which_bb = i;
                    }
                }
                for(int k = entrances[tar + 1];k < codes.size();k ++){
                    if(codes[k]->getResult()){
                        codes[k]->getResult()->which_bb --;
                    }
                }
                */
                codes.insert(codes.begin() + entrances[i + 1], basicBlocks[tar].begin(), basicBlocks[tar].end());
                for(int k = i + 1; k < basicBlocks.size(); k++)
                    entrances[k] += basicBlocks[tar].size();
                codes.erase(codes.begin() + entrances[tar], codes.begin() + entrances[tar] + basicBlocks[tar].size());
                for(int k = tar + 1; k < basicBlocks.size(); k++)
                    entrances[k] -= basicBlocks[tar].size();
                
                basicBlocks[i].insert(basicBlocks[i].end(), basicBlocks[tar].begin(), basicBlocks[tar].end());
                basicBlocks.erase(basicBlocks.begin() + tar);
                entrances.erase(entrances.begin() + tar);
                Pred.erase(Pred.begin() + tar);
                controlFlow[i].pop_back();
                controlFlow[i].insert(controlFlow[i].end(), controlFlow[tar].begin(), controlFlow[tar].end());
                controlFlow.erase(controlFlow.begin() + tar);

                if(i >= tar)
                    i--;
            }
            else if (basicBlocks[i].size() > 1 && BBisinvalid(i))
            {
                int tar = controlFlow[i].back();
                for (int k = 0; k < Pred[i].size(); k++)
                {
                    int tmp = Pred[i][k];
                    IRCode *j = basicBlocks[tmp].back();
                    if (j->getOperation() == IROperation::BEQZ && codes[entrances[i]]->getArg1()->getSymbolName() == j->getArg2()->getSymbolName()) {
                        j->setArg2(basicBlocks[i].back()->getArg1());
                    }
                    else if (j->getOperation() == IROperation::GOTO && codes[entrances[i]]->getArg1()->getSymbolName() == j->getArg1()->getSymbolName()) {
                        j->setArg1(basicBlocks[i].back()->getArg1());
                    }

                    int sign = 0;
                    auto pos = std::find(controlFlow[tmp].begin(),controlFlow[tmp].end(), i);
                    while( pos  != controlFlow[tmp].end()){
                        if(pos != controlFlow[tmp].end() && !sign){
                            controlFlow[tmp][pos - controlFlow[tmp].begin()] = tar;
                            sign = 1;
                        }
                        else if(pos != controlFlow[tmp].end() && sign)
                            controlFlow[tmp].erase(pos);
                        else
                            break;
                        pos = std::find(controlFlow[tmp].begin(),controlFlow[tmp].end(), i);
                    }
                    /*for (int a = 0; a < controlFlow[tmp].size(); a++)
                    {
                        int j = controlFlow[tmp][a];
                        if (j == i){
                            controlFlow[tmp][a] = tar;
                            j = tar;
                        }

                        if(j == tar && !sign)
                            sign = 1;
                        else if(j == tar && sign){
                            controlFlow[tmp].erase(controlFlow[tmp].begin() + a);
                            a--;
                        }
                    }*/
                }
                /*
                for(int k = entrances[i + 1];k < codes.size();k ++){
                    if(codes[k]->getResult()){
                        codes[k]->getResult()->which_bb --;
                    }
                }
                */
                codes.erase(codes.begin() + entrances[i], codes.begin() + entrances[i] + basicBlocks[i].size());
                for(int k = i + 1; k < basicBlocks.size(); k++)
                    entrances[k] -= basicBlocks[i].size();
                
                entrances.erase(entrances.begin() + i);
                Pred.erase(Pred.begin() + i);
                controlFlow.erase(controlFlow.begin() + i);
                
                basicBlocks[i].clear();
                basicBlocks.erase(basicBlocks.begin() + i);
                i--;
            }
        }
    }
}

struct loopinfo* IRFunction::loopchoose(int i){
    int first, end;
    for (first = i; first < basicBlocks.size(); first++)
        if(cycleNum[first] > 0){
            int layer = cycleNum[first];
            for (int k = 0;k < loop.size();k++ )
            {
                loopinfo* j = &loop[k];
                if(j->cyclelayer == layer && j->start == first && !j->handled){
                    struct loopinfo * tmp = j;
                    while(!tmp->subloop.empty()){
                        int pos = 1;
                        if (!tmp->subloop.front()->handled){
                            tmp = tmp->subloop.front();
                            continue;
                        }
                        while(tmp->subloop[pos]->handled)
                        {
                            pos++;
                            if(pos >= tmp->subloop.size())
                                break;
                        }

                        if(pos >= tmp->subloop.size())
                            break;
                        if(!tmp->subloop[pos]->handled){
                            tmp = tmp->subloop[pos];
                            continue;
                        }
                    }

                    tmp->handled = 1;
                    return tmp;
                }
            }
        }

    return nullptr;
}

void IRFunction:: HoistOnLoop(loopinfo * currentloop){
    /*use recursing to process sub loop*/
    if(currentloop->subloop.size() > 0){
        for(int i = 0;i < currentloop->subloop.size();i ++)
            HoistOnLoop(currentloop->subloop[i]);
    }
    /*process this loop*/
    if(currentloop->pred.size() == 0){
        /*no prevous basic block, create a new bb*/
        entrances.insert(entrances.begin()+currentloop->start,entrances[currentloop->start]);

        basicBlocks.insert(basicBlocks.begin() + currentloop->start,{});

        for(int i = 0;i < Pred.size();i++){
            for(int j = 0;j < Pred[i].size();j ++){
                if(Pred[i][j] >= currentloop->start){
                    Pred[i][j] ++;
                }
            }
        }
        Pred[currentloop->start].push_back(currentloop->start);
        Pred.insert(Pred.begin() + currentloop->start,{});

        for(int i = 0;i < controlFlow.size();i++){
            for(int j = 0;j < controlFlow[i].size();j ++){
                if(controlFlow[i][j] >= currentloop->start){
                    controlFlow[i][j] ++;
                }
            }
        }
        controlFlow.insert(controlFlow.begin() + currentloop->start,{});
        controlFlow[currentloop->start].push_back(currentloop->start+1);

        cycleNum.insert(cycleNum.begin() + currentloop->start, currentloop->cyclelayer - 1);

        int prev_start = currentloop->start;
        for(int i = 0;i < loop.size();i ++){
            if(loop[i].start >= prev_start){
                loop[i].start ++;
            }
            if(loop[i].end >= prev_start){
                loop[i].end ++;
            }
            for(int j = 0;j < loop[i].pred.size();j ++){
                if(loop[i].pred[j] >= prev_start){
                    loop[i].pred[j] ++;
                }
            }
        }
        currentloop->pred.push_back(prev_start);

        for(int i = entrances[prev_start+1];i < codes.size();i ++){
            codes[i]->getResult()->which_bb++;
        }
        /*create new bb, process as one prevous bb*/
    
    }
    else if(currentloop->pred.size() == 1){
        /*one prevous basic block, use this bb*/
        ;
    }
    else{
        /*two or more prevous, create a new bb, all prev bb flow to this new bb*/
        /*create a new basic block*/
        entrances.insert(entrances.begin()+currentloop->start,entrances[currentloop->start]);

        basicBlocks.insert(basicBlocks.begin() + currentloop->start,{});

        for(int i = 0;i < Pred.size();i++){
            for(int j = 0;j < Pred[i].size();j ++){
                if(Pred[i][j] >= currentloop->start){
                    Pred[i][j] ++;
                }
            }
        }
        //Pred[currentloop->start].push_back(currentloop->start);
        Pred.insert(Pred.begin() + currentloop->start,{});
        Pred[currentloop->start].insert(Pred[currentloop->start].end(),currentloop->pred.begin(),currentloop->pred.end());
        Pred[currentloop->start + 1].push_back(currentloop->start);
        for(int i = 0;i < Pred[currentloop->start].size();i ++){
            for(int j = 0;j < Pred[currentloop->start+1].size();j++){
                if(Pred[currentloop->start][i] == Pred[currentloop->start+1][j]){
                    Pred[currentloop->start+1].erase(Pred[currentloop->start+1].begin()+j);
                }
                if(Pred[currentloop->start][i] > currentloop->start)
                    currentloop->pred[i]++;
            }
        }

        for(int i = 0;i < controlFlow.size();i++){
            for(int j = 0;j < controlFlow[i].size();j ++){
                if(controlFlow[i][j] >= currentloop->start ){
                    controlFlow[i][j] ++;
                }
            }
        }

        int prev_start = currentloop->start;
        for(int i = 0;i < loop.size();i ++){
            if(loop[i].start >= prev_start){
                loop[i].start ++;
            }
            if(loop[i].end >= prev_start){
                loop[i].end ++;
            }
            for(int j = 0;j < loop[i].pred.size();j ++){
                if(loop[i].pred[j] >= prev_start){
                    loop[i].pred[j] ++;
                }
            }
        }

        controlFlow.insert(controlFlow.begin() + prev_start,{});
        controlFlow[prev_start].push_back(prev_start+1);
        for(int i = 0;i < currentloop->pred.size();i ++){
            for(int j = 0;j < controlFlow[currentloop->pred[i]].size();j ++){
                if(controlFlow[currentloop->pred[i]][j] == prev_start + 1){
                    controlFlow[currentloop->pred[i]][j] = prev_start;
                }
            }
        }

        cycleNum.insert(cycleNum.begin() + currentloop->start, currentloop->cyclelayer - 1);

        while(!currentloop->pred.empty()){
            currentloop->pred.pop_back();
        }

        currentloop->pred.push_back(prev_start);

        for(int i = entrances[prev_start+1];i < codes.size();i ++){
            codes[i]->getResult()->which_bb++;
        }

        /*add label in new bb */
        IRLabel* newlabel = addLabel();
        IRAddLabel* newcode = new IRAddLabel(newlabel); 
        for(int i = prev_start + 1;i < basicBlocks.size();i ++){
            entrances[i] ++;
        }
        basicBlocks[prev_start].push_back(newcode);
        codes.insert(codes.begin() + entrances[prev_start],newcode);
        
        /* make all bbs flowing to currentloop now flow to the new bb*/
        IRLabel* prevlabel = (IRLabel*) basicBlocks[currentloop->start][0]->getArg1();
        for(int i = 0; i < Pred[prev_start].size();i ++){
            int j = basicBlocks[i].size() - 1;
            if (basicBlocks[i][j]->getOperation() == IROperation::GOTO)
            {
                IRLabel* tmplabel = (IRLabel*) basicBlocks[i][j]->getArg1();
                if(tmplabel == prevlabel){
                    basicBlocks[i][j]->setArg1(newlabel);
                }
            }else if(basicBlocks[i][j]->getOperation() == IROperation::BEQZ){
                IRLabel* tmplabel = (IRLabel*) basicBlocks[i][j]->getArg2();
                if(tmplabel == prevlabel){
                    basicBlocks[i][j]->setArg2(newlabel);
                }
            }
        }

    }
    /*after adding new basic block before loop, process as one prevous basic block*/
    for(int bnum = currentloop->start;bnum <= currentloop->end;bnum ++){
        if(cycleNum[bnum] == currentloop->cyclelayer){
            for(int cnum = 0; cnum < basicBlocks[bnum].size();cnum ++){
                if((basicBlocks[bnum][cnum]->getArg1()->getOperandType() == OperandType::VALUE ||
                   basicBlocks[bnum][cnum]->getArg1()->which_bb < currentloop->start) &&
                   (basicBlocks[bnum][cnum]->getArg2()->getOperandType() == OperandType::VALUE ||
                   basicBlocks[bnum][cnum]->getArg2()->which_bb < currentloop->start) &&
                   (IRCode::isTwoArgAssignmentOperation(basicBlocks[bnum][cnum]->getOperation()) ||
                   basicBlocks[bnum][cnum]->getOperation() == IROperation::ASSIGN ||
                   basicBlocks[bnum][cnum]->getOperation() == IROperation::FETCH_ARRAY_ELEM ||
                   basicBlocks[bnum][cnum]->getOperation() == IROperation::ASSIGN_ARRAY_ELEM)){
                    IRCode* tmp = basicBlocks[bnum][cnum];
                    tmp->getResult()->which_bb = currentloop->pred[0];
                    Hoist(currentloop,tmp,currentloop->pred[0]);
                    basicBlocks[bnum].erase(basicBlocks[bnum].begin()+cnum);
                    codes.erase(codes.begin() + entrances[bnum] + cnum);
                    for(int k = bnum+1;k < basicBlocks.size();k++)
                        entrances[k] --;
                }
            }
        }
    }

}

void IRFunction:: Hoist(loopinfo * currentloop, IRCode * code_pos, int entrance){
    int bnum;
    int boff;
    cycleNum = vector<int>(entrances.size(), 0);
    for (int i = 0; i < controlFlow.size(); i++) {
        for (int j : controlFlow[i]) {
            if (j <= i) {
                for (int k = j; k <= i; k++)
                {
                    cycleNum[k]++;
                }               
            }
        }
    }
    for(int i = entrance+1; i < entrances.size();i ++){
        entrances[i] ++;
    }
    int push_pos = basicBlocks[entrance].size();
    basicBlocks[entrance].push_back(code_pos);
    codes.insert(codes.begin()+entrances[entrance]+push_pos,code_pos);
}

void IRFunction::LICM(){
    loop.clear();
    updateloop(0, cycleNum.size(), 0);
    
    for(int i = 0;i < basicBlocks.size();i ++){
        for(int j = 0;j < basicBlocks[i].size();j ++){
            if(basicBlocks[i][j]->getResult()){
                basicBlocks[i][j]->getResult()->which_bb = i;
            }
        }
    }
    for (int j = 0; j < loop.size(); j++){
        if(loop[j].cyclelayer == 1)
            HoistOnLoop(&loop[j]);
    }
    for(int i = 0;i < basicBlocks.size();i ++){
        if(basicBlocks[i].size() == 0){
            entrances.erase(entrances.begin() + i);

            basicBlocks.erase(basicBlocks.begin() + i);

            for(int j = 0;j < Pred.size();j ++){
                for(int k = 0;k < Pred[j].size();k ++){
                    if(Pred[j][k] >= i){
                        Pred[j][k] --;
                    }
                }
            }
            Pred[i+1].insert(Pred[i+1].end(),Pred[i].begin(),Pred[i].end());
            Pred.erase(Pred.begin() + i);

            for(int j = 0;j < controlFlow.size();j ++){
                for(int k = 0;k < controlFlow[j].size();k ++){
                    if(controlFlow[j][k] > i){
                        controlFlow[j][k] --;
                    }
                }
            }
            controlFlow[i-1].insert(controlFlow[i-1].end(),controlFlow[i].begin(),controlFlow[i].end());
            controlFlow.erase(controlFlow.begin() + i);

            cycleNum.erase(cycleNum.begin() + i);

            for(int j = 0;j < loop.size();j ++){
                if(loop[j].start > i){
                    loop[j].start --;
                }
                if(loop[j].end > i){
                    loop[j].end --;
                }
                for(int k = 0;k < loop[j].pred.size();k ++){
                    if(loop[j].pred[k] >= i){
                        loop[j].pred[k] --;
                    }
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
    for (auto i : Tools::sortIndexes(degrees)) {
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
    for (auto i : Tools::sortIndexes(costs)) {
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
        if (sortedOperands[i]->getMetaDataType() == MetaDataType::INT) {
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
    def_use_list();
    switch (inOptimizeLevel)
    {
    case 0:
        basicBlockDivision();
        constFolding();
        liveVarAnalysis();
        delDeadCode();
        JumpThreading();
        break;
    case 1:
        basicBlockDivision();
        constFolding();
        JumpThreading();
        break;
    case 2:
        basicBlockDivision();
        constFolding();
        liveVarAnalysis();
        delDeadCode();
        break;
    case 3:
        basicBlockDivision();
        // liveVarAnalysis();
        // delDeadCode();
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
        for (auto param : vector<tuple<MetaDataType, bool,std::size_t>>(paramTypeList.begin(), paramTypeList.end() - 1)) {
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
    // Register *ra = t->tryGetCertainRegister(true, "ra", hasFreeRegister);
    Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
    // t->addCodeSd(sp, ra, -8);
    // t->setRegisterFree(ra);
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
        // Register *ra = t->tryGetCertainRegister(true, "ra", hasFreeRegister);
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
        // t->addCodeLd(ra, sp, -8);
        t->addCodeRet();
        t->setRegisterFree(sp);
        // t->setRegisterFree(ra);
    }
}

IRProgram::IRProgram() {}

IRProgram *IRProgram::getIRProgram(string newProgramName, SymbolTable *newGlobalSymbolTable) {
    // singleton
    static IRProgram instance;
    static bool initialized = false;
    if (!initialized) {
        instance.initializeFields(newProgramName, newGlobalSymbolTable);
        initialized = true;
    }
    return &instance;
}

void IRProgram::initializeFields(string newProgramName, SymbolTable *newGlobalSymbolTable) {
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
            func.second->ir = this;
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
