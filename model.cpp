#include "model.h"
#include "ui_model.h"
#include "menu.h"

model::model(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::model)
{
    ui->setupUi(this);
}

model::~model()
{
    delete ui;
}

void model::on_horizontalSlider_actionTriggered(int action)
{


}

void model::on_horizontalSlider_rangeChanged(int min, int max)
{

}

void model::on_horizontalSlider_valueChanged(int value)
{

}
