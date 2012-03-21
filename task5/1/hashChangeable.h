#ifndef HASHCHANGEABLE_H
#define HASHCHANGEABLE_H

#include "hash.h"


class HashChangeable : public Hash
{
public:
    HashChangeable(HashFunction* temp, const int LENGTH = 2500);
    ~HashChangeable();
    void insert(std::string);
    bool lookup(std::string);
    int elementsQuantity();
    void deleteValue(std::string);
    /**
      \warning hash function must not have wider range than ARRAYLENGTH
      */                                                               // because i didn't want to create exceptions and yada yada
    virtual void changeFunction(HashFunction*);
private:
    const int ARRAYLENGTH;
    StringList** hashe;
    int quantity;

};

#endif // HASHCHANGEABLE_H
