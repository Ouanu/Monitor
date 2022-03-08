#include "face_tracking_thread.h"
#include "QDateTime"

face_tracking_thread::face_tracking_thread(QObject * parent):QThread(parent)
{
}

void face_tracking_thread::run(){

    capTimer = new QTimer(this);
    connect(capTimer, SIGNAL(timeout()),this,SLOT(CaptureOpen()));
//    CaptureOpen();
    cap.open(0);
    capTimer->start(30);
}

void face_tracking_thread::CaptureOpen()
{

    cap >> frame;
//    face_tracking();
//    eyes_tracking();
    Mat frame1;
    cvtColor(frame, frame1, CV_BGR2RGB);
    string text = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss").toUtf8().constData();
    cv::putText(frame, text, cv::Point(0,50), FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255), 1, LINE_AA);
    cv::putText(frame1, text, cv::Point(0,50), FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255), 1, LINE_AA);
    QImage Qimage1 = QImage((const unsigned char*)(frame1.data),
                            frame1.cols, frame1.rows,
                            frame1.step, QImage::Format_RGB888);
    cap_Frame_lb->setPixmap(QPixmap::fromImage(Qimage1));

    cap_Frame_lb->resize(600, 375);
    cap_Frame_lb->show();

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

void face_tracking_thread::on_get_photo_bt_clicked()
{
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

void face_tracking_thread::on_get_video_bt_clicked()
{
    if(VidFlag)
    {
        VidFlag = false;
        checkvideo = true;


        get_video_bt->setText("关闭录制");
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
        get_video_bt->setText("录制");
        checkvideo = false;
        writer.release();
    }
}

void face_tracking_thread::on_catch_video_btn_clicked()
{
    capTimer->start(10);
}

void face_tracking_thread::face_tracking(void)
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
//                Eng.turnRight(x_offset);
                myt->off_set4 = x_offset*2;
                myt->index = 10;
                myt->start();
            }
            if((x_offset) < 0 && (x_offset) >= -1)
            {
//                Eng.turnLeft(x_offset);
                myt->off_set3 = x_offset*2;
                myt->index = 9;
                myt->start();

            }
            //控制舵机上下偏转
            if((y_offset > 0) && (y_offset <= 1))
            {
//                Eng.turnUp(y_offset);
                myt->off_set1 = y_offset*2;
                myt->index = 7;
                myt->start();
            }
            if((y_offset) < 0 && (y_offset) >= -1)
            {
//                Eng.turnDown(y_offset);
                myt->off_set2 = y_offset*2;
                myt->index = 8;
                myt->start();
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
