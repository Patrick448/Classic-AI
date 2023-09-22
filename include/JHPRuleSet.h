//
// Created by patrick on 18/09/23.
//

#ifndef CLASSICAI_JHPRULESET_H
#define CLASSICAI_JHPRULESET_H


#include "State.h"
#include <vector>
#include "JHPRuleSet.h"
#include "RuleSet.h"
#include "JHPState.h"

class JHPRuleSet:public RuleSet {
private:
    int* ruleStandardOrder;
    int numRules;

public:
    int getNumRules() const;
    void setNumRules(int numRules);
    JHPRuleSet(int numRules);
    ~JHPRuleSet();
    State* applyRule(State* state, int ruleNumber);
    State* applyNextRule(State* state);
    int getRuleByIndex(int index);
    JHPState* rule1(JHPState* state);
    JHPState* rule2(JHPState* state);
    JHPState* rule3(JHPState* state);
    JHPState* rule4(JHPState* state);
    JHPState* rule5(JHPState* state);
    JHPState* rule6(JHPState* state);
    JHPState* rule7(JHPState* state);
    JHPState* rule8(JHPState* state);
    JHPState* rule9(JHPState* state);
    JHPState* rule10(JHPState* state);
    JHPState* rule11(JHPState* state);
    JHPState* rule12(JHPState* state);
    JHPState* rule13(JHPState* state);
    JHPState* rule14(JHPState* state);
    JHPState* rule15(JHPState* state);
};


#endif //CLASSICAI_RULESET_H
