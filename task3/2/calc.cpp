#include "calc.h"

void Calc::left(int a)
{
    left_ = a;
    calc();
}

void Calc::right(int a)
{
    right_ = a;
    calc();
}

void Calc::oper(const QString s)
{
    oper_ = s.toAscii().data()[0];
    calc();
}

void Calc::calc()
{

    if (!(!right_ && oper_ != '/'))
    {
        int temp = operate(left_, oper_, right_);
        QString text = QString::number(temp);
        emit value(text);
    }
}


int Calc::operate(int left, char sym, int right)
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
