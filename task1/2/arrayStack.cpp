#include "arrayStack.h"

ArrayStack::ArrayStack()
{
    length = 0;
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
    return buff[length--];
}

