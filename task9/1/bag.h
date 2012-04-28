#pragma once
#include <set>
#include <iterator>
#include "bagTest.h"


/** Bag (multiset)

    \sa http://www.cplusplus.com/reference/stl/multiset/
    */

template<class T>
class Bag
{
    class iterator
    {
    public:
        iterator() : mIt(mMultiSet.begin()) {}
        iterator(const iterator& it) : mIt(it.mIt) {}
        iterator(const typename std::multiset<T>::iterator& it) : mIt(it) {}
        iterator& operator=(const iterator& it) { mIt = it.mIt; return mIt; }
        T operator*() { return *mIt; }
        iterator& operator++();
        const iterator operator++(int);
    private:
        typename std::multiset<T>::iterator mIt;
    };
private:
    std::multiset<T> mMultiSet;
    friend class BagTest;
public:
    // typedef typename multiset<T>
   /* Bag(const& Bag) const {}
    Bag& operator=(const& Bag) const {}
    ~Bag(){ } */
    bool isEmpty() const { return mMultiSet.empty();}
    void insert(const T&);
    void erase(const T&);
    void eraseAll(const T&);
    bool find(const T&) const;
    int quantity(const T&) const;
    void clear();
    iterator begin() { return iterator(mMultiset.begin()); }
    iterator end() { return iterator(mMultiset.end()); }

};

template<class T>
typename Bag<T>::iterator& operator++()
{
    return ++mIt;
}
template<class T>
const typename Bag<T>::iterator operator++(int)
{
    return mIt++;
}

template<class T> inline
void Bag<T>::insert(const T& val)
{
    mMultiSet.insert(val);
}

template<class T> inline
void Bag<T>::erase(const T& val)
{
    typename std::multiset<T>::iterator it = mMultiSet.find(val);
    mMultiSet.erase(it);
}
template<class T> inline
void Bag<T>::eraseAll(const T& val)
{
    mMultiSet.erase(val);
}

template<class T> inline
void Bag<T>::clear()
{
    mMultiSet.clear();
}

template<class T> inline
int Bag<T>::quantity(const T& val) const
{
    return (int) mMultiSet.count(val);
}

template<class T> inline
bool Bag<T>::find(const T& val) const
{
    return mMultiSet.end() != mMultiSet.find(val);
}
