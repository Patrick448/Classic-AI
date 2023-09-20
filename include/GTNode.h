#ifndef CASALCIUMENTO_GTNODE_H
#define CASALCIUMENTO_GTNODE_H

#include "State.h"
#include <vector>
#include <queue>

using namespace std;

/* Nó da árvore genérica (GENERAL TREE NODE - GTNODE), contém como key um objeto da classe SCENARIO, classe que
 * mostra uma foto do estado do problema, ou seja, um estado. Contém ponteiro para o pai e um vetor que contém
 * ponteiros para os filhos do nó, que variam entre 0 e número máximo de regras - 1*/

class GTNode{

public:
    GTNode(State* state, GTNode* parent); //construtor
    GTNode(State* state);
    ~GTNode(); //destrutor
    State* getState(); //retorna o SCENARIO (key)
    GTNode* getParent(); //retorna o ponteiro para o pai
    vector<GTNode*> getChildren(); //retorna vetor de ponteiros para os filhos
    void makeChild(GTNode* child); //após um no ser criado, essa funcao adiciona um ponteiro para ele no vetor de filhos do no atual
    void printState(); //printa o estado, objeto scenario (key)
    bool isLeaf(); //retorna se é folha (vetor de filhos vazio)
    bool isEqual(State state); //dada um scenario, confere se é o mesmo do no atual
    void removeChild(GTNode* child); //se child esta no vetor de filhos, remove-o de lá
    int getNodeId() const;
    void setNodeId(int nodeId);
    string dotString();

protected:
    static int NEXT_NODE_ID;
    State* state; //key
    GTNode *parent; //ponteiro pro pai
    vector<GTNode*> children; //filhos
    int stateNumber; //numero do estado atual (sequencial)
    int selectedRule; //regra escolhida para gerar o estado atual
    int nodeID;

};

#endif //CASALCIUMENTO_GTNODE_H
