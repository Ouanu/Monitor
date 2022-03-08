#include "menu.h"
#include "ui_menu.h"
#include <QThread>


menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/menu.jpg")));
    this->setPalette(palette);
    ui->swt_Control_bt->setText("切换手动");
    ui->ctl_Panel_sw->setCurrentIndex(0);
    ui->ctl_Panel_sw->hide();

    mSocket = new QTcpSocket();
    connect(mSocket, SIGNAL(readyRead()), this, SLOT(read_data()));
    connect(mSocket, SIGNAL(connected()), this, SLOT(connect_sud()));
    connect(mSocket, SIGNAL(disconnected()),this, SLOT(client_dis()));
    mSocket->connectToHost("192.168.1.179", 9988);



    //调整初始化角度
    sEng.backLrpos();
    sEng.backUdpos();

    //添加分类器
    cascade1.load("./haarcascade_frontalface_alt.xml");
    nestedCascade1.load("./haarcascade_eye_tree_eyeglasses.xml");

    capTimer = new QTimer(this);
    connect(capTimer, SIGNAL(timeout()),this,SLOT(CaptureOpen()));
//    CaptureOpen();
    cap.open(0);
    capTimer->start(10);

    ui->centerlocal->hide();
    processmedia = new QProcess(this);

    myt = new MyThread(this);
//    t = new cmythread(this);


    connect(this, &menu::doit, myt, &MyThread::autorunT);


    myt->start();


}

menu::~menu()
{
    delete ui;
}


//Tcp通信
void menu::read_data()
{
    QString msg = mSocket->readAll();
    if(msg.compare("turnUp") == 0){
        on_turn_up_bt_pressed();
    } else if(msg.compare("turnDown") == 0){
        on_turn_down_bt_pressed();
    } else if(msg.compare("turnLeft") == 0){
        on_turn_left_bt_pressed();
    } else if(msg.compare("turnRight") == 0){
        on_turn_right_bt_pressed();
    } else if(msg.compare("reset") == 0){
        on_turn_reset_bt_pressed();
    } else if(msg.compare("releaseUp") == 0){
        on_turn_up_bt_released();
    } else if(msg.compare("releaseDown") == 0){
        on_turn_down_bt_released();
    } else if(msg.compare("releaseLeft") == 0){
        on_turn_left_bt_released();
    } else if(msg.compare("releaseRight") == 0){
        on_turn_right_bt_released();
    } else if(msg.compare("autoRun") == 0){
        on_swt_Control_bt_clicked();
    } else if(msg.compare("takePhoto") == 0){
        on_get_photo_bt_clicked();
    } else if(msg.compare("takeVideo") == 0){
        on_get_video_bt_clicked();
    } else if(msg.compare("openFile") == 0){
        on_file_Manage_bt_clicked();
    }
    qDebug() << msg;

}


void menu::connect_sud()
{
//    ui->btn_connectServer->setEnabled(false);
}



void menu::client_dis()
{
//    ui->btn_connectServer->setEnabled(true);

}

void menu::on_swt_Control_bt_clicked()
{
    if(swt_Control_flag)
    {   
        swt_Control_flag = false;
        ui->swt_Control_bt->setText("切换自动");
        ui->ctl_Panel_sw->setCurrentIndex(1);
//        autoTimer->stop();
        myt->index = 5;
        myt->autobool = true;
        myt->quit();
//        myt->index = 1;
//        emit doit();




    }else{
        qDebug() << "We in control";
        swt_Control_flag = true;
        ui->swt_Control_bt->setText("切换手动");
        ui->ctl_Panel_sw->setCurrentIndex(0);
//        ui->horizontalSlider->setValue(myt->speed);
        myt->quit();
        myt->autobool = false;
        myt->index = 0;
        myt->start();
//        autoTimer->start(20);

    }
}

void menu::on_file_Manage_bt_clicked()
{
    fIndex = new fileIndex(this);
    fIndex->updatePicData("./photo");
    fIndex->updataVidData("./video/pic","./video");
    fIndex->show();
//    autoTimer->stop();
    capTimer->stop();
    myt->index =5;
    myt->autobool = true;
    myt->quit();
//    this->hide();
//    mSocket->close();
}



void menu::on_turn_up_bt_pressed()
{
    qDebug() << "turn up....";
    myt->index = 3;
    myt->start();


}

void menu::on_turn_left_bt_pressed()
{
    qDebug() << "turn left....";
    myt->index = 1;
    myt->start();


}

void menu::on_turn_right_bt_pressed()
{
    qDebug() << "turn right....";
    myt->index = 2;
    myt->start();


}

void menu::on_turn_down_bt_pressed()
{
    qDebug() << "turn down....";
    myt->index = 4;
    myt->start();

}


void menu::on_turn_reset_bt_pressed()
{
    myt->index = 6;
    myt->start();
}



void menu::on_mode_Setup_bt_2_clicked()
{
    ui->ctl_Panel_sw->setCurrentIndex(2);
}

void menu::autorun(){
    if(spin_Control_flag)
    {
        sEng.turnLeft();

        if(sEng.getLrAngle() <= 0)
        {
            spin_Control_flag = false;
        }
    }
    else
    {
        sEng.turnRight();
        if(sEng.getLrAngle() >= 100)
        {
            spin_Control_flag = true;
        }

    }
    qDebug() << sEng.getLrAngle();
}



void menu::on_horizontalSlider_valueChanged(int value)
{
//    autoTimer->start(10*(10-value/10));
    myt->speed = 10*(10-value/10);
}

void menu::CaptureOpen()
{

    cap >> frame;
    face_tracking();
    eyes_tracking();
    Mat frame1;
    cvtColor(frame, frame1, CV_BGR2RGB);
    string text = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss").toUtf8().constData();
    cv::putText(frame, text, cv::Point(0,50), FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255), 1, LINE_AA);
    cv::putText(frame1, text, cv::Point(0,50), FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255), 1, LINE_AA);
    QImage Qimage1 = QImage((const unsigned char*)(frame1.data),
                            frame1.cols, frame1.rows,
                            frame1.step, QImage::Format_RGB888);
    ui->cap_Frame_lb->setPixmap(QPixmap::fromImage(Qimage1));

    ui->cap_Frame_lb->resize(600, 375);
    ui->cap_Frame_lb->show();

    if(!VidFlag)
    {
    //次数可以调整视频的帧数
    writer << frame;
    writer << frame;
    writer << frame;
    writer << frame;
    }
    lastframe = frame;
    lasttext = text;




}


void menu::on_get_photo_bt_clicked()
{
    qDebug() << "takePhoto";
    stringstream stempr;
    stempr << ImgCount;
    QDateTime qdt = QDateTime::currentDateTime();
    string scountr = stempr.str();
    string strr = "./photo/";
    strr += qdt.toString("yyyy-MM-dd-hh-mm-ss").toUtf8().constData();
    strr += ".jpg";

    imwrite(strr,frame);
    ImgCount++;
}

void menu::on_get_video_bt_clicked()
{
    if(VidFlag)
    {
        VidFlag = false;
        checkvideo = true;


        ui->get_video_bt->setText("关闭录制");
        QDateTime qdt = QDateTime::currentDateTime();



        ostringstream os;
        os << VidCount;

        string str = "./video/";
        string namevc = qdt.toString("yyyy-MM-dd-hh-mm-ss").toUtf8().constData();
        str += namevc;
        str += ".avi";

        QString cmd = "arecord -d3 -c1 -r16000 -twav -fS16_LE ./sound/";
        cmd.append(QString::fromStdString(namevc));
        cmd.append(QString(".wav"));
        process.start(cmd);

        string strr = "./video/pic/";
        strr += lasttext;
        strr += ".jpg";

        imwrite(strr,lastframe);

        writer.open(str, CV_FOURCC('M', 'J', 'P', 'G'), 30.0, Size(640, 480), true);
        if(!(writer.isOpened()))
        {
            qDebug() << "videowriter open fail";
        }
        qDebug() << "开始录制";

        VidCount++;
    }

    else
    {
        VidFlag = true;
        process.kill();
        ui->get_video_bt->setText("录制");
        checkvideo = false;
        writer.release();
    }
}

void menu::on_catch_video_btn_clicked()
{
    capTimer->start(10);
}

void menu::face_tracking(void)
{
    int i = 0;
    double t = 0;
    vector<Rect> faces, faces2;
    const static Scalar colors[] = {
        CV_RGB(0,0,255),
        CV_RGB(0,128,255),
        CV_RGB(0,255,255),
        CV_RGB(0,255,0),
        CV_RGB(255,128,0),
        CV_RGB(255,255,0),
        CV_RGB(255,0,0),
        CV_RGB(255,0,255)} ;
    Mat gray1,smallImg(cvRound(frame.rows/scale1), cvRound(frame.cols/scale1), CV_8UC1 );

    cvtColor(frame, gray1, CV_BGR2GRAY );
    cv::resize(gray1, smallImg, Size(frame.cols / 3, frame.rows / 3));

    equalizeHist( smallImg, smallImg );
    t = (double)cvGetTickCount();
    cascade1.detectMultiScale( smallImg, faces,1.6, 3, 0|CV_HAAR_SCALE_IMAGE,Size(30, 30));

    if(faces.size() > 0) {
        //更新检测到人脸
        Mat faceROI = smallImg(faces[0]);
        Mat myFace;
        cv::resize(faceROI, myFace, Size(92,112));
        faceframe = myFace;
        verifyFrame = faceframe;

        QFile filemodel("./facedata/MyFacePCAModel.xml");
        if(filemodel.exists()){
            modelPCA->read("./facedata/MyFacePCAModel.xml");
            qDebug() << "----------------   "+QString::number(modelPCA->getThreshold());
            modelPCA->setThreshold(3000);
            int predictedLabel = modelPCA->predict(verifyFrame);//加载分类器
//            1.7976931348623157e+308
            qDebug() << "----------------   "+QString::number(modelPCA->getThreshold());
            qDebug() << "----------------   "+QString::number(predictedLabel);
            if(predictedLabel > -1) ui->ctl_Panel_sw->show();
            QFile file("./facedata/Faces/name.txt");
            QByteArray line;
            if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                 while (predictedLabel >= 0)
                 {
                   line = file.readLine();
    //               qDebug() << line ;
                   predictedLabel--;
                 }
                   file.close();
            }
            dataName = line;
            line.replace("\n", " ");
        }

    }



    t = (double)cvGetTickCount() - t;
    for( vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); r++, i++ )
    {
        Mat smallImgROI;
        vector<Rect> nestedObjects;
        static Point center;
        int radius;
        double aspect_ratio = (double)r->width/r->height;

        if( 0.75 < aspect_ratio && aspect_ratio < 1.3 )
        {
            ui->centerlocal->show();
            center.x = cvRound((r->x + r->width*0.5)*scale1)*1.5;
            center.y = cvRound((r->y + r->height*0.5)*scale1)*1.5;
            radius = cvRound((r->width + r->height)*0.25*scale1)*1.5;
            QString centerXY = "x:";
            centerXY += center.x;
            centerXY +=  " y:";
            centerXY += center.y;
            int x = center.x;
            int y = center.y;
            QString textXY = "X:";
            textXY += QString::number(x);
            textXY += " Y:";
            textXY += QString::number(y);
            qDebug() << textXY;
            ui->centerlocal->setText(textXY + " " + dataName);
            ui->centerlocal->setGeometry(QRect(center.x,center.y,200,50));
            circle(frame, center, radius, Scalar(0,0,255), 3, 8, 0 );

            qDebug() << radius;
            if(radius <= 76) {
                qDebug() << "A";
                if(checkmedia == true && mediap == 2) {
                    processmedia->kill();
                    checkmedia = false;
                } else {
                    processmedia->start("aplay ./media/Alarm01.wav");
                    checkmedia = true;
                    mediap = 1;
                }
                on_get_photo_bt_clicked();
                if(checkvideo == true) {
                    on_get_video_bt_clicked();
                }
            } else {
                qDebug() << "B";
                if(checkmedia == true && mediap == 1) {
                    processmedia->kill();
                    checkmedia = false;
                } else {
                    processmedia->start("aplay ./media/Alarm02.wav");
                    checkmedia = true;
                    mediap = 2;
                }
                if(checkvideo == false) {
                    on_get_video_bt_clicked();
                }
            }


            //计算并解析出偏移量
            double x_offset,y_offset;
            double length;

            if(center.x < frame.rows && center.y < frame.cols)
            {
                x_offset=((((double)center.x)/(double)frame.rows)-0.65)*2;
                y_offset=((((double)center.y)/(double)frame.cols)-0.4)*2;
            }

            //控制舵机左右偏转
            if((x_offset > 0) && (x_offset <= 1))
            {
                Eng.turnRight(x_offset);
//                myt->off_set4 = x_offset*2;
//                myt->index = 10;
//                myt->start();
            }
            if((x_offset) < 0 && (x_offset) >= -1)
            {
                Eng.turnLeft(x_offset);
//                myt->off_set3 = x_offset*2;
//                myt->index = 9;
//                myt->start();

            }
            //控制舵机上下偏转
            if((y_offset > 0) && (y_offset <= 1))
            {
                Eng.turnUp(y_offset);
//                myt->off_set1 = y_offset*2;
//                myt->index = 7;
//                myt->start();
            }
            if((y_offset) < 0 && (y_offset) >= -1)
            {
                Eng.turnDown(y_offset);
//                myt->off_set2 = y_offset*2;
//                myt->index = 8;
//                myt->start();
            }

        }
        else
        {
            cout << "no face" <<endl;
            ui->centerlocal->hide();
            checkmedia = false;
        }

        if( nestedCascade1.empty() )
        continue;
    }

}


void menu::eyes_tracking(void)
{
    int i = 0;
    double t = 0;
    vector<Rect> eyes, eyes2;
    const static Scalar colors[] = { CV_RGB(0,0,255),
                                     CV_RGB(0,128,255),
                                     CV_RGB(0,255,255),
                                     CV_RGB(0,255,0),
                                     CV_RGB(255,128,0),
                                     CV_RGB(255,255,0),
                                     CV_RGB(255,0,0),
                                     CV_RGB(255,0,255)} ;
    Mat gray1,smallImg(cvRound(frame.rows/scale1),
                       cvRound(frame.cols/scale1), CV_8UC1 );
    cvtColor(frame, gray1, CV_BGR2GRAY );
    cv::resize(gray1, smallImg, Size(frame.cols / 3, frame.rows / 3));
    equalizeHist( smallImg, smallImg );
    t = (double)cvGetTickCount();
    nestedCascade1.detectMultiScale( smallImg, eyes,1.6, 3, 0
                                     |CV_HAAR_SCALE_IMAGE
                                     ,
                                     Size(30, 30));
    t = (double)cvGetTickCount() - t;
    for( vector<Rect>::const_iterator r = eyes.begin(); r != eyes.end(); r++, i++ )
    {
        Mat smallImgROI;
        vector<Rect> nestedObjects;
        static Point center;
        int radius;
        double aspect_ratio = (double)r->width/r->height;
        if( 0.75 < aspect_ratio && aspect_ratio < 1.3 )
        {
            center.x = cvRound((r->x + r->width*0.5)*scale1)*1.5;
            center.y = cvRound((r->y + r->height*0.5)*scale1)*1.5;
            radius = cvRound((r->width + r->height)*0.25*scale1)*1.5;
            circle(frame, center, radius, Scalar(0,0,255), 3, 8, 0 );

        }
        else
            cout << "no eyes" <<endl;

        if( cascade1.empty() )
            continue;
    }
}

void menu::on_faceRecognition_btn_clicked()
{
    ui->ctl_Panel_sw->setCurrentIndex(3);
}

void menu::on_lineEdit_returnPressed()
{
    qDebug() << "------创建新文件夹-------";
    int num = 0;
    while(1)
    {
        QString str = QString::number(num);
        modelname = ui->lineEdit->text();
        fullPath = "./facedata/Faces/s" + str;
        QDir dir(fullPath);
        if(dir.exists())
        {
            num++;
            continue;
        }
        break;
    }
    filenum = num;
    QString dir = fullPath;
    QDir di;
    di.mkdir(dir);
    QFile file("./facedata/Faces/name.txt");
        if(! file.open(QIODevice::Append|QIODevice::Text))  //append追加，不会覆盖之前的文件
        {
            QMessageBox::critical(this,"错误","文件打开失败，信息没有保存！","确定");
            return;
        }

        QTextStream out(&file);//写入
        out << modelname+"\n";
        file.close();
}

void menu::on_takePhoto_bt_clicked()
{
    setfaceverify = true;
//    on_get_photo_bt_clicked();
    QString s = fullPath + "/" + QString::number(imgcnt) + ".jpg";
    string filename = s.toStdString();
    imwrite(filename, faceframe);
    ui->face_num_lb->setText(QString::number(imgcnt));
    imgcnt ++;
    QFile file("./facedata/Faces/at.txt");
        if(! file.open(QIODevice::Append|QIODevice::Text))  //append追加，不会覆盖之前的文件
        {
            QMessageBox::critical(this,"错误","文件打开失败，信息没有保存！","确定");
            return;
        }

        QTextStream out(&file);//写入
        out << (s+";"+QString::number(filenum)).toUtf8().constData();
        out << "\n";
        file.close();
}

void menu::on_train_btn_clicked()
{
    string fn_csv = "./facedata/Faces/at.txt";
    vector<Mat> images;
    vector<int> labels;

    //查看是否能读取到csv文件
    try
    {
        read_csv1(fn_csv, images, labels,';');
    }
    catch(cv::Exception& e)
    {
        cerr << "Error opening file \"" << fn_csv << "\". Reason: " << e.msg << endl;
        exit(1);
    }

    //排除最后一张照片，作为测试照片
    testSample = images[images.size() - 1];
    testLabel = labels[labels.size() - 1];
    images.pop_back();
    labels.pop_back();


    //训练自己的模型

    model->train(images, labels);
    model->save("./facedata/MyFacePCAModel.xml");
    qDebug()<<"-------训练完成---------";
}



void menu::on_verify_btn_clicked()
{
    modelPCA->read("./facedata/MyFacePCAModel.xml");




//    int predictedLabel = modelPCA->predict(testSample);//加载分类器
    int predictedLabel = modelPCA->predict(verifyFrame);//加载分类器

    string result_message = format("Predicted class = %d / Actual class = %d.", predictedLabel, testLabel);
    cout << result_message << endl;
}

//使用csv文件去读图像和标签，主要使用stringstream和getline方法
//把图片和标签储存到两个容器中
void menu::read_csv1(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';')
{
    std::ifstream file(filename.c_str(), ifstream::in);
    if (!file)
    {
        string error_message = "No valid input file was given, please check the given filename.";
        CV_Error(CV_StsBadArg, error_message);;
    }
    string line, path, classlabel;
    while (getline(file, line))
    {
        stringstream liness(line);
        getline(liness, path, separator);
        getline(liness, classlabel);
        if (!path.empty() && !classlabel.empty())
        {
            images.push_back(imread(path, 0));
            labels.push_back(atoi(classlabel.c_str()));
        }
    }
}

void menu::on_turn_up_bt_released()
{
    myt->index = 5;
    myt->quit();
}

void menu::on_turn_left_bt_released()
{
    myt->index = 5;
    myt->quit();
}



void menu::on_turn_down_bt_released()
{
    myt->index = 5;
    myt->quit();
}



void menu::on_turn_right_bt_released()
{
    myt->index = 5;
    myt->quit();
}

