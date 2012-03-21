#include "someHashFunction.h"

int SomeHashFunction::hash(std::string h)
{
    int j = 0;
    std::string::iterator i = h.begin();
    while (i < h.end())
    {
        j += realFunc( *i, j);
        i++;
    }
    kr = 1;
    j %= ARRAYLENGTH;
    return j;
}

int SomeHashFunction::realFunc (char ch, int j)
{
    j = ((int (ch)) * kr) % ARRAYLENGTH;
    kr *= 11;
    return j;
}

