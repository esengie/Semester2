#pragma once
#include "set.h"


template<class T>
class ListSet : public Set<T>
{
public:
    ListSet(): val(0), next(NULL), current(NULL) { }
    ~ListSet();
    bool isEmpty () {return this->next == NULL;}
    ListSet* lookup(T);
    void add(T);
    void deleteVal(T);
private:
    T val;
    ListSet* next;
    ListSet* current;
    ListSet* lookuper(T);

};

template <class Tclass>
ListSet<Tclass>::~ListSet()
{
    delete next;
}
template <class Tclass>
ListSet<Tclass>* ListSet<Tclass>::lookup(Tclass value)
{
    ListSet* tmp = lookuper(value);
    return tmp->next;
}


template <class Tclass>
ListSet<Tclass>* ListSet<Tclass>::lookuper(Tclass value)
{
    ListSet* tmp = this;
    while (tmp->next && tmp->next->val != value)
        tmp = tmp->next;
    return tmp;
}
template <>
ListSet<std::string>* ListSet<std::string>::lookuper(std::string value)
{
    ListSet* tmp = this;
    while (tmp->next && !tmp->next->val.compare(value))
        tmp = tmp->next;
    return tmp;
}

template <class Tclass>
void ListSet<Tclass>::add(Tclass value)
{
    if (!this->lookup(value))
    {
        ListSet* tmpx = new ListSet();
        tmpx->val = value;
        if (!this->next)
        {
            current = tmpx;
            this->next = current;
        }
        else
        {
            current->next = tmpx;
            current = tmpx;
        }
    }
}

template <class Tclass>
void ListSet<Tclass>::deleteVal(Tclass value)
{
    ListSet* tmp = lookuper(value);
    if (tmp->next)
    {
        if (current == tmp->next)
            current = tmp;
        ListSet* temp = tmp->next;
        tmp->next = tmp->next->next;
        temp->next = NULL;
        delete temp;
    }
}
