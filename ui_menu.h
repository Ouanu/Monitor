/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QWidget *centralWidget;
    QLabel *cap_Frame_lb;
    QStackedWidget *ctl_Panel_sw;
    QWidget *page;
    QLabel *label_8;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QCheckBox *checkBox_A1;
    QCheckBox *checkBox_A2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QCheckBox *checkBox_B1;
    QCheckBox *checkBox_B2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QCheckBox *checkBox_C1;
    QCheckBox *checkBox_C2;
    QLabel *label_2;
    QLabel *label_9;
    QLabel *label_7;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBox_A;
    QCheckBox *checkBox_B;
    QCheckBox *checkBox_C;
    QWidget *page_2;
    QPushButton *turn_reset_bt;
    QPushButton *get_photo_bt;
    QPushButton *get_video_bt;
    QPushButton *turn_up_bt;
    QPushButton *turn_left_bt;
    QPushButton *turn_right_bt;
    QPushButton *turn_down_bt;
    QPushButton *catch_video_btn;
    QWidget *page_3;
    QSlider *horizontalSlider;
    QLabel *label_3;
    QWidget *page_4;
    QLineEdit *lineEdit;
    QPushButton *takePhoto_bt;
    QLabel *face_num_lb;
    QPushButton *train_btn;
    QPushButton *verify_btn;
    QToolButton *swt_Control_bt;
    QToolButton *exp_Check_bt;
    QToolButton *file_Manage_bt;
    QToolButton *mode_Setup_bt_2;
    QLabel *video_current_time;
    QLabel *centerlocal;
    QToolButton *faceRecognition_btn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QStringLiteral("menu"));
        menu->resize(1024, 600);
        menu->setLayoutDirection(Qt::LeftToRight);
        centralWidget = new QWidget(menu);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        cap_Frame_lb = new QLabel(centralWidget);
        cap_Frame_lb->setObjectName(QStringLiteral("cap_Frame_lb"));
        cap_Frame_lb->setGeometry(QRect(30, 10, 600, 375));
        cap_Frame_lb->setStyleSheet(QStringLiteral("background-color: rgb(220, 146, 77);"));
        ctl_Panel_sw = new QStackedWidget(centralWidget);
        ctl_Panel_sw->setObjectName(QStringLiteral("ctl_Panel_sw"));
        ctl_Panel_sw->setGeometry(QRect(660, 0, 341, 401));
        ctl_Panel_sw->setStyleSheet(QStringLiteral("background-color: rgb(56, 195, 223);"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label_8 = new QLabel(page);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 50, 321, 121));
        label_8->setStyleSheet(QLatin1String("border-left: 1px solid red;\n"
"\n"
"border-right: 1px solid red;\n"
"\n"
"border-top: 1px solid red;\n"
"\n"
"border-bottom: 1px solid red;"));
        verticalLayoutWidget = new QWidget(page);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 60, 281, 104));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        checkBox_A1 = new QCheckBox(verticalLayoutWidget);
        checkBox_A1->setObjectName(QStringLiteral("checkBox_A1"));
        checkBox_A1->setEnabled(false);
        checkBox_A1->setStyleSheet(QStringLiteral("color: black"));
        checkBox_A1->setChecked(true);

        horizontalLayout_3->addWidget(checkBox_A1);

        checkBox_A2 = new QCheckBox(verticalLayoutWidget);
        checkBox_A2->setObjectName(QStringLiteral("checkBox_A2"));
        checkBox_A2->setEnabled(false);
        checkBox_A2->setStyleSheet(QStringLiteral("color: black"));
        checkBox_A2->setCheckable(false);

        horizontalLayout_3->addWidget(checkBox_A2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        checkBox_B1 = new QCheckBox(verticalLayoutWidget);
        checkBox_B1->setObjectName(QStringLiteral("checkBox_B1"));
        checkBox_B1->setEnabled(false);
        checkBox_B1->setStyleSheet(QStringLiteral("color: black"));
        checkBox_B1->setChecked(true);

        horizontalLayout_4->addWidget(checkBox_B1);

        checkBox_B2 = new QCheckBox(verticalLayoutWidget);
        checkBox_B2->setObjectName(QStringLiteral("checkBox_B2"));
        checkBox_B2->setEnabled(false);
        checkBox_B2->setStyleSheet(QStringLiteral("color: black"));
        checkBox_B2->setCheckable(false);

        horizontalLayout_4->addWidget(checkBox_B2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        checkBox_C1 = new QCheckBox(verticalLayoutWidget);
        checkBox_C1->setObjectName(QStringLiteral("checkBox_C1"));
        checkBox_C1->setEnabled(false);
        checkBox_C1->setStyleSheet(QStringLiteral("color: black"));
        checkBox_C1->setChecked(true);

        horizontalLayout->addWidget(checkBox_C1);

        checkBox_C2 = new QCheckBox(verticalLayoutWidget);
        checkBox_C2->setObjectName(QStringLiteral("checkBox_C2"));
        checkBox_C2->setEnabled(false);
        checkBox_C2->setStyleSheet(QStringLiteral("color: black"));
        checkBox_C2->setCheckable(false);

        horizontalLayout->addWidget(checkBox_C2);


        verticalLayout->addLayout(horizontalLayout);

        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 20, 101, 41));
        QFont font;
        font.setPointSize(11);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral(""));
        label_9 = new QLabel(page);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 230, 321, 71));
        label_9->setStyleSheet(QLatin1String("border-left: 1px solid red;\n"
"\n"
"border-right: 1px solid red;\n"
"\n"
"border-top: 1px solid red;\n"
"\n"
"border-bottom: 1px solid red;"));
        label_7 = new QLabel(page);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 210, 111, 31));
        label_7->setStyleSheet(QStringLiteral(""));
        horizontalLayoutWidget_4 = new QWidget(page);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(30, 250, 291, 41));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        checkBox_A = new QCheckBox(horizontalLayoutWidget_4);
        checkBox_A->setObjectName(QStringLiteral("checkBox_A"));
        checkBox_A->setEnabled(true);

        horizontalLayout_5->addWidget(checkBox_A);

        checkBox_B = new QCheckBox(horizontalLayoutWidget_4);
        checkBox_B->setObjectName(QStringLiteral("checkBox_B"));

        horizontalLayout_5->addWidget(checkBox_B);

        checkBox_C = new QCheckBox(horizontalLayoutWidget_4);
        checkBox_C->setObjectName(QStringLiteral("checkBox_C"));

        horizontalLayout_5->addWidget(checkBox_C);

        ctl_Panel_sw->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        turn_reset_bt = new QPushButton(page_2);
        turn_reset_bt->setObjectName(QStringLiteral("turn_reset_bt"));
        turn_reset_bt->setGeometry(QRect(120, 100, 91, 71));
        turn_reset_bt->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/reset.png"), QSize(), QIcon::Normal, QIcon::On);
        turn_reset_bt->setIcon(icon);
        turn_reset_bt->setIconSize(QSize(20, 20));
        get_photo_bt = new QPushButton(page_2);
        get_photo_bt->setObjectName(QStringLiteral("get_photo_bt"));
        get_photo_bt->setGeometry(QRect(30, 260, 101, 51));
        get_photo_bt->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/camera.png"), QSize(), QIcon::Normal, QIcon::On);
        get_photo_bt->setIcon(icon1);
        get_photo_bt->setIconSize(QSize(20, 20));
        get_video_bt = new QPushButton(page_2);
        get_video_bt->setObjectName(QStringLiteral("get_video_bt"));
        get_video_bt->setGeometry(QRect(230, 260, 101, 51));
        get_video_bt->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/video.png"), QSize(), QIcon::Normal, QIcon::On);
        get_video_bt->setIcon(icon2);
        get_video_bt->setIconSize(QSize(20, 20));
        turn_up_bt = new QPushButton(page_2);
        turn_up_bt->setObjectName(QStringLiteral("turn_up_bt"));
        turn_up_bt->setGeometry(QRect(120, 30, 91, 71));
        turn_up_bt->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/up.png"), QSize(), QIcon::Normal, QIcon::On);
        turn_up_bt->setIcon(icon3);
        turn_up_bt->setAutoRepeat(true);
        turn_up_bt->setAutoRepeatDelay(10);
        turn_up_bt->setAutoRepeatInterval(100);
        turn_left_bt = new QPushButton(page_2);
        turn_left_bt->setObjectName(QStringLiteral("turn_left_bt"));
        turn_left_bt->setGeometry(QRect(30, 100, 91, 71));
        turn_left_bt->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/left.png"), QSize(), QIcon::Normal, QIcon::On);
        turn_left_bt->setIcon(icon4);
        turn_left_bt->setAutoRepeat(true);
        turn_left_bt->setAutoRepeatDelay(10);
        turn_left_bt->setAutoRepeatInterval(100);
        turn_right_bt = new QPushButton(page_2);
        turn_right_bt->setObjectName(QStringLiteral("turn_right_bt"));
        turn_right_bt->setGeometry(QRect(210, 100, 91, 71));
        turn_right_bt->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/right.png"), QSize(), QIcon::Normal, QIcon::On);
        turn_right_bt->setIcon(icon5);
        turn_right_bt->setAutoRepeat(true);
        turn_right_bt->setAutoRepeatDelay(10);
        turn_right_bt->setAutoRepeatInterval(100);
        turn_down_bt = new QPushButton(page_2);
        turn_down_bt->setObjectName(QStringLiteral("turn_down_bt"));
        turn_down_bt->setGeometry(QRect(120, 170, 91, 71));
        turn_down_bt->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/down.png"), QSize(), QIcon::Normal, QIcon::On);
        turn_down_bt->setIcon(icon6);
        turn_down_bt->setAutoRepeat(true);
        turn_down_bt->setAutoRepeatDelay(10);
        turn_down_bt->setAutoRepeatInterval(100);
        catch_video_btn = new QPushButton(page_2);
        catch_video_btn->setObjectName(QStringLiteral("catch_video_btn"));
        catch_video_btn->setGeometry(QRect(110, 330, 131, 61));
        ctl_Panel_sw->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        horizontalSlider = new QSlider(page_3);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(30, 160, 281, 29));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 90, 321, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("AR PL UKai CN"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_3->setFont(font1);
        label_3->setStyleSheet(QStringLiteral("font: 11pt \"AR PL UKai CN\";"));
        ctl_Panel_sw->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        lineEdit = new QLineEdit(page_4);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 90, 113, 27));
        lineEdit->setStyleSheet(QStringLiteral("background-color: rgb(39, 244, 235);"));
        takePhoto_bt = new QPushButton(page_4);
        takePhoto_bt->setObjectName(QStringLiteral("takePhoto_bt"));
        takePhoto_bt->setGeometry(QRect(70, 160, 171, 41));
        face_num_lb = new QLabel(page_4);
        face_num_lb->setObjectName(QStringLiteral("face_num_lb"));
        face_num_lb->setGeometry(QRect(210, 90, 67, 17));
        train_btn = new QPushButton(page_4);
        train_btn->setObjectName(QStringLiteral("train_btn"));
        train_btn->setGeometry(QRect(70, 220, 171, 41));
        verify_btn = new QPushButton(page_4);
        verify_btn->setObjectName(QStringLiteral("verify_btn"));
        verify_btn->setGeometry(QRect(70, 280, 171, 41));
        ctl_Panel_sw->addWidget(page_4);
        swt_Control_bt = new QToolButton(centralWidget);
        swt_Control_bt->setObjectName(QStringLiteral("swt_Control_bt"));
        swt_Control_bt->setGeometry(QRect(30, 430, 161, 81));
        swt_Control_bt->setStyleSheet(QStringLiteral("padding:10px"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/change.png"), QSize(), QIcon::Normal, QIcon::Off);
        swt_Control_bt->setIcon(icon7);
        swt_Control_bt->setIconSize(QSize(40, 40));
        swt_Control_bt->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        exp_Check_bt = new QToolButton(centralWidget);
        exp_Check_bt->setObjectName(QStringLiteral("exp_Check_bt"));
        exp_Check_bt->setGeometry(QRect(220, 430, 161, 81));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/false.png"), QSize(), QIcon::Normal, QIcon::Off);
        exp_Check_bt->setIcon(icon8);
        exp_Check_bt->setIconSize(QSize(40, 40));
        exp_Check_bt->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        file_Manage_bt = new QToolButton(centralWidget);
        file_Manage_bt->setObjectName(QStringLiteral("file_Manage_bt"));
        file_Manage_bt->setGeometry(QRect(410, 430, 151, 81));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        file_Manage_bt->setIcon(icon9);
        file_Manage_bt->setIconSize(QSize(40, 40));
        file_Manage_bt->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        mode_Setup_bt_2 = new QToolButton(centralWidget);
        mode_Setup_bt_2->setObjectName(QStringLiteral("mode_Setup_bt_2"));
        mode_Setup_bt_2->setGeometry(QRect(590, 430, 161, 81));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/model.png"), QSize(), QIcon::Normal, QIcon::Off);
        mode_Setup_bt_2->setIcon(icon10);
        mode_Setup_bt_2->setIconSize(QSize(40, 40));
        mode_Setup_bt_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        video_current_time = new QLabel(centralWidget);
        video_current_time->setObjectName(QStringLiteral("video_current_time"));
        video_current_time->setGeometry(QRect(50, 30, 67, 17));
        centerlocal = new QLabel(centralWidget);
        centerlocal->setObjectName(QStringLiteral("centerlocal"));
        centerlocal->setGeometry(QRect(420, 210, 67, 17));
        faceRecognition_btn = new QToolButton(centralWidget);
        faceRecognition_btn->setObjectName(QStringLiteral("faceRecognition_btn"));
        faceRecognition_btn->setGeometry(QRect(790, 430, 161, 81));
        faceRecognition_btn->setIcon(icon10);
        faceRecognition_btn->setIconSize(QSize(40, 40));
        faceRecognition_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        menu->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(menu);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 31));
        menu->setMenuBar(menuBar);
        mainToolBar = new QToolBar(menu);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        menu->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(menu);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        menu->setStatusBar(statusBar);

        retranslateUi(menu);

        ctl_Panel_sw->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QMainWindow *menu)
    {
        menu->setWindowTitle(QApplication::translate("menu", "menu", 0));
        cap_Frame_lb->setText(QApplication::translate("menu", "TextLabel", 0));
        label_8->setText(QString());
        label_5->setText(QApplication::translate("menu", "A\345\214\272", 0));
        checkBox_A1->setText(QApplication::translate("menu", "\346\255\243\345\270\270", 0));
        checkBox_A2->setText(QApplication::translate("menu", "\345\274\202\345\270\270", 0));
        label_6->setText(QApplication::translate("menu", "B\345\214\272", 0));
        checkBox_B1->setText(QApplication::translate("menu", "\346\255\243\345\270\270", 0));
        checkBox_B2->setText(QApplication::translate("menu", "\345\274\202\345\270\270", 0));
        label->setText(QApplication::translate("menu", "C\345\214\272", 0));
        checkBox_C1->setText(QApplication::translate("menu", "\346\255\243\345\270\270", 0));
        checkBox_C2->setText(QApplication::translate("menu", "\345\274\202\345\270\270", 0));
        label_2->setText(QApplication::translate("menu", "\345\275\223\345\211\215\347\212\266\346\200\201", 0));
        label_9->setText(QString());
        label_7->setText(QApplication::translate("menu", "\345\275\223\345\211\215\347\212\266\346\200\201", 0));
        checkBox_A->setText(QApplication::translate("menu", "A\345\214\272", 0));
        checkBox_B->setText(QApplication::translate("menu", "B\345\214\272", 0));
        checkBox_C->setText(QApplication::translate("menu", "C\345\214\272", 0));
        turn_reset_bt->setText(QString());
        get_photo_bt->setText(QString());
        get_video_bt->setText(QString());
        turn_up_bt->setText(QString());
        turn_left_bt->setText(QString());
        turn_right_bt->setText(QString());
        turn_down_bt->setText(QString());
        catch_video_btn->setText(QApplication::translate("menu", "\346\215\225\350\216\267", 0));
        label_3->setText(QApplication::translate("menu", "\346\273\221\345\212\250\350\260\203\350\212\202\350\207\252\345\212\250\345\267\241\350\247\206\351\200\237\345\272\246", 0));
        takePhoto_bt->setText(QApplication::translate("menu", "\346\213\215\347\205\247\346\210\252\345\217\226\344\272\272\350\204\270", 0));
        face_num_lb->setText(QApplication::translate("menu", "TextLabel", 0));
        train_btn->setText(QApplication::translate("menu", "\350\256\255\347\273\203", 0));
        verify_btn->setText(QApplication::translate("menu", "\346\240\241\351\252\214", 0));
        swt_Control_bt->setText(QApplication::translate("menu", "\345\210\207\346\215\242\350\207\252\345\212\250", 0));
        exp_Check_bt->setText(QApplication::translate("menu", "\345\274\202\345\270\270\346\237\245\347\234\213", 0));
        file_Manage_bt->setText(QApplication::translate("menu", "\346\226\207\344\273\266\347\256\241\347\220\206", 0));
        mode_Setup_bt_2->setText(QApplication::translate("menu", "\346\250\241\345\274\217\350\256\276\347\275\256", 0));
        video_current_time->setText(QApplication::translate("menu", "test", 0));
        centerlocal->setText(QApplication::translate("menu", "TextLabel", 0));
        faceRecognition_btn->setText(QApplication::translate("menu", "\344\272\272\350\204\270\350\257\206\345\210\253", 0));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
