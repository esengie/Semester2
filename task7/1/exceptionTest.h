#pragma once
#include "iostream"
#include <string>
#include <stdexcept>

class ExceptionTest
{
public:
    class Exception {};
    ExceptionTest()
    {
        std::cout << "I'm Aliiiive" << std::endl;
    }
    ~ExceptionTest()
    {
        std::cout << "I'm deeeaaaaaaaaad!!!!!" << std::endl;
    }
    void Snide()
    {
        throw std::logic_error("sdf");
    }
};
