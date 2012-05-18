#include "sort.h"
#include <iostream>
#include "QList"
int main()
{

    QList<int> abc;
    abc.append(int(345));
    abc.append(int(35));
    abc.append(int(34));
    abc.append(int(45));
    abc.append(int(645));
    abc.append(int(145));
    Sorter<QList<int>::Iterator, int>(abc.begin(), abc.end());
    QList<int>::iterator it = abc.begin();
    while (it != abc.end())
    {
        std::cout << *it << " ";
        it++;
    }

}
