#include "steng.h"

//初始化云台设备
setEng::setEng()
{
    angfd = open(dev, O_RDWR);
    if(angfd < 0) qDebug() << "open steng dev fail";
}

//设置云台初始角度
void setEng::backLrpos()
{
    angLR = 75;
    ioctl(angfd, angLR, TURN_LR_CTL);
}


void setEng::backUdpos()
{
    angUD = 67;
    ioctl(angfd, angUD, TURN_UD_CTL);
}


//控制左右偏转角度
void setEng::turnLeft()
{
    angLR--;
    if(angLR<=25) angLR = 25;
    ioctl(angfd, angLR, TURN_LR_CTL);
}

void setEng::turnRight()
{
    angLR++;
    if(angLR>=125) angLR = 125;
    ioctl(angfd, angLR, TURN_LR_CTL);
}

void setEng::setLrAngle(int angle)
{
    angLR = angle + 25;
    if(angLR <= 25) angLR = 25;
    if(angLR >= 125) angLR = 125;
    ioctl(angfd, angLR, TURN_LR_CTL);
}

int setEng::getLrAngle()
{
    return angLR-25;
}

//控制上下偏转角度
void setEng::turnUp()
{
    angUD--;
    if(angUD<=25) angUD = 25;
    ioctl(angfd, angUD, TURN_UD_CTL);
}

void setEng::turnDown()
{
    angUD++;
    if(angUD>=90) angUD = 90;
    ioctl(angfd, angUD, TURN_UD_CTL);
}

void setEng::setUdAngle(int angle)
{
    angUD = angle + 25;
    if(angUD <= 25) angUD = 25;
    if(angUD >= 125) angUD = 125;
    ioctl(angfd, angUD, TURN_UD_CTL);
}

int setEng::getUdAngle()
{
    return angUD-25;
}


