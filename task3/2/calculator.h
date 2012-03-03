#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <calc.h>

namespace Ui {
    class Calculator;
}

class Calculator : public QWidget
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private:
    Ui::Calculator *ui;
};

#endif // CALCULATOR_H
