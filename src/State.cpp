//
// Created by patrick on 18/09/23.
//

#include "State.h"
int State::NEXT_ID = 0;

// constructor, defaults to the initial state
State::State() {

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

void State::copyVector(State *state) {

    for(int i=0; i<7; i++){
        this->innerVector[i] = state->getInnerVector()[i];
    }
}


int *State::getInnerVector() {
    return this->innerVector;
}

State::State(int h1, int h2, int h3, int m1, int m2, int m3, int b) {
    //hotel side
    this->innerVector[0] = h1;
    this->innerVector[1] = h2;
    this->innerVector[2] = h3;
    this->innerVector[3] = m1;
    this->innerVector[4] = m2;
    this->innerVector[5] = m3;
    this->innerVector[6] = b;


}

void State::auxMove(int passenger) {

    if(this->innerVector[passenger]==0){
        this->innerVector[passenger] =1;
    }else{
        this->innerVector[passenger] =0;
    }
}

void State::move(int passenger) {
    auxMove(passenger);
    auxMove(6);
}

void State::move(int passenger1, int passenger2) {
    auxMove(passenger1);
    auxMove(passenger2);
    auxMove(6);
}

bool State::isValid() {
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

State *State::tryGenerateStateMoving(int passenger1, int passenger2) {
    State* newState = new State();
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


State *State::tryGenerateStateMoving(int passenger) {
    State* newState = new State();
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


bool State::canMove(int passenger1) {
    bool possibleTraversal = false;
    int* vec = this->getInnerVector();

    if(vec[passenger1] == vec[6]){
        possibleTraversal = true;
    }

    return possibleTraversal;
}

bool State::canMove(int passenger1, int passenger2) {
    return canMove(passenger1) && canMove(passenger2);
}

bool State::operator==(const State &rhs) const {

    for(int i=0; i<7; i++){
        if(this->innerVector[i] != rhs.innerVector[i]){
            return false;
        }
    }
    return true;

}

std::string State::toString() {
    std::string stateStr = "\t\t\t|\t\t\t\n\t\t\t"+ std::to_string(this->generatingRule) + "\n\t\t\t|\t\t\t\n" + "[";
    for(int i=0; i<7; i++){
        stateStr +=" "+ std::to_string(this->innerVector[i]) + " |";
    }

    stateStr.pop_back();
    stateStr.pop_back();

    stateStr+= "]";
    return stateStr;
}

int State::getGeneratingRule() const {
    return generatingRule;
}

void State::setGeneratingRule(int generatingRule) {
    State::generatingRule = generatingRule;
}



