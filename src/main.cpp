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

void printMatrix2(int mat[3][3])
{
    // Loop to print the matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <3; j++)
            std::cout << mat[i][j] << " ";
        std::cout << std::endl;
    }
}

void test(){
    int cube[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    for (int i = 0; i < 3; i++) {
        for(int j=i; j<3; j++){
            int aux = cube[i][j];
            cube[i][j] = cube[j][i];
            cube[j][i] = aux;
        }
    }

    for(int i=0; i<1; i++){
        for(int j=0; j<3; j++){
            int aux = cube[i][j];
            cube[i][j] = cube[2-i][j];
            cube[2-i][j] = aux;
        }
    }





    printMatrix2(cube);
}


int main(int argc, char** argv){
    test();
    return 0;
    AIAlgorithm algorithm = AIAlgorithm();

    JealousHusbandsProblem problem = JealousHusbandsProblem();
    JHPRuleSet ruleSet = JHPRuleSet(15);

    GTree* tree = algorithm.breadthFirstSearch(&problem, &ruleSet, 50);
    //algorithm.pruneFailurePaths();
    outputToFile("../graph.dot", tree->dotString(), false);

    cout << tree->dotString() << endl;
    delete tree;
}

