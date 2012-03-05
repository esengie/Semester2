#include <iostream>
#include <calculator.h>
//#include <stack.h>

int main()
{
    std::cout << "Welcome, please specify if you want to use stdin or other input resourses (0 or 1)" << std::endl;
    int i = 0;
    std::cin >> i;
    std::cout << calculate(i) << std::endl;
    return 0;
}
