#pragma once 
#include "string.h"
#include "iostream"
using namespace std;
/// String List without a guardian

class StringList
{
public:
    StringList (): next(NULL), current(this), counter(0), value("") {}
    ~StringList ();
    /** Inserts string into the List

        If it is already in it just increases the counter by one
        otherwise COPIES a string and puts it in the end
      */
    void insert(string h);
    /** Gets the first element from a List

        deletes it from the list, returns NULL if it is empty
      */
    string getVal();
    /** Returns value of element
      */
    StringList* find (string h);
    /** Deletes a string from the list

        \return true if deleted, false if element not found
      */
    bool deleteVal(string h);
    /// Returns counter
    int inclusions();
    /// Prints the List (redundant)
    void print();
    StringList* next;    ///< too lazy to write an iterator, sorry
private:    
    StringList* current; ///< Almost useless element, should have created a Guardian class to hold it, now it's as if every element is a list
    int counter;
    string value;
    void insertEl (string h);
    StringList* finder(string h);


};
