#include "arrayStack.h"

void arrayStack::push(int val)
{
    if (length < size)
    {
        buff[length] = val;
        length++;
    }
    return;
}

int arrayStack::pop()
{
    return buff[length--];
}

