#include "printer.h"


void Printer::spiral(int** s, int n, std::ostream& cyfn)
{
    int i = 0;
    int k = 0;

    while (i < n * n)
    {
        for (int j = k; j < n - k - 1; j++)
        {
            i++;
            cyfn << s[k][j] << " ";
        }

        for (int j = k; j < n - k - 1; j++)
        {
            i++;
            cyfn << s[j][n - k - 1] << " ";
        }

        for (int j = n - k - 1; j >= k; j--)
        {
            i++;
            cyfn << s[n - k - 1][j] << " ";
        }

        for (int j = n - k - 2; j > k; j--)
        {
            i++;
            cyfn << s[j][k] << " ";
        }
        k++;
    }
}

