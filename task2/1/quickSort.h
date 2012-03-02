#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "sort.h"

class QuickSort : public Sort
{
public:
    int* sort(int*, int);
private:
    static void sortHelper(int*, int, int);
};

#endif // QUICKSORT_H
