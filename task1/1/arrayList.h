#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "List.h"

const int size = 1000;

class arrayList : public List
{
public:
    arrayList(): length(0){}
    void add(int val);
    void remove(int val);
    bool isIn(int val);
    int lentgh();
private:
    int length;
    int buff[size];
};


#endif // ARRAYLIST_H
