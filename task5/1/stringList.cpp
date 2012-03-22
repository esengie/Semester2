#include "stringList.h"


StringList::~StringList ()
{
    delete next;
}
int StringList::inclusions()
{
    if (this)
        return counter;
    return 0;
}

string StringList::getVal()
{
    return value;
}

StringList* StringList::find(string val)
{
    StringList* tmp = finder(val);
    return tmp->next;
}

StringList* StringList::finder(string val)
{
    StringList* tmp = this;
    while (tmp->next && tmp->next->value.compare(val))
        tmp = tmp->next;
    return tmp;
}

bool StringList::deleteVal(string val)
{
    StringList* tmp = finder(val);
    if (tmp->next)
    {
        if (tmp->next->counter > 1)
        {
            tmp->next->counter--;
            return true;
        }
        else
        {
            if (current == tmp->next)
                current = tmp;
            StringList* temp = tmp->next;
            tmp->next = tmp->next->next;
            temp->next = NULL;
            delete temp;
            return true;
        }
    }
    return false;
}


void StringList::insertEl(string val)
{
    StringList* tmpx = new StringList;
    tmpx->value = val;
    if (!next)
    {
        current = tmpx;
        next = current;
    }
    else
    {
        current->next = tmpx;
        current = tmpx;
    }
}



void StringList::insert(string val)
{
    StringList* tmp = next;
    if (tmp && (tmp = tmp->find(val)))
    {
        tmp->counter++;
    }
    else
    {
        insertEl(val);
        current->counter = 1;
    }
}


void StringList::print()
{
    StringList* tmp = next;
    while (tmp)
    {
        cout <<'\t' << tmp->value.c_str() << ' ' << tmp->counter << " times " << endl;
        tmp = tmp->next;
    }
    if (!this)
        cout << "empty";
}
