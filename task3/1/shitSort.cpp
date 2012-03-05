#include "shitSort.h"

int* ShitSort::sort(int* array, int length)
{
    return ShitSort::sortHelper(array, 0, length - 1);
}

int* ShitSort::sortHelper(int* array, int i, int j)
{
    if (array[j] < array[i])
    {
        swap(array[i], array[j]);
    }
    if ((j - i + 1) >= 3)
    {
        int t = (j - i + 1) / 3;
        sortHelper(array, i, j - t);
        sortHelper(array, i + t, j);
        sortHelper(array, i, j - t);
    }
    return array;
}
