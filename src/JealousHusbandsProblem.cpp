//
// Created by patrick on 18/09/23.
//

#include "JealousHusbandsProblem.h"

JealousHusbandsProblem::JealousHusbandsProblem()  {
    this->initialState = new State();
    this->goalState = new State(0,0,0,0,0,0,0);
}

JealousHusbandsProblem::~JealousHusbandsProblem() {
    delete this->initialState;
    delete this->goalState;
}

State *JealousHusbandsProblem::getInitialState() {
    return this->initialState;
}

State *JealousHusbandsProblem::getGoalState() {
    return this->goalState;
}

void JealousHusbandsProblem::setInitialState(State *initialState) {
    this->initialState = initialState;
}

void JealousHusbandsProblem::setGoalState(State *goalState) {
    this->goalState = goalState;
}
