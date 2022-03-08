/********************************************************************************
** Form generated from reading UI file 'fileIndex.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEINDEX_H
#define UI_FILEINDEX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fileIndex
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QListWidget *picWidget;
    QListWidget *vidWidget;
    QPushButton *exit_bt;
    QPushButton *deletefile;
    QPushButton *flashfile;
    QPushButton *rename;
    QPushButton *search;
    QPushButton *pushButton;
    QListWidget *dataWidget;
    QPushButton *insert_init;
    QPushButton *openButton;
    QPushButton *sendButton;

    void setupUi(QMainWindow *fileIndex)
    {
        if (fileIndex->objectName().isEmpty())
            fileIndex->setObjectName(QStringLiteral("fileIndex"));
        fileIndex->resize(1024, 600);
        fileIndex->setMinimumSize(QSize(1024, 600));
        fileIndex->setMaximumSize(QSize(1024, 600));
        centralwidget = new QWidget(fileIndex);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1024, 600));
        tabWidget->setMinimumSize(QSize(1024, 600));
        tabWidget->setMaximumSize(QSize(1024, 600));
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tabWidget->setStyleSheet(QStringLiteral("background-color: rgb(208, 201, 194);"));
        picWidget = new QListWidget(centralwidget);
        picWidget->setObjectName(QStringLiteral("picWidget"));
        picWidget->setGeometry(QRect(0, 0, 1024, 600));
        picWidget->setMinimumSize(QSize(1024, 600));
        vidWidget = new QListWidget(centralwidget);
        vidWidget->setObjectName(QStringLiteral("vidWidget"));
        vidWidget->setGeometry(QRect(0, 0, 1024, 600));
        vidWidget->setMinimumSize(QSize(1024, 600));
        vidWidget->setMaximumSize(QSize(1024, 600));
        exit_bt = new QPushButton(centralwidget);
        exit_bt->setObjectName(QStringLiteral("exit_bt"));
        exit_bt->setGeometry(QRect(949, 0, 71, 41));
        exit_bt->setStyleSheet(QStringLiteral("border-image: url(:/images/exit.png);"));
        deletefile = new QPushButton(centralwidget);
        deletefile->setObjectName(QStringLiteral("deletefile"));
        deletefile->setGeometry(QRect(830, 530, 121, 51));
        deletefile->setStyleSheet(QStringLiteral("background-color: rgb(228, 164, 164);"));
        flashfile = new QPushButton(centralwidget);
        flashfile->setObjectName(QStringLiteral("flashfile"));
        flashfile->setGeometry(QRect(630, 530, 141, 51));
        rename = new QPushButton(centralwidget);
        rename->setObjectName(QStringLiteral("rename"));
        rename->setGeometry(QRect(430, 530, 131, 51));
        search = new QPushButton(centralwidget);
        search->setObjectName(QStringLiteral("search"));
        search->setGeometry(QRect(240, 530, 131, 51));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 530, 111, 51));
        dataWidget = new QListWidget(centralwidget);
        dataWidget->setObjectName(QStringLiteral("dataWidget"));
        dataWidget->setGeometry(QRect(10, 10, 1024, 600));
        dataWidget->setMinimumSize(QSize(1024, 600));
        dataWidget->setMaximumSize(QSize(1024, 600));
        insert_init = new QPushButton(centralwidget);
        insert_init->setObjectName(QStringLiteral("insert_init"));
        insert_init->setGeometry(QRect(658, 10, 111, 51));
        openButton = new QPushButton(centralwidget);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(210, 30, 99, 27));
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(450, 30, 99, 27));
        fileIndex->setCentralWidget(centralwidget);
        dataWidget->raise();
        tabWidget->raise();
        picWidget->raise();
        vidWidget->raise();
        exit_bt->raise();
        deletefile->raise();
        flashfile->raise();
        rename->raise();
        search->raise();
        pushButton->raise();
        insert_init->raise();
        openButton->raise();
        sendButton->raise();

        retranslateUi(fileIndex);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(fileIndex);
    } // setupUi

    void retranslateUi(QMainWindow *fileIndex)
    {
        fileIndex->setWindowTitle(QApplication::translate("fileIndex", "MainWindow", 0));
        exit_bt->setText(QString());
        deletefile->setText(QApplication::translate("fileIndex", "\345\210\240\351\231\244", 0));
        flashfile->setText(QApplication::translate("fileIndex", "\345\210\267\346\226\260", 0));
        rename->setText(QApplication::translate("fileIndex", "\346\224\271\345\220\215", 0));
        search->setText(QApplication::translate("fileIndex", "\346\237\245\350\257\242", 0));
        pushButton->setText(QApplication::translate("fileIndex", "\345\242\236\345\212\240", 0));
        insert_init->setText(QApplication::translate("fileIndex", "\347\241\256\345\256\232", 0));
        openButton->setText(QApplication::translate("fileIndex", "open", 0));
        sendButton->setText(QApplication::translate("fileIndex", "send", 0));
    } // retranslateUi

};

namespace Ui {
    class fileIndex: public Ui_fileIndex {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEINDEX_H
