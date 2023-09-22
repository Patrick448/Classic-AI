//
// Created by patrick on 18/09/23.
//

#ifndef CLASSICAI_RULESET_H
#define CLASSICAI_RULESET_H


#include "State.h"
#include <vector>


class RuleSet {

public:
   // RuleSet(int numRules);
    /*~RuleSet();*/
    virtual State* applyRule(State* state, int ruleNumber)=0;
    virtual int getRuleByIndex(int index)=0;
    virtual int getNumRules() const=0;
    virtual void setNumRules(int numRules)=0;

};


#endif //CLASSICAI_RULESET_H
