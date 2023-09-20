//
// Created by patrick on 18/09/23.
//

#ifndef CLASSICAI_STATE_H
#define CLASSICAI_STATE_H
#include <string>

class State {
    private:
    static int NEXT_ID;
    int innerVector[7]; // 0-2: males, 3-5: females. 6: boat. 0 means on hotel, 1 means safe.
    int hotelMales = innerVector[0];
    int hotelFemales = innerVector[3];
    int hotelBoat = innerVector[6];
    int safeMales = innerVector[7];
    int safeFemales = innerVector[10];
    int safeBoat = innerVector[13];
    int id;
    int generatingRule;
public:
    int getGeneratingRule() const;

    void setGeneratingRule(int generatingRule);

public:
    State(int innerVector[14]);
    State();

    State(int h1, int h2, int h3, int m1, int m2, int m3, int b);
    int* getInnerVector();
    bool isValid();
    void move(int passenger);
    void auxMove(int passenger);
    void move(int passenger1, int passenger2);
    void copyVector(State* state);
    State* tryGenerateStateMoving(int passenger);
    State* tryGenerateStateMoving(int passenger1, int passenger2);
    bool canMove(int passenger1);
    bool canMove(int passenger1, int passenger2);
    bool operator==(const State &rhs) const;
    std::string toStringWithRule();
    std::string toString();

};


#endif //CLASSICAI_STATE_H
