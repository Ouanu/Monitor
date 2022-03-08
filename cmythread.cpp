#include "cmythread.h"

cmythread::cmythread(QObject *parent):QThread(parent)
{

}

void cmythread::run(){
//    switch (num) {
//        case 1:
//            csEng.turnLeft();
//            break;
//        case 2:
//            csEng.turnRight();
//            break;
//        case 3:
//            csEng.turnUp();
//            break;
//        case 4:
//            csEng.turnDown();
//            break;
//    default:break;
//    }
}

void cmythread::turnLeft(){
    while(speed){
        csEng.turnLeft();
    }

}

void cmythread::turnRight(){
    while(speed){
        csEng.turnRight();
    }
}

void cmythread::turnUp(){
    while(speed){
        csEng.turnUp();
    }
}

void cmythread::turnDown(){
    while(speed){
        csEng.turnDown();
    }
}

void cmythread::init(){
    csEng.backLrpos();
    csEng.backUdpos();
}

