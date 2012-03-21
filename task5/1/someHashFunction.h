#ifndef SOMEHASHFUNCTION_H
#define SOMEHASHFUNCTION_H

#include "hashFunction.h"

class SomeHashFunction : public HashFunction
{
public:
    SomeHashFunction(const int LENGTH): HashFunction(LENGTH), kr(1) {}
    int hash(std::string);
private:
    int realFunc(char, int);
    long long kr;
};

#endif // SOMEHASHFUNCTION_H
