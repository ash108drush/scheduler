#include "formtable.h"
#include "ui_formtable.h"

FormTable::FormTable(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormTable)
{
    ui->setupUi(this);
}

FormTable::~FormTable()
{
    delete ui;
}
