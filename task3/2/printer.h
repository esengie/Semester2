#ifndef TYPER_H
#define TYPER_H

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
    static void spiral(int**, int);
};

#endif // TYPER_H
