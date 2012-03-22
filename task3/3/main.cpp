#include <quickSort.h>
#include <iostream>
#include <stdio.h>
const int SIZE = 1000;

int main()
{
    Sort* sorter = new QuickSort();
    int** array = new int*[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = new int[SIZE];
    }


    int n = 0;
    int m = 0;

    std::cout << "Write n and m" << std::endl;
    std::cin >> n >> m;
    std::cout << "Write a matrix " << n << "X" << m << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> array[j][i];
        }
    }


    sorter->sort(array, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << array[j][i] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < SIZE; i++)
    {
        delete [] array[i];
    }

    delete sorter;
    delete [] array;
    return 0;
}
