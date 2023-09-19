//
// Created by patrick on 18/09/23.
//

#ifndef CLASSICAI_AIALGORITHM_H
#define CLASSICAI_AIALGORITHM_H


#include "GTree.h"
#include "Problem.h"
#include "RuleSet.h"

class AIAlgorithm {

public:
    GTree* irrevocableSearch(Problem* problem, RuleSet* ruleSet);
};


#endif //CLASSICAI_AIALGORITHM_H
