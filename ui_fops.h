/********************************************************************************
** Form generated from reading UI file 'fops.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOPS_H
#define UI_FOPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fops
{
public:
    QPushButton *back_menu_bt;
    QLabel *label;

    void setupUi(QWidget *fops)
    {
        if (fops->objectName().isEmpty())
            fops->setObjectName(QStringLiteral("fops"));
        fops->resize(1024, 600);
        back_menu_bt = new QPushButton(fops);
        back_menu_bt->setObjectName(QStringLiteral("back_menu_bt"));
        back_menu_bt->setGeometry(QRect(240, 420, 501, 71));
        back_menu_bt->setStyleSheet(QStringLiteral("background-color: rgb(193, 95, 95);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/exit.png"), QSize(), QIcon::Normal, QIcon::On);
        back_menu_bt->setIcon(icon);
        back_menu_bt->setIconSize(QSize(40, 40));
        label = new QLabel(fops);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 100, 751, 191));
        QFont font;
        font.setPointSize(21);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("background-color: rgb(48, 193, 111);"));

        retranslateUi(fops);

        QMetaObject::connectSlotsByName(fops);
    } // setupUi

    void retranslateUi(QWidget *fops)
    {
        fops->setWindowTitle(QApplication::translate("fops", "Form", 0));
        back_menu_bt->setText(QApplication::translate("fops", "\350\277\224\345\233\236\350\217\234\345\215\225", 0));
        label->setText(QApplication::translate("fops", "         \346\255\244\345\244\204\346\230\257\346\226\207\344\273\266\347\256\241\347\220\206\347\225\214\351\235\242", 0));
    } // retranslateUi

};

namespace Ui {
    class fops: public Ui_fops {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOPS_H
