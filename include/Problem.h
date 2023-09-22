//
// Created by patrick on 18/09/23.
//

#ifndef CLASSICAI_PROBLEM
#define CLASSICAI_PROBLEM_H


#include "State.h"

//this class represents the problem to be solved by the algorithm
class Problem {

private:
    public:
    virtual State* getInitialState()= 0;
    virtual State* getGoalState()=0;
    virtual void setInitialState(State* initialState)=0;
    virtual void setGoalState(State* goalState)=0;
    virtual State* createNewState()=0;
};


#endif //CLASSICAI_JEALOUSHUSBANDSPROBLEM_H
