#ifndef SHITSORT_H
#define SHITSORT_H
#include "sort.h"

class ShitSort : public Sort
{
public:
    int* sort(int*, int);
private:
    static int* sortHelper(int*, int, int);
};

#endif // SHITSORT_H
