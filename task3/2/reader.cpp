#include "reader.h"

void reader::init(int** a)
{
    for (int i = 0; i < arraylengthi; i++)
        for (int j = 0; j < arraylengthi; j++)
            a[i][j] = 0;
}
void reader::readArray (int a[], int first, int last)
{
    int i = 0;
    for (i = first; i < last; i++)
        std::cin >> a[i];
}
