#ifndef pointerStack_H
#define pointerStack_H

#include "Stack.h"

class pointerStack : public Stack
{
public:
    pointerStack(): next(0), value(0){ }
    void push(int val);
    int pop();
    ~pointerStack() {delete next;}
private:
    pointerStack* next;
    int  value;
};

#endif // pointerStack_H
