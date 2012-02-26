#include "arrayStack.h"

ArrayStack::ArrayStack()
{
    length = 1;
}

void ArrayStack::push(int val)
{
    if (length < size)
    {
        buff[length] = val;
        length++;
    }
    return;
}

int ArrayStack::pop()
{
    if (length)
        return buff[--length];
    return 0;
}

