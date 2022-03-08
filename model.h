#ifndef MODEL_H
#define MODEL_H

#include <QWidget>

namespace Ui {
class model;
}

class model : public QWidget
{
    Q_OBJECT

public:
    explicit model(QWidget *parent = 0);
    ~model();

private slots:
    void on_horizontalSlider_actionTriggered(int action);

    void on_horizontalSlider_rangeChanged(int min, int max);

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::model *ui;
};

#endif // MODEL_H
