//
// Created by patrick on 18/09/23.
//

#ifndef CLASSICAI_RULESET_H
#define CLASSICAI_RULESET_H


#include "State.h"
#include <vector>


class RuleSet {
    private:

        int* ruleStandardOrder;
        int numRules;
public:
    int getNumRules() const;

    void setNumRules(int numRules);

public:
        RuleSet(int numRules);
        ~RuleSet();
        State* applyRule(State* state, int ruleNumber);
        State* applyNextRule(State* state);
        State* rule1(State* state);
        State* rule2(State* state);
        State* rule3(State* state);
        State* rule4(State* state);
        State* rule5(State* state);
        State* rule6(State* state);
        State* rule7(State* state);
        State* rule8(State* state);
        State* rule9(State* state);
        State* rule10(State* state);
        State* rule11(State* state);
        State* rule12(State* state);
        State* rule13(State* state);
        State* rule14(State* state);
        State* rule15(State* state);
        int getRuleByIndex(int index);

        bool isApplicable(State* state, int ruleNumber);

};


#endif //CLASSICAI_RULESET_H
