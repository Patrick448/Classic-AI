//
// Created by patrick on 18/09/23.
//

#include "JHPRuleSet.h"

JHPRuleSet::JHPRuleSet(int numRules){
    this->numRules = numRules;
    this->ruleStandardOrder = new int[numRules]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                                    11, 12, 13, 14, 15};

}


JHPRuleSet::~JHPRuleSet() {
    delete[] this->ruleStandardOrder;
}


JHPState *JHPRuleSet::rule1(JHPState *state) {
    JHPState *newState = state->tryGenerateStateMoving(3, 4);

    return newState;
}

JHPState *JHPRuleSet::rule2(JHPState *state) {
    JHPState *newState = state->tryGenerateStateMoving(4, 5);
    return newState;
}

JHPState *JHPRuleSet::rule3(JHPState *state) {
    JHPState *newState = state->tryGenerateStateMoving(3, 5);
    return newState;
}

JHPState *JHPRuleSet::rule4(JHPState *state) {
    JHPState *newState = state->tryGenerateStateMoving(3);
    return newState;
}

JHPState *JHPRuleSet::rule5(JHPState *state) {
    JHPState *newState = state->tryGenerateStateMoving(4);
    return newState;
}

JHPState *JHPRuleSet::rule6(JHPState *state) {
    JHPState *newState = state->tryGenerateStateMoving(5);
    return newState;
}

JHPState *JHPRuleSet::rule7(JHPState *state) {
    JHPState *newState = state->tryGenerateStateMoving(0, 1);
    return newState;
}

JHPState *JHPRuleSet::rule8(JHPState *state) {
    JHPState *newState = state->tryGenerateStateMoving(1, 2);
    return newState;
}

JHPState *JHPRuleSet::rule9(JHPState *state) {
    JHPState *newState = state->tryGenerateStateMoving(0, 2);
    return newState;
}

JHPState *JHPRuleSet::rule10(JHPState *state) {
    JHPState *newState = state->tryGenerateStateMoving(0);
    return newState;
}

JHPState *JHPRuleSet::rule11(JHPState *state) {
    JHPState *newState = state->tryGenerateStateMoving(1);
    return newState;
}

JHPState *JHPRuleSet::rule12(JHPState *state) {
    JHPState *newState = state->tryGenerateStateMoving(2);
    return newState;
}

JHPState *JHPRuleSet::rule13(JHPState *state) {
    JHPState *newState = state->tryGenerateStateMoving(0, 3);
    return newState;
}

JHPState *JHPRuleSet::rule14(JHPState *state) {
    JHPState *newState = state->tryGenerateStateMoving(1, 4);
    return newState;
}

JHPState *JHPRuleSet::rule15(JHPState *state) {
    JHPState *newState = state->tryGenerateStateMoving(2, 5);
    return newState;
}

State *JHPRuleSet::applyRule(State *state, int ruleNumber) {
    JHPState jhpState = dynamic_cast<JHPState &>(*state);

    State *resultingState = state;

    if (ruleNumber == 1) {
        resultingState = this->rule1(&jhpState);
    } else if (ruleNumber == 2) {
        resultingState = this->rule2(&jhpState);
    } else if (ruleNumber == 3) {
        resultingState = this->rule3(&jhpState);
    } else if (ruleNumber == 4) {
        resultingState = this->rule4(&jhpState);
    } else if (ruleNumber == 5) {
        resultingState = this->rule5(&jhpState);
    } else if (ruleNumber == 6) {
        resultingState = this->rule6(&jhpState);
    } else if (ruleNumber == 7) {
        resultingState = this->rule7(&jhpState);
    } else if (ruleNumber == 8) {
        resultingState = this->rule8(&jhpState);
    } else if (ruleNumber == 9) {
        resultingState = this->rule9(&jhpState);
    } else if (ruleNumber == 10) {
        resultingState = this->rule10(&jhpState);
    } else if (ruleNumber == 11) {
        resultingState = this->rule11(&jhpState);
    } else if (ruleNumber == 12) {
        resultingState = this->rule12(&jhpState);
    } else if (ruleNumber == 13) {
        resultingState = this->rule13(&jhpState);
    } else if (ruleNumber == 14) {
        resultingState = this->rule14(&jhpState);
    } else if (ruleNumber == 15) {
        resultingState = this->rule15(&jhpState);
    }

    if(resultingState!= nullptr){
        resultingState->setGeneratingRule(ruleNumber);
    }

    return resultingState;
}


State *JHPRuleSet::applyNextRule(State *state) {
    return nullptr;
}

int JHPRuleSet::getRuleByIndex(int index){
    return ruleStandardOrder[index];
}



int JHPRuleSet::getNumRules() const {
    return numRules;
}

void JHPRuleSet::setNumRules(int numRules) {
    this->numRules = numRules;
}




