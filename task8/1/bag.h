#pragma once
#include <set>



/** Bag (multiset)

    \sa http://www.cplusplus.com/reference/stl/multiset/
    */

template<class T>
class Bag
{
public:
    ~Bag(){ }
    bool isEmpty() const { return mMultiSet.empty();}
    void insert(const T&);
    void erase(const T&);
    void eraseAll(const T&);
    bool find(const T&) const;
    int quantity(const T&) const;
    void clear();
private:
    std::multiset<T> mMultiSet;
};




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
