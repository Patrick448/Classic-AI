//
// Created by patrick on 18/09/23.
//

#include <iostream>
#include "AIAlgorithm.h"

GTree *AIAlgorithm::irrevocableSearch(Problem *problem, RuleSet* ruleSet) {
    bool success = false;
    bool failure = false;
    GTree* searchTree = new GTree();
    State* currentState = new State();
    GTNode* currentNode = new GTNode(currentState);
    searchTree->setRoot(currentNode);
    int currentRule;

    while(!success && !failure){
        State* newState = nullptr;
        currentRule =0;
        //tries to apply rules until it succeeds or has tried all of them
        while(newState == nullptr && currentRule <= 14){
            newState = ruleSet->applyRule(currentNode->getState(), ruleSet->getRuleByIndex(currentRule));
            if(newState!= nullptr && searchTree->findOnPath(newState, currentNode)){
                delete newState;
                newState = nullptr;
            }
            currentRule ++;
        }

        if(newState == nullptr){
            failure = true;
        }else if(*currentNode->getState() == *problem->getGoalState()){
            success = true;
        }else{
            GTNode* newNode = new GTNode( newState, currentNode);
            currentNode = newNode;
           // cout << currentNode->getState()->toString() << endl;
        }

    }

    return searchTree;
}
