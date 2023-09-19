//
// Created by patrick on 18/09/23.
//

#include <iostream>
#include "AIAlgorithm.h"

using namespace std;

void auxPrintTreeOnePath(GTree* tree){
    GTNode* currentNode = tree->getRoot();
    while(currentNode->getChildren().size() > 0){
        cout << currentNode->getState()->toString() << endl;
        currentNode = currentNode->getChildren()[0];
    }
    cout << currentNode->getState()->toString() << endl;
}

int main(int argc, char** argv){
    AIAlgorithm algorithm = AIAlgorithm();
    Problem problem = Problem();
    RuleSet ruleSet = RuleSet(15);
    GTree* tree = algorithm.irrevocableSearch(&problem, &ruleSet);
    auxPrintTreeOnePath(tree);
    delete tree;
}

