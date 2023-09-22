//
// Created by patrick on 18/09/23.
//

#ifndef CLASSICAI_STATE_H
#define CLASSICAI_STATE_H
#include <string>

class State {

public:
    virtual int getGeneratingRule() const=0;
    virtual void setGeneratingRule(int generatingRule)=0;
    virtual bool isValid()=0;
    virtual bool operator==(const State &rhs) const=0;
    virtual std::string toString()=0;

};


#endif //CLASSICAI_STATE_H
