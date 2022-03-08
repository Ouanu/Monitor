#ifndef AUTOPTZ_H
#define AUTOPTZ_H

#include <QObject>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <QTimer>
#include <QDebug>
#define dev "/dev/sm_stENG"
#define TURN_LR_CTL 0x2
#define TURN_UD_CTL 0x3
#define Kp 2.0

class autoPtz
{
public:
    autoPtz();

    double turnUp(double off_set1);
    double turnDown(double off_set2);
    double turnLeft(double off_set3);
    double turnRight(double off_set4);

private:
    double angLR;
    double angUD;
    int angfd;
};

#endif // AUTOPTZ_H
