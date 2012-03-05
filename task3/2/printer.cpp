#include "printer.h"
#include <iostream>

void Printer::spiral(int** s, int n)
{
    int i = 0;
    int k = 0;

    while (i < n * n)
    {
        for (int j = k; j < n - k - 1; j++)
        {
            i++;
            std::cout<< s[k][j] << " ";
        }

        for (int j = k; j < n - k - 1; j++)
        {
            i++;
            std::cout << s[j][n - k - 1] << " ";
        }

        for (int j = n - k - 1; j >= k; j--)
        {
            i++;
            std::cout << s[n - k - 1][j] << " ";
        }

        for (int j = n - k - 2; j > k; j--)
        {
            i++;
            std::cout << s[j][k] << " ";
        }
        k++;
    }
}

