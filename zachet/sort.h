#ifndef SORT_H
#define SORT_H
#include "comparer.h"
#include <algorithm>


template<class Y, class T, class Comp = Comparer<T> >
class Sorter
{
public:
    //(Comp eq): cmp(eq) {}
    explicit Sorter(Y begin, Y end)
    {
        Y it = begin;

        Comp cmp;
        while (it != end)
        {
            Y it2 = begin;
            while(it2 != end)
            {
                if (cmp(*it, *it2))
                    qSwap(*it, *it2);
                it2++;
            }
            it++;
        }
    }

};

#endif // SORT_H
