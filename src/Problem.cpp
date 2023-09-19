//
// Created by patrick on 18/09/23.
//

#include "Problem.h"

Problem::Problem() {
    this->initialState = new State();
    this->goalState = new State(0,0,0,0,0,0,0);
}

Problem::~Problem() {
    delete this->initialState;
    delete this->goalState;
}

State *Problem::getInitialState() {
    return this->initialState;
}

State *Problem::getGoalState() {
    return this->goalState;
}

void Problem::setInitialState(State *initialState) {
    this->initialState = initialState;
}

void Problem::setGoalState(State *goalState) {
    this->goalState = goalState;
}
