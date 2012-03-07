#include "sort.h"

void Sort::swap(int*& a, int*& b)
{
    int* i = a;
    a = b;
    b = i;
}

