#pragma once
#include <vector>
#include <string>
#include <algorithm>


template<class T>
class Vector
{
    typedef typename std::vector<T>::size_type vec_sz;
    typedef typename std::vector<T>::const_iterator const_it;
    class VectorsMismatch{};
    class StringError {};
public:
    Vector(vec_sz n): size(n) { std::vector<T> values(int(n - 1), 0); }     ///< init with n zeroes
    Vector(const Vector<T>& th): size(th.size), values(th.values.begin(), th.values.end()) {}  ///< copying constructor
    Vector(const std::vector<T>& th): size(th.size()), values(th.begin(), th.end()) {}  ///< copying from std::vector
    ~Vector(){ }
    bool isNull () const { return (values.end() == std::find_if(values.begin(), values.end(), nonZero));}
    Vector operator+ (const Vector<T>&) const;
    Vector operator- (const Vector<T>&) const;
    Vector operator= (const Vector<T>&);
    T scalar(const Vector<T>&) const;

private:
    vec_sz size;
    std::vector<T> values;
    static bool nonZero(T f) {return f;}
};
template <> inline
bool Vector<std::string>::nonZero(std::string f) { return f.empty(); }


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
Vector<std::string> Vector<std::string>::operator-(const Vector<std::string>& leftHand) const
{
    throw StringError();
}

template<class T>
Vector<T> Vector<T>::operator-(const Vector<T>& leftHand) const
{
    if (this->isNull() || leftHand.isNull())
        return (this->isNull()? leftHand : *this);
    if (this->size != leftHand.size)
        throw VectorsMismatch();
    Vector<T> ret(this->size);
    for (vec_sz i = 0; i != this->size; i++)
    {
        ret.values.push_back(this->values[i] - leftHand.values[i]);
    }
    return ret;
}

template<class T>
Vector<T> Vector<T>::operator=(const Vector<T>& right)
{
    values.clear();
    size = right.size;
    values = std::vector<T>(right.values.begin(),right.values.end());
    return *this;
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
Vector<std::string>::Vector(vec_sz n): size(n)
{
    std::string k = "";
    std::vector<std::string> values(int(n - 1), k);
}

template <> inline
std::string Vector<std::string>::scalar(const Vector<std::string>& leftHand) const
{
    throw StringError();
}
