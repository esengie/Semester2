#include "calculator.h"
#include <arrayStack.h>
#include <pointerStack.h>
#include <stdio.h>
#include <string>
#include <iostream>

bool isNumber(char ch)
{
    return (ch <= '9' && ch >= '0');
}

int operate(char sym, Stack*& stack)
{
    int right = stack->pop();
    int left = stack->pop();
    switch (sym)
    {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
    }
    return right;
}

int calculate(int n)
{
    if (n == 1)
    {
        std::string h = "";
        std::cout << "Specify the filename" << std::endl;
        std::cin >> h;
        freopen(h.c_str(), "rw", stdin);
    }
    std::cout << "Please enter the expression you want calculated and end it with" << std::endl;

    int result = 0;
    Stack* stack = new PointerStack();
    char ch = ' ';

    while(std::cin)
    {
        int i = 0;
        bool isNum = false;
        ch = std::cin.get();

        while (ch == '\n' || ch == ' ')
        {
            ch = std::cin.get();
        }
        if (isNumber(ch))
        {
            do
            {
                isNum = true;
                i = i * 10 + ch - '0';
                ch = std::cin.get();
            }
            while (std::cin && isNumber(ch));
        }
        if (isNum)
        {
            stack->push(i);
            std::cin.putback(ch);
        }
        else
            if (std::cin)
            {
                result = operate(ch, stack);
                stack->push(result);
            }
    }
    result = stack->pop();
    delete stack;
    return result;
}
