#include "filePrinter.h"
#include <iostream>
#include <string>
#include <fstream>

void FilePrinter::print(int** array, int length)
{
  /*  std::string h;
    std::cout << "Specify filename to print into" << std::endl;
    std::cin >> h;
    std::streambuf *psbuf, *backup;
    std::ofstream filestr;
    filestr.open(h.c_str());
    backup = std::cout.rdbuf();     // back up cout's streambuf
    psbuf = filestr.rdbuf();   // get file's streambuf
    std::cout.rdbuf(psbuf);         // assign streambuf to cout
*/    spiral(array, length);
  //  std::cout.rdbuf(backup);        // restore cout's original streambuf
  //  filestr.close();
}
