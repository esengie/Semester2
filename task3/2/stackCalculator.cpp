#include "stackCalculator.h"

int StackCalculator::operate(int left, char sym, int right)
{
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
    return 0;
}
