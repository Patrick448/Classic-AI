//
// Created by patrick on 18/09/23.
//

#include <iostream>
#include <fstream>
#include "AIAlgorithm.h"

using namespace std;

void outputToFile(string path, string text, bool append)
{
    ofstream outputf;

    if (append)
    {
        outputf.open(path, std::ios_base::app);
    }
    else
    {
        outputf.open(path);
    }

    outputf << text;
    outputf.close();
}

void auxPrintTreeOnePath(GTree* tree){
    GTNode* currentNode = tree->getRoot();
    while(currentNode->getChildren().size() > 0){
        cout << currentNode->getState()->toStringWithRule() << endl;
        currentNode = currentNode->getChildren()[0];
    }
    cout << currentNode->getState()->toStringWithRule() << endl;
}

int main(int argc, char** argv){
    AIAlgorithm algorithm = AIAlgorithm();
    Problem problem = Problem();
    RuleSet ruleSet = RuleSet(15);
    GTree* tree = algorithm.backtrackingSearch(&problem, &ruleSet, 50);
    auxPrintTreeOnePath(tree);
    //algorithm.pruneFailurePaths();
    outputToFile("../graph.dot", tree->dotString(), false);

    cout << tree->dotString() << endl;
    delete tree;
}

