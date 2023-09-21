//
// Created by patrick on 18/09/23.
//

#include "RuleSet.h"

RuleSet::RuleSet(int numRules) {
    this->numRules = numRules;
    this->ruleStandardOrder = new int[this->numRules]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                                    11, 12, 13, 14, 15};

    /*for(int i=0; i< numRules; i++){
        ruleStandardOrder[i] = i+1;
    }*/
}

RuleSet::~RuleSet() {
    delete[] this->ruleStandardOrder;
}


State *RuleSet::rule1(State *state) {
    State *newState = state->tryGenerateStateMoving(3, 4);

    return newState;
}

State *RuleSet::rule2(State *state) {
    State *newState = state->tryGenerateStateMoving(4, 5);
    return newState;
}

State *RuleSet::rule3(State *state) {
    State *newState = state->tryGenerateStateMoving(3, 5);
    return newState;
}

State *RuleSet::rule4(State *state) {
    State *newState = state->tryGenerateStateMoving(3);
    return newState;
}

State *RuleSet::rule5(State *state) {
    State *newState = state->tryGenerateStateMoving(4);
    return newState;
}

State *RuleSet::rule6(State *state) {
    State *newState = state->tryGenerateStateMoving(5);
    return newState;
}

State *RuleSet::rule7(State *state) {
    State *newState = state->tryGenerateStateMoving(0, 1);
    return newState;
}

State *RuleSet::rule8(State *state) {
    State *newState = state->tryGenerateStateMoving(1, 2);
    return newState;
}

State *RuleSet::rule9(State *state) {
    State *newState = state->tryGenerateStateMoving(0, 2);
    return newState;
}

State *RuleSet::rule10(State *state) {
    State *newState = state->tryGenerateStateMoving(0);
    return newState;
}

State *RuleSet::rule11(State *state) {
    State *newState = state->tryGenerateStateMoving(1);
    return newState;
}

State *RuleSet::rule12(State *state) {
    State *newState = state->tryGenerateStateMoving(2);
    return newState;
}

State *RuleSet::rule13(State *state) {
    State *newState = state->tryGenerateStateMoving(0, 3);
    return newState;
}

State *RuleSet::rule14(State *state) {
    State *newState = state->tryGenerateStateMoving(1, 4);
    return newState;
}

State *RuleSet::rule15(State *state) {
    State *newState = state->tryGenerateStateMoving(2, 5);
    return newState;
}

State *RuleSet::applyRule(State *state, int ruleNumber) {

    State *resultingState = state;

    if (ruleNumber == 1) {
        resultingState = this->rule1(state);
    } else if (ruleNumber == 2) {
        resultingState = this->rule2(state);
    } else if (ruleNumber == 3) {
        resultingState = this->rule3(state);
    } else if (ruleNumber == 4) {
        resultingState = this->rule4(state);
    } else if (ruleNumber == 5) {
        resultingState = this->rule5(state);
    } else if (ruleNumber == 6) {
        resultingState = this->rule6(state);
    } else if (ruleNumber == 7) {
        resultingState = this->rule7(state);
    } else if (ruleNumber == 8) {
        resultingState = this->rule8(state);
    } else if (ruleNumber == 9) {
        resultingState = this->rule9(state);
    } else if (ruleNumber == 10) {
        resultingState = this->rule10(state);
    } else if (ruleNumber == 11) {
        resultingState = this->rule11(state);
    } else if (ruleNumber == 12) {
        resultingState = this->rule12(state);
    } else if (ruleNumber == 13) {
        resultingState = this->rule13(state);
    } else if (ruleNumber == 14) {
        resultingState = this->rule14(state);
    } else if (ruleNumber == 15) {
        resultingState = this->rule15(state);
    }

    if(resultingState!= nullptr){
        resultingState->setGeneratingRule(ruleNumber);
    }

    return resultingState;
}


State *RuleSet::applyNextRule(State *state) {
    return nullptr;
}

int RuleSet::getRuleByIndex(int index){
    return ruleStandardOrder[index];
}


bool RuleSet::isApplicable(State *state, int ruleNumber) {
    bool applicable = false;
    State *result = applyRule(state, ruleNumber);

    return false;
}

int RuleSet::getNumRules() const {
    return numRules;
}

void RuleSet::setNumRules(int numRules) {
    RuleSet::numRules = numRules;
}




