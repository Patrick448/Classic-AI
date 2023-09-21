//
// Created by patrick on 18/09/23.
//

#include <iostream>
#include "AIAlgorithm.h"
#include <stack>

GTree *AIAlgorithm::irrevocableSearch(Problem *problem, RuleSet* ruleSet, int maxDepth) {
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
        while(newState == nullptr && currentRule < ruleSet->getNumRules()){
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
                this->successNodes.push_back(currentNode);

            }
        }

    }

    return searchTree;
}

GTree *AIAlgorithm::backtrackingSearch(Problem *problem, RuleSet* ruleSet, int maxDepth) {
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
        while (newState == nullptr && rulesStack.back() < ruleSet->getNumRules()) {
            newState = ruleSet->applyRule(currentNode->getState(), ruleSet->getRuleByIndex(rulesStack.back()));
            if (newState != nullptr && searchTree->findOnPath(newState, currentNode)) {
                delete newState;
                newState = nullptr;
            }
            rulesStack.back()++;
        }

        if (newState == nullptr) {
            rulesStack.pop_back();
            currentNode = currentNode->getParent();

            if(currentNode== nullptr){
                failure = true;
                cout << "FAILURE" << endl;
            }

        } else {
            GTNode *newNode = new GTNode(newState, currentNode);
            currentNode = newNode;
            rulesStack.push_back(0);

            if (*newState == *problem->getGoalState()) {
                success = true;
                cout << "SUCCESS" << endl;
                this->successNodes.push_back(currentNode);

                //cout << newState->toStringWithRule() << endl;
            }
        }


    }

    return searchTree;
}

GTree *AIAlgorithm::breadthFirstSearch(Problem *problem, RuleSet *ruleSet, int maxDepth) {
    bool success = false;
    bool failure = false;
    int depth = 1;
    GTree* searchTree = new GTree();
    State* currentState = new State();
    GTNode* currentNode = new GTNode(currentState);
    searchTree->setRoot(currentNode);

    queue<GTNode*> open;
    queue<GTNode*> closed;
    open.push(currentNode);

    while(!success && !failure) {
        State *newState = nullptr;

        //todo: ver se é possível implementar o maxDepth
        // precisaria ter como saber cada vez que um nível é completado
        if(open.empty()/* || depth == maxDepth*/){
            failure = true;
            cout << "FAILURE" << endl;
        }else {
            currentNode = open.front();

            if (*currentNode->getState() == *problem->getGoalState()) {
                success = true;
                cout << "SUCCESS" << endl;
                this->successNodes.push_back(currentNode);

            } else {
                for (int i = 0; i < ruleSet->getNumRules(); i++) {
                    newState = ruleSet->applyRule(currentNode->getState(), ruleSet->getRuleByIndex(i));
                    if (newState == nullptr || searchTree->findOnPath(newState, currentNode)) {
                        delete newState;
                        newState = nullptr;
                    } else {
                        GTNode *newNode = new GTNode(newState, currentNode);
                        open.push(newNode);
                    }
                }
            }
        }
        open.pop();
    }

    this->searchTree = searchTree;
    return searchTree;
}

GTree *AIAlgorithm::depthFirstSearch(Problem *problem, RuleSet *ruleSet, int maxDepth) {
    bool success = false;
    bool failure = false;
    int depth = 1;
    GTree* searchTree = new GTree();
    State* currentState = new State();
    GTNode* currentNode = new GTNode(currentState);
    searchTree->setRoot(currentNode);

    stack<GTNode*> open;
    queue<GTNode*> closed;
    open.push(currentNode);

    while(!success && !failure) {
        State *newState = nullptr;

        //todo: ver se é possível implementar o maxDepth
        // precisaria ter como saber cada vez que um nível é completado
        if(open.empty()/* || depth == maxDepth*/){
            failure = true;
            cout << "FAILURE" << endl;
        }else {
            currentNode = open.top();
            open.pop();

            if (*currentNode->getState() == *problem->getGoalState()) {
                success = true;
                cout << "SUCCESS" << endl;
                this->successNodes.push_back(currentNode);
            } else {
                for (int i = 0; i < ruleSet->getNumRules(); i++) {
                    newState = ruleSet->applyRule(currentNode->getState(), ruleSet->getRuleByIndex(i));
                    if (newState == nullptr || searchTree->findOnPath(newState, currentNode)) {
                        delete newState;
                        newState = nullptr;
                    } else {
                        GTNode *newNode = new GTNode(newState, currentNode);
                        open.push(newNode);
                    }
                }
            }
        }
    }

    this->searchTree = searchTree;
    return searchTree;

}

void AIAlgorithm::pruneFailurePaths() {

    this->searchTree->prune(successNodes);
}
