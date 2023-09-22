//
// Created by patrick on 18/09/23.
//

#ifndef CLASSICAI_JEALOUSHUSBANDSPROBLEM_H
#define CLASSICAI_JEALOUSHUSBANDSPROBLEM_H


#include "State.h"
#include "Problem.h"
#include "JHPState.h"

//this class represents the problem to be solved by the algorithm
class JealousHusbandsProblem : public Problem{
    State* initialState;
    State* goalState;

    public:
    JealousHusbandsProblem();
    ~JealousHusbandsProblem();
    State* getInitialState() override;
    State* getGoalState() override;
    void setInitialState(State* initialState) override;
    void setGoalState(State* goalState) override;
    State * createNewState() override;
};


#endif //CLASSICAI_JEALOUSHUSBANDSPROBLEM_H
