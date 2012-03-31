#ifndef EXCEPTIONALSET_H
#define EXCEPTIONALSET_H

#include "listSet.h"

template<class T>
class ExceptionalSet : public ListSet<T>
{
public:
    class DeleteFromEmpty {};
    class AddExisting {};
    void deleteVal(T);
    void add(T);

};
template <class Tclass>
void ExceptionalSet<Tclass>::deleteVal(Tclass value)
{
    if (!ListSet<Tclass>::lookup(value))
        throw ExceptionalSet::DeleteFromEmpty();
    ListSet<Tclass>::deleteVal(value);
}
template <class Tclass>
void ExceptionalSet<Tclass>::add(Tclass value)
{
    if (ListSet<Tclass>::lookup(value))
        throw ExceptionalSet::AddExisting();
    ListSet<Tclass>::add(value);
}

#endif // EXCEPTIONALSET_H
