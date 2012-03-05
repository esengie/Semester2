#include "calculatorWidget.h"
#include "ui_calculator.h"


CalculatorWidget::CalculatorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculatorWidget)
{
    StackCalculator* kt = new StackCalculator();
    ui->setupUi(this);
    ui->comboBox->addItem("+");
    ui->comboBox->addItem("*");
    ui->comboBox->addItem("-");
    ui->comboBox->addItem("/");
    connect(ui->spinBox, SIGNAL(valueChanged(int)),
            kt,SLOT(left(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)),
            kt,SLOT(right(int)));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(const QString &)),
            kt,SLOT(oper(QString)));
    connect(kt, SIGNAL(value(QString)),
            ui->lineEdit, SLOT(setText(QString)));
}

CalculatorWidget::~CalculatorWidget()
{
    delete ui;
}
