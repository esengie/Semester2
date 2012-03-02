#ifndef SORT_H
#define SORT_H

class Sort
{
public:
    virtual int* sort(int*, int) = 0;
protected:
    static void swap (int& a, int& b)
    {
        int i = a;
        a = b;
        b = i;
    }
};

#endif // SORT_H

