//
// Created by patrick on 18/09/23.
//

#ifndef CLASSICAI_RUBIKRULESET_H
#define CLASSICAI_RUBIKRULESET_H


#include "State.h"
#include <vector>
#include "RuleSet.h"
#include "RubikState.h"

class RubikRuleSet: public RuleSet{

public:

    State* applyRule(State* state, int ruleNumber);
    int getRuleByIndex(int index);
    int getNumRules() const;
    void setNumRules(int numRules);
    RubikState* rule1(RubikState* state);
    RubikState* rule2(RubikState* state);
    RubikState* rule3(RubikState* state);
    RubikState* rule4(RubikState* state);
    RubikState* rule5(RubikState* state);
    RubikState* rule6(RubikState* state);
    RubikState* rule7(RubikState* state);
    RubikState* rule8(RubikState* state);
    RubikState* rule9(RubikState* state);
    RubikState* rule10(RubikState* state);
    RubikState* rule11(RubikState* state);
    RubikState* rule12(RubikState* state);

};


#endif //CLASSICAI_RULESET_H
