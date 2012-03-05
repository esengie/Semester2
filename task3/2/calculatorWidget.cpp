#include "stackCalculator.h"
#include "calculatorWidget.h"
#include "ui_calculator.h"


CalculatorWidget::CalculatorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculatorWidget), m_left(0), m_oper('+'), m_right(0)
{
    ui->setupUi(this);
    ui->comboBox->addItem("+");
    ui->comboBox->addItem("*");
    ui->comboBox->addItem("-");
    ui->comboBox->addItem("/");
    connect(ui->spinBox, SIGNAL(valueChanged(int)),
            this,SLOT(left(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)),
            this,SLOT(right(int)));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(const QString&)),
            this,SLOT(oper(const QString&)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)),
            this,SLOT(sender()));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)),
            this,SLOT(sender()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(const QString&)),
            this,SLOT(sender()));
    connect(this, SIGNAL(value(QString)),
            ui->lineEdit, SLOT(setText(QString)));
}

CalculatorWidget::~CalculatorWidget()
{
    delete ui;
}


void CalculatorWidget::left(int a)
{
    m_left = a;
}

void CalculatorWidget::right(int a)
{
    m_right = a;
}

void CalculatorWidget::oper(const QString& s)
{
    m_oper = s.toAscii().data()[0];
}


void CalculatorWidget::sender()
{
    if (m_right || m_oper != '/')
    {
        int temp = StackCalculator::operate(m_left, m_oper, m_right);
        QString text = QString::number(temp);
        emit value(text);
    }
    else
    {
        emit value("0");
    }
}

