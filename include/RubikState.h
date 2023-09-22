//
// Created by patrick on 18/09/23.
//

#ifndef CLASSICAI_RUBIKSTATE_H
#define CLASSICAI_RUBIKSTATE_H
#include <string>
#include "State.h"

class RubikState: public State {

private:


   //0 - yellow (up); 1 - red; 2 - green (front); 3 - orange; 4 - blue; 5 - white (down)
    int cube[6][3][3] = {
            {{0,0,0},{0,0,0},{0,0,0}},
            {{1,1,1},{1,1,1},{1,1,1}},
            {{2,2,2},{2,2,2},{2,2,2}},
            {{3,3,3},{3,3,3},{3,3,3}},
            {{4,4,4},{4,4,4},{4,4,4}},
            {{5,5,5},{5,5,5},{5,5,5}}
    };



public:
    RubikState();
    ~RubikState();
    int getGeneratingRule() const;
    void setGeneratingRule(int generatingRule);
    bool isValid();
    bool operator==(const State &rhs) const;
    std::string toString();
    RubikState* rotU(bool clockwise, int side);

};


#endif //CLASSICAI_STATE_H
