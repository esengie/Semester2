#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "sort.h"

/// Recursive quicksort.

/// \sa http://en.wikipedia.org/wiki/Quicksort#Simple_version

class QuickSort : public Sort
{
public:
    int* sort(int*, int);
private:
    /// actual sorter.
    /** \param array takes an array
        \param first takes first element of an array
        \param last takes last element of an array
    */
    static void sortHelper(int* array, int first, int last);
};

#endif // QUICKSORT_H
