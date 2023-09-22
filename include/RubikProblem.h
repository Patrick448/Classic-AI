//
// Created by patrick on 18/09/23.
//

#ifndef CLASSICAI_RUBIKPROBLEM
#define CLASSICAI_RUBIKPROBLEM_H


#include "State.h"
#include "Problem.h"

//this class represents the problem to be solved by the algorithm
class RubikProblem : public Problem {

private:
    public:
    State* getInitialState();
    State* getGoalState();
    void setInitialState(State* initialState);
    void setGoalState(State* goalState);
    State* createNewState();
};


#endif //CLASSICAI_JEALOUSHUSBANDSPROBLEM_H
