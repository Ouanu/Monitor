#include "autoptz.h"

autoPtz::autoPtz()
{
    angfd = open(dev,O_RDWR);
    angLR=75;
    ioctl(angfd,angLR,TURN_LR_CTL);

    angUD=65;
    ioctl(angfd,angUD,TURN_UD_CTL);

}

double autoPtz::turnUp(double off_set1)
{
    angUD =angUD + (off_set1)*Kp;
    if(angUD<25) angUD=25;
    ioctl(angfd,angUD,TURN_UD_CTL);
    return angUD;
}

double autoPtz::turnDown(double off_set2)
{
    angUD = angUD + off_set2*Kp;
    if(angUD>90) angUD=90;
    ioctl(angfd,angUD,TURN_UD_CTL);
    return angUD;
}

double autoPtz::turnLeft(double off_set3)
{
    angLR =angLR - (off_set3)*Kp;
    if(angLR<25) angLR=25;
    ioctl(angfd,angLR,TURN_LR_CTL);
    return angLR;
}

double autoPtz::turnRight(double off_set4)
{
    angLR = angLR-off_set4*Kp;
    if(angLR>125) angLR=125;
    ioctl(angfd,angLR,TURN_LR_CTL);
    return angLR;
}



