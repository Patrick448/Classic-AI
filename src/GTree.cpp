#include "GTree.h"
#include "GTNode.h"
#include <vector>
#include <iostream>


/*GTree::GTree(vector<int> rules) {
    this->rules = rules;
    cout << "ARVORE CRIADA. SEQUENCIA DE REGRAS: ";
    for (int i = 0; i < this->rules.size(); i++)
        cout << rules.at(i) << " ";
    cout << endl;
    State state;
    GTNode *node;
    node = this->Insert(state, nullptr, 0);
    this->root = node;
}*/

GTree::~GTree() {
    this->clear(this->root);
}

GTNode* GTree::Insert(State state, GTNode *parent, int selectedRule) {
   /* this->stateCounter++;
    GTNode* node = new GTNode(state, parent, this->stateCounter, selectedRule);
    if (parent != nullptr)
        parent->makeChild(node);
    this->updateQueue(node);
    return node;*/
}

bool GTree::Search(State state) {
    int flag = 0;
    this->auxSearch(state, this->root, flag);
    if (flag == 0)
        return false;
    else
        return true;
}

void GTree::auxSearch(State sc, GTNode *node, int &flag) {
    if (node->isEqual(sc))
        flag = 1;
    else
        if (!node->isLeaf())
            for(int i = 0; i < node->getChildren().size(); i++)
                this->auxSearch(sc, node->getChildren().at(i), flag);
}

GTNode* GTree::getRoot() {
    return this->root;
}

void GTree::print() {
    cout << "Imprimindo sequencia de estados e regras: ";
    auxPrint(this->root);
}

void GTree::auxPrint(GTNode *node) {
    node->printState();
    if (!node->isLeaf())
        for(int i = 0; i < node->getChildren().size(); i++)
            auxPrint(node->getChildren().at(i));
}

void GTree::clear(GTNode *node) {
    if (!node->isLeaf())
        for(int i = 0; i < node->getChildren().size(); i++)
            clear(node->getChildren().at(i));
    delete node;
}

bool GTree::findOnPath(State *state, GTNode *node) {


    GTNode* currentNode = node;
    while (currentNode != nullptr) //unico nó que tem como pai null é a raiz
    {
        if (*currentNode->getState() == *state){
            return true;
        }else{
            currentNode = currentNode->getParent();
        }
    }

    return false;
}

GTNode* GTree::RemoveLeaf(GTNode *node) {
    if (!node->isLeaf()){
        //cout << "Nó não é folha. Impossível remover." << endl;
        return node;
    }
    GTNode *p = node->getParent();
    p->removeChild(node);
    this->clear(node);
    this->stateCounter--;
    return p;
}



GTree::GTree() {
    //State* state = nullptr;
    //GTNode* node = nullptr;
    //this->stateCounter++;
    this->root = nullptr;
}

int GTree::getTotalStates() {
    return this->stateCounter;
}

void GTree::setRoot(GTNode *node) {
    this->root = node;
}

string GTree::dotString() {

    string str = "digraph G {\n";
    str+= "node [margin=0.1 width=0.5 shape=record style=rounded]\nedge[fontcolor=blue]\n";
    str+= this->root->dotString() + "\n}";
    return str;
}

void GTree::prune(vector<GTNode *> keepList) {
    for(int i=0; i<keepList.size(); i++){
        GTNode* node = keepList.at(i);
        node->pruneBackwards(node);
    }
}

