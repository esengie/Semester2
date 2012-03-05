#include "stackCalculator.h"

void StackCalculator::left(int a)
{
    m_left = a;
    calc();
}

void StackCalculator::right(int a)
{
    m_right = a;
    calc();
}

void StackCalculator::oper(const QString s)
{
    m_oper = s.toAscii().data()[0];
    calc();
}

void StackCalculator::calc()
{

    if (m_right || m_oper != '/')
    {
        int temp = operate(m_left, m_oper, m_right);
        QString text = QString::number(temp);
        emit value(text);
    }
}


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
