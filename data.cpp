#include "data.h"
#include "ui_data.h"

data::data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::data)
{
    ui->setupUi(this);
}

data::~data()
{
    delete ui;
}
