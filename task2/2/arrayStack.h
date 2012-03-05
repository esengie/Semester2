#ifndef ArrayStack_H
#define ArrayStack_H

#include "stack.h"


class ArrayStack : public Stack
{
public:
    ArrayStack();
    void push(int val);
    int pop();
private:
    static const int size = 1000;
    int length;
    int buff[size];
};


#endif // ArrayStack_H
