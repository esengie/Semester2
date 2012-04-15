#pragma once
#include <vector>
#include <string>
#include <algorithm>
using std::vector;


template<class T>
class Vector
{
    typedef typename vector<T>::size_type vec_sz;
    typedef typename std::vector<T>::const_iterator const_it;
    class VectorsMismatch{};
    class StringError {};
public:
    Vector(vec_sz n): size(n) { vector<T> values(0, int(n - 1)); }
    Vector(const Vector<T>& th): size(th.size), values(th.values){}

    Vector(const vector<T>& th): size(th.size()), values(th.begin(), th.end()) {}
    ~Vector(){ }
    bool isNull () const { return (values.end() == std::find_if(values.begin(), values.end(), nonZero));}
    Vector operator+(const Vector<T>&) const;
    Vector operator*(const Vector<T>&) const;
    Vector& operator=(const Vector<T>&);
    T scalar(const Vector<T>&) const;

private:
    vec_sz size;
    vector<T> values;
    static bool nonZero(T f) {return f;}
};


template<class T>
Vector<T> Vector<T>::operator+(const Vector<T>& leftHand) const
{
    if (this->isNull() || leftHand.isNull())
        return (!this->isNull()? *this : leftHand);
    if (this->size != leftHand.size)
        throw VectorsMismatch();
    Vector<T> ret(this->size);
    for (vec_sz i = 0; i != this->size; i++)
    {
        ret.values.push_back(this->values[i] + leftHand.values[i]);
    }
    return ret;
}
template<> inline
Vector<std::string> Vector<std::string>::operator*(const Vector<std::string>& leftHand) const
{
    throw StringError();
}

template<class T>
Vector<T> Vector<T>::operator*(const Vector<T>& leftHand) const
{
    if (this->isNull() || leftHand.isNull())
        return (this->isNull()? &this : leftHand);
    if (this->size != leftHand.size)
        throw VectorsMismatch();
    Vector<T> ret(this->size);
    for (vec_sz i = 0; i != this->size; i++)
    {
        ret.values.push_back(this->values[i] * leftHand.values[i]);
    }
    return ret;
}


template<class T>
T Vector<T>::scalar(const Vector<T>& leftHand) const
{
    if (this->size != leftHand.size)
        throw VectorsMismatch();
    T ret = 0;
    const_it it = values.begin();
    const_it itLeft = leftHand.values.begin();
    while (it != values.end())
    {
        ret += (*it)*(*itLeft);
        ++it;
        ++itLeft;
    }
    return ret;
}

template <> inline
std::string Vector<std::string>::scalar(const Vector<std::string>& leftHand) const
{
    throw StringError();
}
