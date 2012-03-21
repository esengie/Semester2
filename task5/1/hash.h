#ifndef HASH_H
#define HASH_H

#include "string"
#include "hashFunction.h"
#include "stringList.h"

/// Hash interface

class Hash
{
public:
    Hash(HashFunction* temp): hasher(temp){}
    virtual ~Hash () {}
    /** Takes std::string inserts it into hash */
    virtual void insert(std::string) = 0;
    /** Finds a string in a hash

        \return true if found
      */
    virtual bool lookup(std::string) = 0;
    /** Deletes value if found */
    virtual void deleteValue(std::string) = 0;
    /**
        \return element Quantity
      */
    virtual int elementsQuantity() = 0;
    /** Changes a hash function

      */
    virtual void changeFunction(HashFunction*) = 0;
protected:
    HashFunction* hasher; ///< hash function
};

#endif // HASH_H
