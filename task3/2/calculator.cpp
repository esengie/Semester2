#include "calculator.h"
#include "ui_calculator.h"


Calculator::Calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculator)
{
    Calc* kt = new Calc();
    ui->setupUi(this);
    ui->comboBox->addItem("+");
    ui->comboBox->addItem("*");
    ui->comboBox->addItem("-");
    ui->comboBox->addItem("/");
    connect(ui->spinBox, SIGNAL(valueChanged(int)),
            kt,SLOT(left(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)),
            kt,SLOT(right(int)));
    connect(ui->comboBox, SIGNAL(editTextChanged(QString)),
            kt,SLOT(oper(QString)));
    connect(kt, SIGNAL(value(QString)),
            ui->lineEdit, SLOT(setText(QString)));
}

Calculator::~Calculator()
{
    delete ui;
}
