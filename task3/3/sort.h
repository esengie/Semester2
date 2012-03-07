#ifndef SORT_H
#define SORT_H


/// Interface for Sorter

class Sort
{
public:
/** Virtual sorter

    Sorter function interface
    \param matrix an array of arrays passed to the sorter
    \param length length of the array passed
    \return pointer to sorted (initial) array
*/
    virtual int** sort(int** array, int length) = 0;
    virtual ~Sort() {}
protected:
/** just an integer swap procedure.

    takes two integer pointers by a reference and swaps them with the use of third initialised integer pointer
*/
    static void swap (int*& a, int*& b);
};

#endif // SORT_H

