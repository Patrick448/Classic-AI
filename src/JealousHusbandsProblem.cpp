//
// Created by patrick on 18/09/23.
//

#include "JealousHusbandsProblem.h"
#include "JHPState.h"

JealousHusbandsProblem::JealousHusbandsProblem()  {
    this->initialState = new JHPState();
    this->goalState = new JHPState(0,0,0,0,0,0,0);
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

State *JealousHusbandsProblem::createNewState() {
    return new JHPState();
}
