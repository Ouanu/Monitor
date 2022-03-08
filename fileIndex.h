#ifndef SHOW_FILE_H
#define SHOW_FILE_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QListWidget>
#include <QDir>
#include <QLabel>
#include "fullShow.h"
#include "click_lable.h"
#include "QMessageBox"
#include "QLineEdit"
#include "QInputDialog"
#include "QFileDialog"
#include <opencv2/highgui/highgui.hpp>
#include <QImage>
#include <opencv2/imgproc/imgproc.hpp>
#include <QProcess>
#include "QTcpSocket"
#include <QAbstractSocket>
#include <QFile>
#include <QQueue>
#include <QTimer>

using namespace cv;
namespace Ui {
class fileIndex;
}

class fileIndex : public QMainWindow
{
    Q_OBJECT

public:
    explicit fileIndex(QWidget *parent = 0);
    ~fileIndex();
    void updatePicData(QString p_name);
    void updataVidData(QString vp_name,QString v_name);
    void deletefile_pic();
    void deletefile_vid();
signals:
    void give_message(QPixmap message);
    void give_vedname(QString ved_name);
public slots:
    void openFile();
    void startTransfer();
    void updateClientProgress(qint64);
    void displayError(QAbstractSocket::SocketError);
    void openBtnClicked();
    void sendBtnClicked();

private slots:
     void slot_itemClicked(QListWidgetItem * item);

     void on_exit_bt_clicked();

     void on_deletefile_clicked();

     void on_tabWidget_destroyed();

     void on_flashfile_clicked();

     void rename_vid();

     void rename_pic();

     void on_rename_clicked();

     void on_search_clicked();

     void search_pic();
     void search_vid();
     void insert_pic();
     void insert_vid();
     void on_pushButton_clicked();

     void on_insert_init_clicked();

     void sendFiles();

     QPixmap getpixmap(const String &path);


private:
    Ui::fileIndex *ui;

    QString picPath,pvPath,vidPath,dataPath;
    QStringList picList;      // 文件目录下所有的图像文件名
    QStringList vidList;      // 文件目录下所有的图像文件名
    fullShow *msg;
    QStringList filters;
    QStringList searchfilters;
    QFont font;
    QSize IMAGE_SIZE;
    QSize ITEM_SIZE;

    QStringList searchList;
    QStringList dataList;
    QStringList ltFilePath;

    bool flag = false;

    int tabindex;

    QProcess process;

    //传送文件
    QTcpSocket *m_tcpClient;
    QFile *m_localFile;
    qint64 m_totalBytes;
    qint64 m_bytesWritten;
    qint64 m_bytesToWrite;
    qint64 m_payloadSize;
    QString m_fileName;
    QByteArray m_outBlock;

    QQueue<QString> q;
    QTimer *sendTime;
};

#endif // SHOW_FILE_H
