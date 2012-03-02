#include "quickSort.h"

int* QuickSort::sort(int* array,int length)
{
    sortHelper(array, 0, length - 1);
    return array;
}

void QuickSort::sortHelper(int* array, int first, int last)
{
    if (first < last)
    {
        int i = first + 1;
        int j = last;
        int mediane = array[(first + last) / 2];
        swap (array[(first+last) / 2], array[first]);
        while (i <= j)
        {
            while (array[i] <= mediane && i <= last )
                i++;
            while (array[j] > mediane && j >= first)
                j--;
            if (i<j)
                swap (array[i], array[j]);
        }
        swap(array[j], array[first]);
        sortHelper (array, first, j - 1);
        sortHelper (array, j + 1, last);
    }

}
