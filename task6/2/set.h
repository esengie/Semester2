#ifndef SET_H
#define SET_H
#include <string>

template <class T>
class Set
{
public:
    virtual ~Set() {}
    virtual void add(T) = 0;
    virtual Set* lookup(T) = 0;
    virtual void deleteVal(T) = 0;
    virtual bool isEmpty() = 0;
    virtual void intersect(Set<T>*) = 0;
    virtual void unite(Set<T>*) = 0;
};

#endif // SET_H
