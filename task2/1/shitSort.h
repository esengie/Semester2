#ifndef SHITSORT_H
#define SHITSORT_H
#include "sort.h"

/// Stooge sort at its finest (recursive)

/// \sa http://en.wikipedia.org/wiki/Stooge_sort

class ShitSort : public Sort
{
public:
    int* sort(int*, int);
private:
    /// actual sorter.
    /** \param array takes an array
        \param first takes first element of an array
        \param last takes last element of an array
    */
    static int* sortHelper(int* array, int first, int last);
};

#endif // SHITSORT_H
