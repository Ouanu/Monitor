#ifndef CMYTHREAD_H
#define CMYTHREAD_H
#include "steng.h"
#include "QThread"


class cmythread : public QThread
{
    Q_OBJECT
public:
//    cmythread();
    explicit cmythread(QObject *parent = 0);
    int num=0;
    bool speed = true;


protected:
    void run();
private:
    setEng csEng;

public slots:
    void turnLeft();
    void turnRight();
    void turnUp();
    void turnDown();
    void init();

};

#endif // CMYTHREAD_H
