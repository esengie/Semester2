#include <ui-Calculator.h>
#include <calculatorWidget.h>
#include <stackCalculator.h>

CalculatorWidget::CalculatorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculatorWidget),
    numMapper(new QSignalMapper()),
    opMapper(new QSignalMapper()),
    m_left(0), m_oper(' '), m_right(0)
{
    ui->setupUi(this);
    for (int i = 0; i < Ui_CalculatorWidget::SIZE; i++)
    {
        if (i < 10)
        {
            connect(ui->pushButton[i], SIGNAL(clicked()), numMapper, SLOT(map()));
            numMapper->setMapping(ui->pushButton[i], ui->pushButton[i]->objectName().toInt());
        }
        else
        {
            connect(ui->pushButton[i], SIGNAL(clicked()), opMapper, SLOT(map()));
            opMapper->setMapping(ui->pushButton[i], ui->pushButton[i]->objectName());
        }
    };

    connect(opMapper, SIGNAL(mapped(QString)), this, SLOT(oper(QString)));
    connect(numMapper, SIGNAL(mapped(int)), this, SLOT(left(int)));
    connect(numMapper, SIGNAL(mapped(int)), this, SLOT(right(int)));
    connect(this, SIGNAL(result(QString)), ui->lineEdit, SLOT(setText(QString)));

}

CalculatorWidget::~CalculatorWidget()
{
    delete ui;
}



void CalculatorWidget::left(int value)
{
    if (m_oper == ' ')
    {
        m_left = m_left * 10 + value;
        QString text = QString::number(m_left);
        emit result(text);
    }
}

void CalculatorWidget::right(int value)
{
    if (m_oper != ' ')
    {
        m_right = m_right * 10 + value;
        QString text = QString::number(m_right);
        emit result(text);
    }
}

void CalculatorWidget::oper(QString sym)
{
    char op = sym.toAscii().data()[0];
    if (op == 'C')
    {
        m_oper = ' ';
        m_left = 0;
        m_right = 0;
        emit (result("0"));
        return;
    }
    if (op == '=')
    {
        if (m_right || m_oper != '/')
            {
                m_left = StackCalculator::operate(m_left, m_oper, m_right);
                QString text = QString::number(m_left);
                emit result(text);
            }
        else
        {
            m_left = 0;
            emit result("0");
        }
        m_oper = ' ';
        m_right = 0;
    }
    else
        m_oper = op;
}


