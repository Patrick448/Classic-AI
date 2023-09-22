//
// Created by patrick on 18/09/23.
//

#include "JHPState.h"
int JHPState::NEXT_ID = 0;

// constructor, defaults to the initial state
JHPState::JHPState() {

    this->innerVector[0] = 1;
    this->innerVector[1] = 1;
    this->innerVector[2] = 1;
    this->innerVector[3] = 1;
    this->innerVector[4] = 1;
    this->innerVector[5] = 1;
    this->innerVector[6] = 1;
    this->id = NEXT_ID;
    NEXT_ID++;

}

void JHPState::copyVector(State *state) {
    JHPState* jhpState = dynamic_cast<JHPState*>(state);

    for(int i=0; i<7; i++){
        this->innerVector[i] = jhpState->getInnerVector()[i];
    }
}


int *JHPState::getInnerVector() {
    return this->innerVector;
}

JHPState::JHPState(int h1, int h2, int h3, int m1, int m2, int m3, int b) {
    //hotel side
    this->innerVector[0] = h1;
    this->innerVector[1] = h2;
    this->innerVector[2] = h3;
    this->innerVector[3] = m1;
    this->innerVector[4] = m2;
    this->innerVector[5] = m3;
    this->innerVector[6] = b;
}

void JHPState::auxMove(int passenger) {

    if(this->innerVector[passenger]==0){
        this->innerVector[passenger] =1;
    }else{
        this->innerVector[passenger] =0;
    }
}

void JHPState::move(int passenger) {
    auxMove(passenger);
    auxMove(6);
}

void JHPState::move(int passenger1, int passenger2) {
    auxMove(passenger1);
    auxMove(passenger2);
    auxMove(6);
}

bool JHPState::isValid() {
    bool valid = true;
    bool womanAlone=false;
    bool withOtherMen=false;

    for(int m=3; m<6 && valid; m++){
        if(innerVector[m] != innerVector[m-3]){
            womanAlone = true;
        }
        for(int h=0; h<3; h++){
            if(innerVector[m] == innerVector[h]){
                withOtherMen = true;
            }
        }

        if(womanAlone && withOtherMen){
            valid = false;
        }else{
            womanAlone=false;
            withOtherMen=false;
        }
    }


    return valid;
}

JHPState *JHPState::tryGenerateStateMoving(int passenger1, int passenger2) {
    JHPState* newState = new JHPState();
    newState->copyVector(this);

    if(!this->canMove(passenger1, passenger2)){
        delete newState;
        newState = nullptr;
    }
    else{
        newState->move(passenger1, passenger2);
        if(!newState->isValid()){
            delete newState;
            newState = nullptr;
        }
    }

    return newState;
}


JHPState *JHPState::tryGenerateStateMoving(int passenger) {
    JHPState* newState = new JHPState();
    newState->copyVector(this);

    if(!this->canMove(passenger)){
        delete newState;
        newState = nullptr;
    }
    else{
        newState->move(passenger);
        if(!newState->isValid()){
            delete newState;
            newState = nullptr;
        }
    }

    return newState;
}


bool JHPState::canMove(int passenger1) {
    bool possibleTraversal = false;
    int* vec = this->getInnerVector();

    if(vec[passenger1] == vec[6]){
        possibleTraversal = true;
    }

    return possibleTraversal;
}

bool JHPState::canMove(int passenger1, int passenger2) {
    return canMove(passenger1) && canMove(passenger2);
}

bool JHPState::operator==(const State &rhs) const {
    const JHPState& rhsJHP = dynamic_cast<const JHPState&>(rhs);

    for(int i=0; i<7; i++){
        if(this->innerVector[i] != rhsJHP.innerVector[i]){
            return false;
        }
    }
    return true;
}

std::string JHPState::toStringWithRule() {
    std::string stateStr = "\t\t\t|\t\t\t\n\t\t\t"+ std::to_string(this->generatingRule) + "\n\t\t\t|\t\t\t\n" + "[";
    for(int i=0; i<7; i++){
        stateStr +=" "+ std::to_string(this->innerVector[i]) + " |";
    }

    stateStr.pop_back();
    stateStr.pop_back();

    stateStr+= "]";
    return stateStr;
}

std::string JHPState::toString() {
    std::string stateStr = "";
    for(int i=0; i<7; i++){
        stateStr +=" "+ std::to_string(this->innerVector[i]) + " |";
    }

    stateStr.pop_back();
    stateStr.pop_back();

    return stateStr;
}

int JHPState::getGeneratingRule() const {
    return generatingRule;
}

void JHPState::setGeneratingRule(int generatingRule) {
    this->generatingRule = generatingRule;
}



