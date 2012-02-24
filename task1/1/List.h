#ifndef LIST_H
#define LIST_H


class List
{
public:
    virtual void add(int val) = 0;
    virtual void remove(int val) = 0;
    virtual bool isIn(int val) = 0;
    virtual int lentgh() = 0;
};

#endif // LIST_H
