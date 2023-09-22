//
// Created by patrick on 18/09/23.
//

#include <iostream>
#include <fstream>
#include "AIAlgorithm.h"
#include "JHPRuleSet.h"

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
        cout << currentNode->getState()->toString() << endl;
        currentNode = currentNode->getChildren()[0];
    }
    cout << currentNode->getState()->toString() << endl;
}

int main(int argc, char** argv){
    AIAlgorithm algorithm = AIAlgorithm();

    JealousHusbandsProblem problem = JealousHusbandsProblem();
    JHPRuleSet ruleSet = JHPRuleSet(15);

    GTree* tree = algorithm.breadthFirstSearch(&problem, &ruleSet, 50);
    //algorithm.pruneFailurePaths();
    outputToFile("../graph.dot", tree->dotString(), false);

    cout << tree->dotString() << endl;
    delete tree;
}

