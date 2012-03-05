#include "filePrinter.h"
#include <iostream>
#include <string>
#include <stdio.h>

void FilePrinter::print(int** array, int length)
{
    std::string h;
    std::cout << "Specify filename to print into" << std::endl;
    std::cin >> h;
    freopen(h.c_str(), "rw", stdout);
    spiral(array, length);
    fclose(stdout);
}
