#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <stackCalculator.h>

namespace Ui {
    class CalculatorWidget;
}

class CalculatorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalculatorWidget(QWidget *parent = 0);
    ~CalculatorWidget();

private:
    Ui::CalculatorWidget *ui;
    int m_left;
    char m_oper;
    int m_right;

};

#endif // CALCULATOR_H
