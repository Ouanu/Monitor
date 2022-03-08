#ifndef DATA_H
#define DATA_H

#include <QWidget>

namespace Ui {
class data;
}

class data : public QWidget
{
    Q_OBJECT

public:
    explicit data(QWidget *parent = 0);
    ~data();

private:
    Ui::data *ui;
};

#endif // DATA_H
