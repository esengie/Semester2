
#include "reader.h"
#include "filePrinter.h"
#include "consolePrinter.h"

using namespace reader;
int main()
{
    int length = 0;
    int** arr = new int*[arraylengthi];
    for (int i = 0; i < arraylengthi; i++)
    {
        arr[i] = new int[arraylengthi];
    }

    init(arr);
    std::cout << "Please specify n" << std::endl;
    std::cin >> length;
    for (int i = 0; i < length; i++)
    {
        readArray(arr[i], 0, length);
    }

    std::cout << "Specify if you waant your output on console of file (1 or 0)" << std::endl;
    bool f = true;
    std::cin >> f;
    Printer* spiraller;
    if (f)
        spiraller = new ConsolePrinter;
    else
        spiraller = new FilePrinter;

    spiraller->print(arr, length);



    for (int i = 0; i < arraylengthi; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete spiraller;

    return 0;
}


