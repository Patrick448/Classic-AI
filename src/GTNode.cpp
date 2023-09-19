#include "GTNode.h"
#include <vector>
#include <algorithm>
#include<iostream>

GTNode::GTNode(State* state, GTNode* parent) {
    this->state = state;
    this->parent = parent;
    parent->children.push_back(this);
    //this->stateNumber = stateNumber;
    //this->selectedRule = ruleNumber;
}

GTNode::~GTNode() {
    delete this->state;
}
GTNode::GTNode(State* state) {
    this->state = state;
    this->parent = nullptr;
}

State* GTNode::getState() {
    return this->state;
}

GTNode* GTNode::getParent() {
    return this->parent;
}

vector<GTNode*> GTNode::getChildren() {
    return this->children;
}

void GTNode::makeChild(GTNode *child) {
    this->children.push_back(child);
}

void GTNode::printState() {
   /* cout << endl;
    cout << "--------------------------------------";
    cout << endl;
    cout << "State: " << this->stateNumber << endl;
    cout << "Last Rule: R" << this->selectedRule << endl;
    this->state.print();
    queue<int> q = this->getQueue();
    cout << "Possibly rules: {";
    while (!q.empty())
    {
        if (q.size() != 1)
            cout << q.front() << " ";
        else
            cout << q.front();

        q.pop();
    }
    cout << "}" << endl;
    cout << "--------------------------------------" << endl;*/
}

bool GTNode::isLeaf() {
    if(children.empty())
        return true;
    else
        return false;
}

bool GTNode::isEqual(State state) {
   /* if (this->state == state)
        return true;
    else
        return false;*/
}




void GTNode::removeChild(GTNode *child) {
    vector<GTNode*>::iterator it;
    it = find(this->children.begin(), this->children.end(), child);
    if (it != this->children.end()){
        this->children.erase(it);
        //cout << "filho removido!" << endl;
    }
    else
    {
        //cout << "filho nao encontrado" << endl;
    }
};