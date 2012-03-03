#ifndef CALC_H
#define CALC_H

#include <QString>
#include <QWidget>

class Calc : public QWidget
{
    Q_OBJECT
public:
    Calc(): QWidget(), left_(0), oper_('+'), right_(0)
    { }
signals:
    void value(QString);
public slots:
    void left(int);
    void oper(QString);
    void right(int);
private:
    //static const int size = 0;

    int left_;
    char oper_;
    int right_;

    void calc();
    static int operate(int, char, int);
};

#endif // CALC_H
