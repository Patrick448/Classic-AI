//
// Created by patrick on 18/09/23.
//

#ifndef CLASSICAI_AIALGORITHM_H
#define CLASSICAI_AIALGORITHM_H


#include "GTree.h"
#include "Problem.h"
#include "RuleSet.h"

class AIAlgorithm {

private:
    vector<GTNode*> successNodes;
    GTree* searchTree;

public:
    GTree* irrevocableSearch(Problem* problem, RuleSet* ruleSet, int maxDepth);
    GTree* backtrackingSearch(Problem* problem, RuleSet* ruleSet, int maxDepth);
    GTree* breadthFirstSearch(Problem* problem, RuleSet* ruleSet, int maxDepth);
    GTree* depthFirstSearch(Problem* problem, RuleSet* ruleSet, int maxDepth);
    GTree* successTree();
};


#endif //CLASSICAI_AIALGORITHM_H
