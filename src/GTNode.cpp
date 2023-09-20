#include "GTNode.h"
#include <vector>
#include <algorithm>
#include<iostream>

int GTNode::NEXT_NODE_ID = 0;

GTNode::GTNode(State* state, GTNode* parent) {
    this->state = state;
    this->parent = parent;
    parent->children.push_back(this);
    //this->stateNumber = stateNumber;
    //this->selectedRule = ruleNumber;
    this->nodeID = NEXT_NODE_ID;
    NEXT_NODE_ID++;
}

GTNode::~GTNode() {
    delete this->state;
}
GTNode::GTNode(State* state) {
    this->state = state;
    this->parent = nullptr;
    this->nodeID = NEXT_NODE_ID;
    NEXT_NODE_ID++;
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
}

int GTNode::getNodeId() const {
    return nodeID;
}

void GTNode::setNodeId(int nodeId) {
    nodeID = nodeId;
}

string GTNode::dotString() {
    string str = std::to_string(this->nodeID);
    str+= "[label=\"" + this->state->toString() + "\"];\n";

    for(int i = 0; i < this->children.size(); i++){
        str += std::to_string(this->nodeID) + " -> " + std::to_string(this->children[i]->getNodeId());
        str += "[label=\"" + std::to_string(this->children[i]->getState()->getGeneratingRule()) + "\"];\n";
        str += this->children[i]->dotString();
    }

    return str;
};