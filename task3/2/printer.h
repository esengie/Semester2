#ifndef TYPER_H
#define TYPER_H


#include <iostream>

/// Virtual typer class


class Printer
{
public:
    /** typer fucntion
      \param int** a square matrix
      \param int the size of it
    */
    void virtual print(int**, int) = 0;
protected:
    static void spiral(int**, int, std::ostream& = std::cout);
};

#endif // TYPER_H
