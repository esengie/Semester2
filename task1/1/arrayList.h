#ifndef ArrayList_H
#define ArrayList_H

#include "list.h"



class ArrayList : public List
{
public:
    ArrayList();
    void add(int val);
    void remove(int val);
    bool isIn(int val);
    int length();
private:
    static const int size = 1000;
    int lengthi;
    int buff[size];

};


#endif // ArrayList_H
