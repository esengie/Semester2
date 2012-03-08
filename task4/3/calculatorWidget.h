#ifndef CALCULATORWIDGET_H
#define CALCULATORWIDGET_H

#include <QWidget>
#include <QSignalMapper>


namespace Ui {
    class CalculatorWidget;
}

class CalculatorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalculatorWidget(QWidget *parent = 0);
    ~CalculatorWidget();
signals:
    void result(QString);
public slots:
    void oper(QString);
    void left(int);
    void right(int);

private:
    Ui::CalculatorWidget *ui;
    QSignalMapper * numMapper;
    QSignalMapper * opMapper;
    int m_left;
    char m_oper;
    int m_right;
    bool isRight;

};

#endif // CALCULATORWIDGET_H
