#include "pointerStack.h"


PointerStack::PointerStack()
{
    next = 0;
    value = 0;
}

PointerStack::~PointerStack()
{
    delete next;
}

void PointerStack::push(int val)
{
    PointerStack* temp = new PointerStack;
    temp->value = val;
    temp->next = next;
    next = temp;
}

int PointerStack::pop()
{
    PointerStack* temp = next;
    int ollie = 0;
    if (temp)
    {
        next = next->next;
        ollie = temp->value;
        temp->next = 0;
        delete temp;
    }
    return ollie;
}
