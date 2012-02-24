#ifndef POINTERLIST_H
#define POINTERLIST_H

#include "List.h"

class pointerList : public List
{
public:
    pointerList(): next(0), value(0){ }
    void add(int val);
    void remove(int val);
    bool isIn(int val);
    int lentgh();
    ~pointerList() {delete next;}
private:
    pointerList* next;
    int  value;
};

#endif // POINTERLIST_H
