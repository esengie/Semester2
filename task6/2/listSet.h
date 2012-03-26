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
    void intersect(Set<T>*);
    void unite(Set<T>*);
private:
    static bool isEqual(const T&, const T&);
    T val;
    ListSet* next;
    ListSet* current;
    ListSet* lookuper(T);

};

template <>
inline ListSet<std::string>::ListSet(): val(""), next(NULL), current(NULL)
{}


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
    while (tmp->next && !isEqual(tmp->next->val, value))
        tmp = tmp->next;
    return tmp;
}

template <class Tclass>
bool ListSet<Tclass>::isEqual(const Tclass& value, const Tclass& value2)
{
    return value == value2;
}

template <>
bool ListSet<std::string>::isEqual(const std::string& value, const std::string& value2)
{
    return !value.compare(value2);
}

template <class Tclass>
void ListSet<Tclass>::intersect(Set<Tclass>* inters)
{
    ListSet<Tclass>* tmp = this->next;
    while (tmp)
    {
        ListSet<Tclass>* temp = 0;
        if (!inters->lookup(tmp->val))
        {
            temp = tmp;
            tmp = tmp->next;
            this->deleteVal(temp->val);
        }
        else
        {
            tmp=tmp->next;
        }

    }
}


template <class Tclass>
void ListSet<Tclass>::unite(Set<Tclass>* inters)
{

    ListSet<Tclass>* tmp = this->next;

    while (tmp)
    {
        Set<Tclass>* temp = inters->lookup(tmp->val);
        if (!temp)
        {
            inters->add(tmp->val);
        }
        tmp = tmp->next;
    }
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
