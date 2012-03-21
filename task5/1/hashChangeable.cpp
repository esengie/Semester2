#include "hashChangeable.h"

HashChangeable::HashChangeable(HashFunction* temp, const int LENGTH): Hash(temp), ARRAYLENGTH(LENGTH)
{
    hashe = new StringList*[ARRAYLENGTH];
    quantity = 0;
    for (int i = 0; i < ARRAYLENGTH; i++)
        hashe[i] = new StringList;
}
HashChangeable::~HashChangeable()
{
    for (int i = 0; i < ARRAYLENGTH; i++)
        delete hashe[i];
}

void HashChangeable::changeFunction(HashFunction * fHasher)
{
    //HashFunction::ARRAYLENGTH = ARRAYLENGTH;
    hasher = fHasher;
}

int HashChangeable::elementsQuantity()
{
    return quantity;
}

void HashChangeable::insert(std::string h)
{
    hashe[hasher->hash(h)]->insert(h);
    quantity++;
}

void HashChangeable::deleteValue(std::string h)
{
    if (hashe[hasher->hash(h)]->deleteVal(h))
        quantity--;
}

bool HashChangeable::lookup(std::string h)
{
    return hashe[hasher->hash(h)]->find(h);
}
