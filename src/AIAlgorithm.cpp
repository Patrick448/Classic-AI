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
        }else {
            GTNode *newNode = new GTNode(newState, currentNode);
            currentNode = newNode;

            if (*newState == *problem->getGoalState()) {
                success = true;
            }
        }

    }

    return searchTree;
}

GTree *AIAlgorithm::backtrackingSearch(Problem *problem, RuleSet* ruleSet) {
    bool success = false;
    bool failure = false;
    GTree* searchTree = new GTree();
    State* currentState = new State();
    GTNode* currentNode = new GTNode(currentState);
    searchTree->setRoot(currentNode);
    int currentRule;
    vector<int> rulesStack;
    rulesStack.push_back(0);

    while(!success && !failure) {
        State *newState = nullptr;
        //currentRule =0;


        //tries to apply rules until it succeeds or has tried all of them
        while (newState == nullptr && rulesStack.back() <= 14) {
            newState = ruleSet->applyRule(currentNode->getState(), ruleSet->getRuleByIndex(rulesStack.back()));
            if (newState != nullptr && searchTree->findOnPath(newState, currentNode)) {
                delete newState;
                newState = nullptr;
            }
            rulesStack.back()++;
        }

        if (newState == nullptr) {
            //failure = true;
            rulesStack.pop_back();
            currentNode = currentNode->getParent();

            if(currentNode== nullptr){
                failure = true;
            }

        } else {
            GTNode *newNode = new GTNode(newState, currentNode);
            currentNode = newNode;
            rulesStack.push_back(0);

            if (*newState == *problem->getGoalState()) {
                success = true;
                cout << "----------------SUCCESS!----------------" << endl;
                cout << newState->toStringWithRule() << endl;
            }
        }


    }

    return searchTree;
}

GTree *AIAlgorithm::breadthFirstSearch(Problem *problem, RuleSet *ruleSet) {
    return nullptr;
}

GTree *AIAlgorithm::depthFirstSearch(Problem *problem, RuleSet *ruleSet) {
    return nullptr;
}
