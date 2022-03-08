/********************************************************************************
** Form generated from reading UI file 'model.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODEL_H
#define UI_MODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_model
{
public:
    QSlider *horizontalSlider;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *model)
    {
        if (model->objectName().isEmpty())
            model->setObjectName(QStringLiteral("model"));
        model->resize(479, 345);
        horizontalSlider = new QSlider(model);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(90, 90, 281, 29));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(model);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 50, 161, 21));
        pushButton = new QPushButton(model);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 210, 99, 27));

        retranslateUi(model);

        QMetaObject::connectSlotsByName(model);
    } // setupUi

    void retranslateUi(QWidget *model)
    {
        model->setWindowTitle(QApplication::translate("model", "Form", 0));
        label->setText(QApplication::translate("model", "\350\207\252\345\212\250\345\267\241\350\247\206\351\200\237\345\272\246", 0));
        pushButton->setText(QApplication::translate("model", "\346\233\264\346\224\271", 0));
    } // retranslateUi

};

namespace Ui {
    class model: public Ui_model {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODEL_H
