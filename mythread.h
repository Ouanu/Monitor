#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <steng.h>
#include <QTimer>
#include <autoptz.h>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);
    bool autobool = false;
    int speed=50;
    int index = 0;
    int chosenum = 0;
    double distance = 0.0;
    double off_set1;
    double off_set2;
    double off_set3;
    double off_set4;

protected:
    void run();


signals:
    void sigDone();

public slots:
    void autorunT();
private:
    setEng sEngthread;
    bool spin_Control_flag = true;
    QTimer *autoTimer;
    autoPtz Eng;


};

#endif // MYTHREAD_H
