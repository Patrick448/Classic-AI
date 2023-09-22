//
// Created by patrick on 22/09/23.
//

#include "RubikState.h"
#include <iostream>

RubikState::RubikState() {

}

RubikState::~RubikState() {

}


int RubikState::getGeneratingRule() const {
    return 0;
}

void RubikState::setGeneratingRule(int generatingRule) {

}

bool RubikState::isValid() {
    return false;
}

bool RubikState::operator==(const State &rhs) const {
    return false;
}

std::string RubikState::toString() {
    return std::string();
}

void printMatrix(int mat[3][3])
{
    // Loop to print the matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <3; j++)
            std::cout << mat[i][j] << " ";
        std::cout << std::endl;
    }
}

RubikState *RubikState::rotU(bool clockwise, int side) {

    //transpose side
    for (int i = 0; i < 3; i++) {
        for(int j=i; j<3; j++){
            int aux = cube[side][i][j];
            cube[side][i][j] = cube[side][j][i];
            cube[side][j][i] = aux;
        }
    }

    //1 pode ser substituido por tamanho da coluna/2 (tirando a parte decimal)
    for(int i=0; i<1; i++){
        for(int j=0; j<3; j++){
            int aux = cube[side][i][j];
            cube[side][i][j] = cube[side][2-i][j];
            cube[side][2-i][j] = aux;
        }
    }

    return nullptr;
}

