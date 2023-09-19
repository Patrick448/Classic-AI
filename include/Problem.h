//
// Created by patrick on 18/09/23.
//

#ifndef CLASSICAI_PROBLEM_H
#define CLASSICAI_PROBLEM_H


#include "State.h"

//this class represents the problem to be solved by the algorithm
class Problem {
    State* initialState;
    State* goalState;

    public:
    Problem();
    ~Problem();
    State* getInitialState();
    State* getGoalState();
    void setInitialState(State* initialState);
    void setGoalState(State* goalState);
};


#endif //CLASSICAI_PROBLEM_H
