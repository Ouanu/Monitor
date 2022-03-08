#ifndef FACE_TRACKING_THREAD_H
#define FACE_TRACKING_THREAD_H

#include "QThread"
#include "QTimer"
#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/face.hpp>
#include <opencv2/core/cvstd.hpp>
#include <QLabel>
#include "QPushButton"
#include "QProcess"
#include "QFile"


using namespace cv;
using namespace cv::face;
using namespace std;
class face_tracking_thread : public QThread
{
    Q_OBJECT
public:
    explicit face_tracking_thread(QObject *parent = 0);

protected:
    void run();

private slots:
    void task();
    void CaptureOpen();
    void on_get_photo_bt_clicked();
    void on_get_video_bt_clicked();
    void on_catch_video_btn_clicked();
    void face_tracking(void);

private:
    QTimer *capTimer;
    VideoCapture cap;
    VideoWriter writer;
    QLabel *cap_Frame_lb;
    Mat frame;
    Mat lastframe;
    String lasttext;
    bool VidFlag = true;
    int ImgCount = 0;
    int VidCount = 0;
    QPushButton *get_video_bt;
    bool checkvideo = false;
    QProcess process;
    double scale1 = 2.0;
    CascadeClassifier cascade1, nestedCascade1;
    Mat faceframe;
    Mat verifyFrame;
    Ptr<BasicFaceRecognizer> model = EigenFaceRecognizer::create();

    Ptr<FaceRecognizer> modelPCA = EigenFaceRecognizer::create();


};

#endif // FACE_TRACKING_THREAD_H
