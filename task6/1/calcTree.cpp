#include "calcTree.h"
#include <stdexcept>
using std::string;
using std::cout;

Operation::Operation (string& s)
{
    if (s.begin() != s.end())
    {
        operand = s[1];
        s.erase(0, 2);
        left = build(s);
        right = build(s);
        s.erase(0, 1);
    }
}

CalcTree* Operation::build(string& s)
{
    while (s[0] == ' ')
        s.erase(0, 1);
    if (s.begin() != s.end())
    {
        CalcTree* tmp = 0;
        if (s[0] == '(')
                tmp = new Operation(s);
        else
                tmp = new Leaf(s);
        return tmp;
    }
    return NULL;
}


int Operation::result(void) const
{
    switch (operand)
    {                                                        
        case '+':
            return left->result() + right->result();
            break;
        case '-':
            return left->result() - right->result();
            break;
        case '*':
            return left->result() * right->result();
            break;
        case '/':
            return left->result() / right->result();
            break;
        default:
            throw std::invalid_argument("No fare, what's wrong with you people?!");
            break;
    }
}

void Operation::print(void) const
{
    cout << '(' << operand;
    left->print();
    right->print();
    cout << ')';
}


