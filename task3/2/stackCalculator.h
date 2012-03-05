#ifndef CALC_H
#define CALC_H

#include <QString>
#include <QWidget>

class StackCalculator : public QWidget
{
    Q_OBJECT
public:
    StackCalculator(): QWidget(), m_left(0), m_oper('+'), m_right(0)
    { }
signals:
    void value(QString);
public slots:
    void left(int);
    void oper(QString);
    void right(int);
private:
    //static const int size = 0;

    int m_left;
    char m_oper;
    int m_right;

    void calc();
    static int operate(int, char, int);
};

#endif // CALC_H
