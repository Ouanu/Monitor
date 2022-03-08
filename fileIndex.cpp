#include "fileIndex.h"
#include "ui_fileIndex.h"

fileIndex::fileIndex(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fileIndex)
{
    ui->setupUi(this);

    ui->picWidget->hide();
    ui->vidWidget->hide();
    ui->dataWidget->hide();
    ui->insert_init->hide();

    picPath.clear();
    vidPath.clear();
    pvPath.clear();

    //设置窗口样式
    setStyleSheet("background:skyblue;");
    font.setBold(true);
    font.setFamily("楷体");
     //设置窗口尺寸
    IMAGE_SIZE.setWidth(238);
    IMAGE_SIZE.setHeight(160);
    ITEM_SIZE.setWidth(238);
    ITEM_SIZE.setHeight(190);
    ui->picWidget->setIconSize(IMAGE_SIZE);
    ui->picWidget->clear();

    ui->vidWidget->setIconSize(IMAGE_SIZE);
    ui->vidWidget->clear();

    ui->dataWidget->setIconSize(IMAGE_SIZE);
    ui->dataWidget->clear();
     //图片列表基本设置
    ui->picWidget->setResizeMode(QListView::Adjust);
    ui->picWidget->setViewMode(QListView::IconMode);
    ui->picWidget->setMovement(QListView::Static);
    ui->picWidget->setSpacing(8);
    ui->picWidget->clear();
    ui->picWidget->setStyleSheet(
     "QListWidget::Item{padding-top:10px; padding-bottom:4px; }"
     "QListWidget::Item:hover{background:skyblue; }"
     "QListWidget::item:selected{background:lightgreen; color:red; }"
     "QListWidget::item:selected:!active{border-width:0px;"
     "background:lightgreen; }"
     "QListWidget{background:skyblue; }"
    );
    //去除光标
    ui->picWidget->setFocusPolicy(Qt::NoFocus);
    //去除边框
    ui->picWidget->setFrameShape(QListWidget::NoFrame);



    ui->vidWidget->setResizeMode(QListView::Adjust);
    ui->vidWidget->setViewMode(QListView::IconMode);
    ui->vidWidget->setMovement(QListView::Static);
    ui->vidWidget->setSpacing(8);
    ui->vidWidget->clear();
    ui->vidWidget->setStyleSheet(
     "QListWidget::Item{padding-top:10px; padding-bottom:4px; }"
     "QListWidget::Item:hover{background:skyblue; }"
     "QListWidget::item:selected{background:lightgreen; color:red; }"
     "QListWidget::item:selected:!active{border-width:0px;"
     "background:lightgreen; }"
     "QListWidget{background:skyblue; }"
    );
    //去除光标
    ui->vidWidget->setFocusPolicy(Qt::NoFocus);
    //去除边框
    ui->vidWidget->setFrameShape(QListWidget::NoFrame);

    ui->dataWidget->setResizeMode(QListView::Adjust);
    ui->dataWidget->setViewMode(QListView::IconMode);
    ui->dataWidget->setMovement(QListView::Static);
    ui->dataWidget->setSpacing(8);
    ui->dataWidget->clear();
    ui->dataWidget->setStyleSheet(
     "QListWidget::Item{padding-top:10px; padding-bottom:4px; }"
     "QListWidget::Item:hover{background:skyblue; }"
     "QListWidget::item:selected{background:lightgreen; color:red; }"
     "QListWidget::item:selected:!active{border-width:0px;"
     "background:lightgreen; }"
     "QListWidget{background:skyblue; }"
    );
    //去除光标
    ui->dataWidget->setFocusPolicy(Qt::NoFocus);
    //去除边框
    ui->dataWidget->setFrameShape(QListWidget::NoFrame);


    ui->tabWidget->setStyleSheet("QTabWidget#tabWidget{background-color:rgb(255,0,0);}\
                                     QTabBar::tab{background-color:rgb(220,200,180);color:rgb(0,0,0);font:9pt '新宋体'}\
                                     QTabBar::tab::selected{background-color:rgb(0,100,200);color:rgb(255,0,0);font:13pt '新宋体'}");
    //双击图片放大图示
    connect(ui->picWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this,
     SLOT(slot_itemClicked(QListWidgetItem*)));
    connect(ui->vidWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this,
            SLOT(slot_itemClicked(QListWidgetItem*)));

    ui->tabWidget->addTab(ui->picWidget,"图片");
    ui->tabWidget->addTab(ui->vidWidget,"视频");
    ui->tabWidget->addTab(ui->dataWidget,"全部结果");

    msg = new fullShow(this);


    //Tcp传输文件
    m_payloadSize=64*1024;
    m_totalBytes=0;
    m_bytesWritten=0;
    m_bytesToWrite=0;
    m_tcpClient=new QTcpSocket(this);

    connect(m_tcpClient,SIGNAL(connected()),this,SLOT(startTransfer()));
    connect(m_tcpClient,SIGNAL(bytesWritten(qint64)),this,SLOT(updateClientProgress(qint64)));
    connect(m_tcpClient,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    connect(ui->sendButton,SIGNAL(clicked(bool)),this,SLOT(sendBtnClicked()));
    connect(ui->openButton,SIGNAL(clicked(bool)),this,SLOT(openBtnClicked()));

    sendTime = new QTimer(this);
    connect(sendTime, SIGNAL(timeout()),this,SLOT(sendFiles()));
    sendTime->start(500);

}

fileIndex::~fileIndex()
{
    delete ui;
}

void fileIndex::openFile(){
    m_fileName=QFileDialog::getOpenFileName(this);

}

void fileIndex::startTransfer(){
    m_localFile=new QFile(m_fileName);
    qDebug() << m_fileName;
    if(!m_localFile->open(QFile::ReadOnly)){
        qDebug()<<"client：open file error!";
        return;
    }
    m_totalBytes=m_localFile->size();
    QDataStream sendOut(&m_outBlock,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_5_4);
    QString currentFileName=m_fileName.right(m_fileName.size()-m_fileName.lastIndexOf('/')-1);
    //文件总大小、文件名大小、文件名
    sendOut<<qint64(0)<<qint64(0)<<currentFileName;
    m_totalBytes+=m_outBlock.size();
    sendOut.device()->seek(0);
    sendOut<<m_totalBytes<<qint64(m_outBlock.size()-sizeof(qint64)*2);
    m_bytesToWrite=m_totalBytes-m_tcpClient->write(m_outBlock);
    qDebug() << "已连接";
    m_outBlock.resize(0);

}

void fileIndex::updateClientProgress(qint64 numBytes){
    m_bytesWritten+=(int)numBytes;
    if(m_bytesToWrite>0){
        m_outBlock=m_localFile->read(qMin(m_bytesToWrite,m_payloadSize));
        m_bytesToWrite-=(int)m_tcpClient->write(m_outBlock);
        m_outBlock.resize(0);
    }

    else{

        m_localFile->close();
    }


    if(m_bytesWritten==m_totalBytes){
//        ui->clientStatusLabel->setText(QString("传送文件 %1 成功").arg(m_fileName));
        m_localFile->close();
        m_tcpClient->close();
    }


}

void fileIndex::displayError(QAbstractSocket::SocketError){
    qDebug()<<m_tcpClient->errorString();
    m_tcpClient->close();

}

void fileIndex::openBtnClicked(){

    openFile();

}

void fileIndex::sendBtnClicked(){
    m_bytesWritten=0;
    m_tcpClient->connectToHost("192.168.1.179", 8899);
}

void fileIndex::sendFiles(){
    if(q.size() > 0 && m_bytesWritten == m_totalBytes){
        m_fileName = q.head();
        sendBtnClicked();
        q.dequeue();
    }
}

//加载显示图片数据
void fileIndex::updatePicData(QString p_name)
{

    //遍历图片目录
     picPath = p_name;
     QDir dir(picPath);
     if(!dir.exists())
     return;
     dir.setFilter(QDir::Files | QDir::NoSymLinks);
     filters << "*.png" <<"*.jpg";
     dir.setNameFilters(filters);
     picList = dir.entryList();
     if(picList.count() <= 0)
     return ;
     ui->picWidget->clear();

     //添加显示图片数据
     for(int i=0; i<picList.count(); ++i)
     {

         try{
             QPixmap pixmap(picPath + "/" +picList.at(i));
             QListWidgetItem *listWidgetItem = new QListWidgetItem
             (QIcon(pixmap.scaled(IMAGE_SIZE)), picList.at(i));
             listWidgetItem->setFont(QFont(font));
             listWidgetItem->setTextColor(QColor(255,255,255));
             listWidgetItem->setSizeHint(ITEM_SIZE);
             ui->picWidget->insertItem(i, listWidgetItem);
             q.enqueue(picPath + "/" +picList.at(i));
         } catch (Exception e) {
             qDebug() << e.what();
         }

     }

}

//加载显示视频数据
void fileIndex::updataVidData(QString vp_name,QString v_name)
{
    //遍历视频图片目录
//     pvPath = vp_name;
     vidPath = v_name;
//     qDebug()<<"vp_name: "<<vp_name;
     QDir v_dir(vidPath);
     if (!v_dir.exists()) {return;}
     // 设置过滤器
     v_dir.setFilter(QDir::Files | QDir::NoSymLinks);
     QStringList v_filters;
     v_filters << "*.avi"; //插入到字符串列表，形成过滤器
     v_dir.setNameFilters(v_filters);
     vidList = v_dir.entryList(); //获取所有文件名
//    qDebug()<<"vp_name:vidList "<<vidList;
     ui->vidWidget->clear();
     //添加显示图片数据
     for(int i=0; i<vidList.count(); ++i)
     {
         QString vidFile = vidList.at(i).split(".").at(0)+".avi";
//         QPixmap pixmap(pvPath + "/" +vidList.at(i));
         try{
             QPixmap pixmap = getpixmap((vidPath + "/" + vidList.at(i)).toStdString());
             QListWidgetItem *listWidgetItem = new QListWidgetItem
             (QIcon(pixmap.scaled(IMAGE_SIZE)), vidFile);
             listWidgetItem->setFont(QFont(font));
             listWidgetItem->setTextColor(QColor(255,255,255));
             listWidgetItem->setSizeHint(ITEM_SIZE);
             ui->vidWidget->insertItem(i, listWidgetItem);
             q.enqueue(vidPath + "/" + vidList.at(i));
//             qDebug() << vidPath + "/" + vidList.at(i);
             QString soundName = vidList.at(i);
             soundName.replace("avi", "wav");
             q.enqueue("./sound/" + soundName);
         } catch (Exception e) {
             qDebug() << "we got some mistakes";
         }
     }

}

//双击全屏显示或播放
void  fileIndex::slot_itemClicked(QListWidgetItem * item)
{
    QString fileName = item->text();

    //如果是双击图片
    if(fileName.split(".").at(1)=="jpg"||fileName.split(".").at(1)=="png")
    {
        QSize picSize(1024, 600);
        QPixmap pixmap;
        pixmap.load(picPath + "/" + picList.at(ui->picWidget->row(item)));
        QPixmap scaledPixmap = QPixmap(pixmap.scaled(picSize));
//        msg = new fullShow(this);

        //将图像传到全屏窗口显示
        connect(this, SIGNAL(give_message(QPixmap)),msg,SLOT(show_picture(QPixmap)));
        msg->show();

        emit give_message(scaledPixmap);
//        this->hide();
    }
    else if(fileName.split(".").at(1)=="avi"||fileName.split(".").at(1)=="mp4")
    {
            connect(this, SIGNAL(give_vedname(QString)),msg,SLOT(show_video(QString)));
            msg->show();
            emit give_vedname(vidPath + "/" + fileName);
    }

}

void fileIndex::on_exit_bt_clicked()
{
    this->close();

}

void fileIndex::deletefile_pic()
{
    /*获取当前选中的Item*/
    QList<QListWidgetItem*> items = ui->picWidget->selectedItems();

    if (items.count() > 0)
    {

        QString msgtext = items.first()->text();
        //qDebug()<<picPath + "/" +msgtext;
        /*弹出询问对话框*/
        if (QMessageBox::Yes == QMessageBox::question(this, QStringLiteral("Remove Item"),
                                                      "delete " + msgtext, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
        {
            foreach(QListWidgetItem* var, items)
            {
                ui->picWidget->removeItemWidget(var);
                items.removeOne(var);
                delete var;
            }

            QFile file(picPath + "/" +msgtext);
            file.remove();

        }
    }
}

void fileIndex::deletefile_vid()
{
    /*获取当前选中的Item*/
    QList<QListWidgetItem*> items = ui->vidWidget->selectedItems();

    if (items.count() > 0)
    {

        QString msgtext = items.first()->text();
        // qDebug()<<vidPath + "/" +msgtext;
        /*弹出询问对话框*/
        if (QMessageBox::Yes == QMessageBox::question(this, QStringLiteral("Remove Item"),
                                                      "delete " + msgtext, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
        {
            foreach(QListWidgetItem* var, items)
            {
                ui->vidWidget->removeItemWidget(var);
                items.removeOne(var);
                delete var;
            }
            QFile file(vidPath + "/" +msgtext);
            file.remove();
            msgtext.replace("avi", "jpg");
        }
    }
}

void fileIndex::on_deletefile_clicked()
{
    if(ui->tabWidget->currentIndex() == 0){
        deletefile_pic();
    }else if(ui->tabWidget->currentIndex() == 1){
        deletefile_vid();
    }
}

void fileIndex::on_tabWidget_destroyed()
{

}

void fileIndex::on_flashfile_clicked()
{
    if(ui->tabWidget->currentIndex()==0){

        updatePicData("./photo");
    } else if(ui->tabWidget->currentIndex()==1){
        updataVidData("./video/pic", "./video");
    }
}


void fileIndex::rename_pic()
{

    QList<QListWidgetItem*> items = ui->picWidget->selectedItems();

    if (items.count() > 0)
    {
        QString msgtext = items.first()->text();

        QString dlgTitle="改名";
        QString txtLabel="请输入文件名";
        QString defaultInput="new.jpg";
        QLineEdit::EchoMode echoMode=QLineEdit::Normal;//正常文字输入
        bool ok = false;
        QString text = QInputDialog::getText(this, dlgTitle,txtLabel, echoMode,defaultInput, &ok);
        if (ok && !text.isEmpty())
        {
            QFile file(picPath + "/" +msgtext);
            bool ok = file.rename(picPath + "/" +text);
//            ui->picWidget->clear();
            updatePicData(picPath);
        }

    }


}


void fileIndex::rename_vid()
{
    QList<QListWidgetItem*> items = ui->vidWidget->selectedItems();

    if (items.count() > 0)
    {
        QString msgtext = items.first()->text();

        QString dlgTitle="改名";
        QString txtLabel="请输入文件名";
        QString defaultInput="new.avi";
        QLineEdit::EchoMode echoMode=QLineEdit::Normal;//正常文字输入
        bool ok = false;
        QString text = QInputDialog::getText(this, dlgTitle,txtLabel, echoMode,defaultInput, &ok);
        if (ok && !text.isEmpty())
        {
            QFile file(vidPath + "/" +msgtext);
            bool ok = file.rename(vidPath + "/" +text);
            msgtext.replace("avi", "jpg");
            QFile file1(pvPath + "/" +msgtext);
            text.replace("avi", "jpg");
            bool ok1 = file1.rename(pvPath + "/" +text);
//            ui->vidWidget->clear();
            updataVidData("./video/pic", "./video");
        }
    }
}


void fileIndex::on_rename_clicked()
{
    if(ui->tabWidget->currentIndex()==0){
        rename_pic();
    }else if(ui->tabWidget->currentIndex()==1){
        rename_vid();
    }
}



void fileIndex::search_pic()
{
    ui->picWidget->clear();
    searchList.clear();
    QString dlgTitle="搜索";
    QString txtLabel="请输入文件名";
    QString defaultInput="";
    QLineEdit::EchoMode echoMode=QLineEdit::Normal;//正常文字输入
    bool ok = false;
    QString text = QInputDialog::getText(this, dlgTitle,txtLabel, echoMode,defaultInput, &ok);
    qDebug()<< text;
    if (ok && !text.isEmpty())
    {
        //遍历图片目录
         searchfilters.clear();
         picPath = "./photo";
         QDir dir(picPath);
         if(!dir.exists())
         return;
         dir.setFilter(QDir::Files | QDir::NoSymLinks);
         searchfilters << "*.jpg";
         qDebug()<< "text:" << text;
         dir.setNameFilters(searchfilters);
         qDebug()<<"searchList:"<<searchList;
         searchList = dir.entryList();

         if(searchList.count() <= 0)
         return ;

         //添加显示图片数据
         for(int i=0; i<searchList.count(); ++i)
         {
            if(searchList[i].contains(text, Qt::CaseSensitive)){
                QPixmap pixmap_pic(picPath + "/" +picList.at(i));
                QListWidgetItem *listWidgetItemPic = new QListWidgetItem
                (QIcon(pixmap_pic.scaled(IMAGE_SIZE)), picList.at(i));
                listWidgetItemPic->setFont(QFont(font));
                listWidgetItemPic->setTextColor(QColor(255,255,255));
                listWidgetItemPic->setSizeHint(ITEM_SIZE);
                ui->picWidget->insertItem(i, listWidgetItemPic);
            }
         }
    }
}

void fileIndex::search_vid()
{
    ui->vidWidget->clear();
    searchList.clear();
    QString dlgTitle="搜索";
    QString txtLabel="请输入文件名";
    QString defaultInput="";
    QLineEdit::EchoMode echoMode=QLineEdit::Normal;//正常文字输入
    bool ok = false;
    QString text = QInputDialog::getText(this, dlgTitle,txtLabel, echoMode,defaultInput, &ok);
    qDebug()<< text;
    if (ok && !text.isEmpty())
    {
        //遍历视频图片目录
        searchfilters.clear();
//         pvPath = "./video/pic";
         vidPath = "./video";
         QDir v_dir(vidPath);
         if (!v_dir.exists()) {return;}
         // 设置过滤器
         v_dir.setFilter(QDir::Files | QDir::NoSymLinks);
         QStringList v_filters;
         v_filters << "*.avi"; //插入到字符串列表，形成过滤器
         v_dir.setNameFilters(v_filters);
         searchList = v_dir.entryList(); //获取所有文件名

         ui->vidWidget->clear();
         //添加显示图片数据
         for(int i=0; i<searchList.count(); ++i)
         {
             if(searchList[i].contains(text, Qt::CaseSensitive)){
                 QString vidFile = vidList.at(i).split(".").at(0)+".avi";
//                 QPixmap pixmap(pvPath + "/" +vidList.at(i));
                 QPixmap pixmap = getpixmap((vidPath + '/' + searchList.at(i)).toStdString());
                 QListWidgetItem *listWidgetItem = new QListWidgetItem
                 (QIcon(pixmap.scaled(IMAGE_SIZE)), vidFile);
                 listWidgetItem->setFont(QFont(font));
                 listWidgetItem->setTextColor(QColor(255,255,255));
                 listWidgetItem->setSizeHint(ITEM_SIZE);
                 ui->vidWidget->insertItem(i, listWidgetItem);
             }
         }
    }
}

void fileIndex::on_search_clicked()
{
    if(ui->tabWidget->currentIndex()==0){
        search_pic();
    }else if(ui->tabWidget->currentIndex()==1){
        search_vid();
    }
}


void fileIndex::insert_pic(){
    //遍历图片目录
    flag = true;
     dataPath = ltFilePath.first();
     dataList.clear();
     QDir dir(dataPath);
     if(!dir.exists())
     return;
     dir.setFilter(QDir::Files | QDir::NoSymLinks);
     filters.clear();
     filters << "*.png" <<"*.jpg";
     dir.setNameFilters(filters);
     dataList = dir.entryList();
     if(dataList.count() <= 0)
     return ;
     ui->dataWidget->clear();
     //添加显示图片数据
     for(int i=0; i<dataList.count(); ++i)
     {
         qDebug() << dataPath + "/" +dataList.at(i);
         QPixmap pixmap(dataPath + "/" +dataList.at(i));
         QListWidgetItem *listWidgetItem = new QListWidgetItem
         (QIcon(pixmap.scaled(IMAGE_SIZE)), dataList.at(i));
         listWidgetItem->setFont(QFont(font));
         listWidgetItem->setTextColor(QColor(255,255,255));
         listWidgetItem->setSizeHint(ITEM_SIZE);
         ui->dataWidget->insertItem(i, listWidgetItem);
     }
}

void fileIndex::insert_vid(){
    //遍历视频图片目录
     ui->dataWidget->clear();
     dataList.clear();
//     pvPath = "./other/pic";
     vidPath = ltFilePath.first();
     QDir v_dir(vidPath);
     if (!v_dir.exists()) {return;}
     // 设置过滤器
     v_dir.setFilter(QDir::Files | QDir::NoSymLinks);
     QStringList v_filters;
     v_filters << "*.avi"; //插入到字符串列表，形成过滤器
     v_dir.setNameFilters(v_filters);
     dataList = v_dir.entryList(); //获取所有文件名
     //添加显示图片数据
     for(int i=0; i<dataList.count(); ++i)
     {

         QString vidFile = dataList.at(i).split(".").at(0)+".avi";
         QPixmap pixmap = getpixmap((vidPath + '/' + dataList.at(i)).toStdString());
         QListWidgetItem *listWidgetItem = new QListWidgetItem
         (QIcon(pixmap.scaled(IMAGE_SIZE)), vidFile);
         listWidgetItem->setFont(QFont(font));
         listWidgetItem->setTextColor(QColor(255,255,255));
         listWidgetItem->setSizeHint(ITEM_SIZE);
         ui->dataWidget->insertItem(i, listWidgetItem);
     }

}

void fileIndex::on_pushButton_clicked()
{

    QFileDialog dialog(this, tr("Open Files"));
    dialog.setAcceptMode(QFileDialog::AcceptOpen);  ///< 打开文件? 好像默认就是
    dialog.setModal(QFileDialog::ExistingFiles);
    dialog.setOption(QFileDialog::DontUseNativeDialog); ///< 不是用本地对话框
    dialog.resize(QSize(1024,600));
    dialog.exec();
    ltFilePath = dialog.selectedFiles();
    qDebug() << ltFilePath;
//    insert_pic();
//    tabindex = 0;
    if(ui->tabWidget->currentIndex()==0){
        insert_pic();
        tabindex=0;
    }else if(ui->tabWidget->currentIndex()==1){
        insert_vid();
        tabindex=1;
    }
    ui->insert_init->show();

}

void fileIndex::on_insert_init_clicked()
{
    QList<QListWidgetItem*> items = ui->dataWidget->selectedItems();
    if (items.count() > 0)
    {

        QString msgtext = items.first()->text();
        // qDebug()<<vidPath + "/" +msgtext;
        /*弹出询问对话框*/
        if (QMessageBox::Yes == QMessageBox::question(this, QStringLiteral("Remove Item"),
                                                      "delete " + msgtext, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
        {
            foreach(QListWidgetItem* var, items)
            {
                ui->dataWidget->removeItemWidget(var);
                items.removeOne(var);
                delete var;
            }
            if(tabindex==0){
                dataPath.clear();
                dataPath = ltFilePath.first();
                picPath.clear();
                picPath = "./photo/" + msgtext;
//                QFile file(dataPath + "/" + msgtext);
                qDebug() << dataPath + "/" + msgtext;
                QFile::copy(dataPath + "/" + msgtext, picPath);
            } else if(tabindex==1){
                dataPath.clear();
                dataPath = ltFilePath.first();
                vidPath.clear();
                vidPath = "./video/" + msgtext;
//                QFile file(dataPath + "/" + msgtext);
                qDebug() << dataPath + "/" + msgtext;
                QFile::copy(dataPath + "/" + msgtext, vidPath);
            }

        }
    }
}

QPixmap fileIndex::getpixmap(const String &path){
    VideoCapture vc(path);
    Mat framep;
    vc >> framep;
    cvtColor(framep, framep, CV_BGR2RGB);
    QImage Qimage1 = QImage((const unsigned char*)(framep.data),
                            framep.cols, framep.rows,
                            framep.step, QImage::Format_RGB888);
    return QPixmap::fromImage(Qimage1);
}
