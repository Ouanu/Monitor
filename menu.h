#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include<fops.h>
#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <steng.h>
#include <model.h>
#include <QTime>
#include <QTimer>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/face.hpp>
#include <QDebug>
#include <string>
#include <QDateTimeEdit>
#include <QString>
#include <click_lable.h>
#include <fileIndex.h>
#include <QProcess>
#include <iostream>
#include "autoptz.h"
#include <QDir>
#include <opencv2/dnn/dnn.hpp>
#include <fstream>
#include "mythread.h"
#include "cmythread.h"
#include "QTcpSocket"

using namespace std;
using namespace cv;

using namespace cv::face;

namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();

    void face_tracking(void);
    void eyes_tracking(void);


signals:
    void doit();



private slots:
    void on_swt_Control_bt_clicked();

    void on_file_Manage_bt_clicked();

    void on_turn_up_bt_pressed();

    void on_turn_left_bt_pressed();

    void on_turn_right_bt_pressed();

    void on_turn_down_bt_pressed();

    void on_turn_reset_bt_pressed();

    void on_mode_Setup_bt_2_clicked();

    void autorun();

    void on_horizontalSlider_valueChanged(int value);

    void CaptureOpen();

    void on_get_photo_bt_clicked();

    void on_get_video_bt_clicked();

    void on_catch_video_btn_clicked();

    void on_faceRecognition_btn_clicked();

    void on_lineEdit_returnPressed();

    void on_takePhoto_bt_clicked();

    void on_train_btn_clicked();

    void on_verify_btn_clicked();

    void read_csv1(const string&, vector<Mat>&, vector<int>&, char);

    void on_turn_up_bt_released();

    void on_turn_left_bt_released();

    void on_turn_down_bt_released();

    void on_turn_right_bt_released();

    void read_data();

    void connect_sud();

    void client_dis();

private:
    Ui::menu *ui;
    setEng sEng;

    bool swt_Control_flag = true;

    QTimer *autoTimer;
    bool spin_Control_flag = true;
    int LrAngle = 0;
    int valueReal;

    QTimer *capTimer;
    VideoCapture cap;
    Mat frame;
    Mat lastframe;
    String lasttext;

    int ImgCount = 0;

    VideoWriter writer;
    int VidCount = 0;
    bool VidFlag = true;

    fileIndex *fIndex;
    QProcess process;

    CascadeClassifier cascade1, nestedCascade1;
    double scale1 = 2.0;
    bool tryflip1;
    bool checkvideo = false;

    QProcess* processmedia;
    bool checkmedia = false;

    int mediap = 0;

    QString fullPath;
    autoPtz Eng;
    int filenum;
    Mat faceframe;

    Mat testSample;
    int testLabel;

    Ptr<BasicFaceRecognizer> model = EigenFaceRecognizer::create();

    Ptr<FaceRecognizer> modelPCA = EigenFaceRecognizer::create();

    QString modelname;
    Mat verifyFrame;
    bool setfaceverify;
    int imgcnt = 0;

    QString* fileItems;
    QString dataName;

    MyThread *myt;

    cmythread *t;
    QTcpSocket *mSocket;


};

#endif // MENU_H
