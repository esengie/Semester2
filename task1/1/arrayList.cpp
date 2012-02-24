#include "arrayList.h"

void swap(int* am, int* bm)
{
    int im = *am;
    *am = *bm;
    *bm = im;
}

void arrayList::add(int val)
{
    if (length < size)
    {
        buff[length] = val;
        length++;
    }
    return;
}

void arrayList::remove(int val)
{
    int i = 0;
    while (i < length && val != buff[i])
    {
        i++;
    }
    if (i == length)
        return;
    while (i < length)
    {
        swap (&buff[i], &buff[i+1]);
        i++;
    }
    length--;
    return;
}

bool arrayList::isIn(int val)
{
    for (int i = 0; i < length; i++)
        if (buff[i] == val)
            return true;
    return false;
}

int arrayList::lentgh()
{
    return length;
}
