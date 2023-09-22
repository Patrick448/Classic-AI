//
// Created by patrick on 22/09/23.
//

#include "RubikRuleSet.h"
#include "RubikState.h"


State *RubikRuleSet::applyRule(State *state, int ruleNumber) {
    RubikState jhpState = dynamic_cast<RubikState &>(*state);

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
    }

    if (resultingState != nullptr) {
        resultingState->setGeneratingRule(ruleNumber);
    }

    return resultingState;
}

//U
RubikState *RubikRuleSet::rule1(RubikState *state) {
    return nullptr;
}

RubikState *RubikRuleSet::rule2(RubikState *state) {
    return nullptr;
}

RubikState *RubikRuleSet::rule3(RubikState *state) {
    return nullptr;
}

RubikState *RubikRuleSet::rule4(RubikState *state) {
    return nullptr;
}

RubikState *RubikRuleSet::rule5(RubikState *state) {
    return nullptr;
}

RubikState *RubikRuleSet::rule6(RubikState *state) {
    return nullptr;
}

RubikState *RubikRuleSet::rule7(RubikState *state) {
    return nullptr;
}

RubikState *RubikRuleSet::rule8(RubikState *state) {
    return nullptr;
}

RubikState *RubikRuleSet::rule9(RubikState *state) {
    return nullptr;
}

RubikState *RubikRuleSet::rule10(RubikState *state) {
    return nullptr;
}

RubikState *RubikRuleSet::rule11(RubikState *state) {
    return nullptr;
}

RubikState *RubikRuleSet::rule12(RubikState *state) {
    return nullptr;
}

int RubikRuleSet::getRuleByIndex(int index) {
    return 0;
}

int RubikRuleSet::getNumRules() const {
    return 0;
}

void RubikRuleSet::setNumRules(int numRules) {

}



