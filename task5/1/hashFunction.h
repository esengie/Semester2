#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H

#include "string"
/// Hash Function Interface

class HashFunction
{
public:
    virtual ~HashFunction() {}
    HashFunction (const int LENGTH = 2500): ARRAYLENGTH(LENGTH) {}
    /// Hash function takes a std::string
    virtual int hash(std::string) = 0;
    const int ARRAYLENGTH;
};

#endif // HASHFUNCTION_H
