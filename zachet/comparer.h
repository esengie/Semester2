#ifndef COMPARER_H
#define COMPARER_H
template <class T>
class Comparer
{
public:
    bool operator()(const T& ob1,const T& ob2)
    {
        if (ob1 < ob2)
            return true;
        return false;
    }
};

#endif // COMPARER_H
