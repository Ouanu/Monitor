#-------------------------------------------------
#
# Project created by QtCreator 2021-10-12T19:58:38
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sMonitor
TEMPLATE = app


SOURCES += main.cpp\
        menu.cpp \
    fops.cpp \
    steng.cpp \
    model.cpp \
    fileIndex.cpp \
    click_lable.cpp \
    fullShow.cpp \
    autoptz.cpp \
    mythread.cpp \
    cmythread.cpp

HEADERS  += menu.h \
    fops.h \
    steng.h \
    model.h \
    fileIndex.h \
    click_lable.h \
    fullShow.h \
    ui_fileIndex.h \
    autoptz.h \
    mythread.h \
    cmythread.h

FORMS    += menu.ui \
    fops.ui \
    model.ui \
    fullShow.ui \
    fileIndex.ui

RESOURCES += \
    images.qrc


INCLUDEPATH += /usr/local/arm/opencv-arm/include\
                /usr/local/arm/opencv-arm/include/opencv\
                /usr/local/arm/opencv-arm/include/opencv2
LIBS += /usr/local/arm/opencv-arm/lib/libopencv_highgui.so\
        /usr/local/arm/opencv-arm/lib/libopencv_core.so \
        /usr/local/arm/opencv-arm/lib/libopencv_imgproc.so \
        /usr/local/arm/opencv-arm/lib/libopencv_imgcodecs.so \
        /usr/local/arm/opencv-arm/lib/libopencv_video.so \
        /usr/local/arm/opencv-arm/lib/libopencv_videoio.so \
        /usr/local/arm/opencv-arm/lib/libopencv_objdetect.so \
        /usr/local/arm/opencv-arm/lib/libopencv_face.so
LIBS += `pkg-config --cflags --libs opencv`


#INCLUDEPATH += /usr/local/include
#LIBS += -L/usr/local/lib/libopencv_highgui.so \
#        /usr/local/lib/libopencv_core.so \
#        /usr/local/lib/libopencv_imgproc.so \
#        /usr/local/lib/libopencv_imgcodecs.so \
#        /usr/local/lib/libopencv_face.so \
#        /usr/local/lib/libopencv_objdetect.so \
#        /usr/local/lib/libopencv_videoio.so

DISTFILES += \
    fileIndex.o \
    click_lable.o
