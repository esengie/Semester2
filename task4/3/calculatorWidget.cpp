#include "calculatorWidget.h"
#include "ui_calculatorWidget.h"

CalculatorWidget::CalculatorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculatorWidget)
{
    ui->setupUi(this);
}

CalculatorWidget::~CalculatorWidget()
{
    delete ui;
}
