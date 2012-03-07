#include <iostream>
#include <quickSort.h>
#include <bubbleSort.h>
#include <shitSort.h>

int main()
{
    int a[] = {2, 3, 15, 6, 1};
    Sort* sorter = new BubbleSort();
    sorter->sort(a, 5);
    for (int i = 0; i < 5; i++)
        std::cout << a[i] << " ";

    delete sorter;
    return 0;
}
