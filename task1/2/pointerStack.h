#ifndef PointerStack_H
#define PointerStack_H

#include "stack.h"

class PointerStack : public Stack
{
public:
    PointerStack();
    void push(int val);
    int pop();
    ~PointerStack();
private:
    PointerStack* next;
    int  value;
};

#endif // PointerStack_H
