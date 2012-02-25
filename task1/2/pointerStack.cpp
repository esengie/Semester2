#include "pointerStack.h"

void pointerStack::push(int val)
{
    pointerStack* temp = new pointerStack;
    temp->value = val;
    temp->next = next;
    next = temp;
    return;
}

int pointerStack::pop()
{
    pointerStack* temp = next;
    int ollie = 0;
    if (temp->next)
    {
        next = next->next;
        ollie = temp->value;
        temp->next = 0;
        delete temp;
    }
    return ollie;
}
