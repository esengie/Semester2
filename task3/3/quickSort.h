#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "sort.h"

/** Recursive quicksort.

    \sa http://en.wikipedia.org/wiki/Quicksort#Simple_version
*/

class QuickSort : public Sort
{
public:
    /// calls sortHelper
    int** sort(int**, int);
private:
    /** actual sorter.

        \param array takes an array of arrays
        \param first takes first index of an array
        \param last takes last index of an array
    */
    static void sortHelper(int** array, int first, int last);
};

#endif // QUICKSORT_H
