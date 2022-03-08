#include "mythread.h"
#include <QDebug>

MyThread::MyThread(QObject* parent):QThread(parent)
{
//    autoTimer = new QTimer();
//    connect(autoTimer, SIGNAL(timeout()), this, SLOT(autorunT()),Qt::DirectConnection);
//    autoTimer->start(10);
}

void MyThread::run()
{
//    sleep(5);

//    qDebug()<<"We in myThread";

    autorunT();

//    emit sigDone();
}

void MyThread::autorunT(){
//    sleep(3);

    if(index == 0){
        sEngthread.backLrpos();
        sEngthread.backUdpos();
        while(!autobool){
            qDebug() << autobool;
            msleep(speed);
            qDebug() << "We in autorun";
            if(spin_Control_flag)
            {
                sEngthread.turnLeft();

                if(sEngthread.getLrAngle() <= 0)
                {
                    spin_Control_flag = false;
                }
            }
            else
            {
                sEngthread.turnRight();
                if(sEngthread.getLrAngle() >= 100)
                {
                    spin_Control_flag = true;
                }

            }
            qDebug() << sEngthread.getLrAngle();
        }

    } else {
        switch(index) {
            case 1:
                while(index == 1){
                    sEngthread.turnLeft();
                    qDebug() << "weinleft";
                    msleep(20);
                }

                break;
            case 2:
                while(index == 2){
                    sEngthread.turnRight();
                    msleep(20);
                }

                break;
            case 3:
                while(index == 3){
                    sEngthread.turnUp();
                    msleep(20);
                }

                break;
            case 4:
                while(index == 4){
                    sEngthread.turnDown();
                    msleep(20);
                }

                break;
            case 6:
                sEngthread.backLrpos();
                sEngthread.backUdpos();
                break;
            case 7:
                Eng.turnUp(off_set1);
            break;
            case 8:
                Eng.turnUp(off_set2);
                break;
            case 9:
                Eng.turnUp(off_set3);
                break;
            case 10:
                Eng.turnUp(off_set4);
                break;

        default: break;
        }
    }

}

