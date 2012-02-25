#ifndef arrayStack_H
#define arrayStack_H

#include "Stack.h"

const int size = 1000;

class arrayStack : public Stack
{
public:
    arrayStack(): length(0){}
    void push(int val);
    int pop();
private:
    int length;
    int buff[size];
};


#endif // arrayStack_H
