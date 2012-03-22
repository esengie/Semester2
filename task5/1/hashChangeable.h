#ifndef HASHCHANGEABLE_H
#define HASHCHANGEABLE_H

#include "hash.h"

class HashChangeableTest;

class HashChangeable : public Hash
{
friend class HashChangeableTest;
public:
    HashChangeable(HashFunction* temp, const int LENGTH = 2500);
    ~HashChangeable();
    void insert(std::string);
    bool lookup(std::string);
    int elementsQuantity();
    void deleteValue(std::string);
    /**
      \warning hash function must not have wider range than arraylength
      */                                                               // because i didn't want to create exceptions and yada yada
    virtual void changeFunction(HashFunction*);
protected:
    const int ARRAYLENGTH;
    StringList** hashe;
    int quantity;

};

#endif // HASHCHANGEABLE_H
