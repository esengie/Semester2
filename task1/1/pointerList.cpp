#include "pointerList.h"

void pointerList::add(int val)
{
    pointerList* temp = new pointerList;
    temp->value = val;
    if (!next)
        next = temp;
    else
    {
        temp->next = next;
        next = temp;
    }
    return;
}

void pointerList::remove(int val)
{
    pointerList* temp = this;
    while(temp->next && temp->next->value != val)
        temp = temp->next;
    if (temp->next && temp->next->value == val)
    {
        pointerList* tmp = temp->next;
        temp->next = temp->next->next;
        tmp->next = 0;
        delete tmp;
    }
    return;
}

bool pointerList::isIn(int val)
{
    pointerList* temp = next;
    while (temp)
    {
        if (temp->value == val)
            return true;
        temp = temp->next;
    }
    return false;
}

int pointerList::lentgh()
{
    int length = 0;
    pointerList* temp = next;
    while (temp)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

