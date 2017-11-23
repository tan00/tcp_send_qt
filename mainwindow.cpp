#include "myhelper.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "appSetting.h"
#include "socket_manager.h"
#include "csv.h"
#include <fstream>
#include <string>
#include <vector>


#include <QFile>
#include <QFileDialog>
#include <QMessageBox>


using std::string ;
using std::vector ;
using std::cout ;

enum rowFormat{sn,describe,casetype,sendmsg,recmsg,expect,result};


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusBar();

    initConfig();
    setConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setProcessBar(int val)
{
    ui->progressBar->setValue(val);
}


void MainWindow::initConfig()
{
    AppSetting::ReadConfig();

    ui->lineEdit_ip->setText( AppSetting::TcpServerIP );
    ui->lineEdit_port->setText( QString::number(AppSetting::TcpServerPort) );
    ui->spinBox_headLen->setValue(  AppSetting::Headlen  );
    ui->lineEdit_loops->setText( QString::number(AppSetting::Loops) );
    ui->lineEdit_threads->setText( QString::number(AppSetting::Threads) );
    ui->checkBox_hexsend->setChecked(AppSetting::HexSendTcpClient)  ;
    ui->checkBox_hexreceive->setChecked(AppSetting::HexReceiveTcpClient);
}

void MainWindow::setConnect()
{
    //saveConfig
    connect( ui->lineEdit_ip, QLineEdit::textChanged, this, saveConfig );
    connect( ui->lineEdit_port, QLineEdit::textChanged, this, saveConfig );
    connect( ui->lineEdit_loops, QLineEdit::textChanged, this, saveConfig );
    connect( ui->lineEdit_threads, QLineEdit::textChanged, this, saveConfig );
    connect( ui->spinBox_headLen, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, saveConfig );
    connect( ui->checkBox_hexsend, QCheckBox::stateChanged, this, saveConfig );
    connect( ui->checkBox_hexreceive, QCheckBox::stateChanged, this, saveConfig );

    //打开测试文件
    connect( ui->action_Open, QAction::triggered, this, &slot_openfile );

    //recive
    connect( &sockManager, QAbstractSocket::readyRead, this, &slot_recive );
}

void MainWindow::saveConfig()
{
    freshSetting();
    AppSetting::WriteConfig();
}

void MainWindow::freshSetting()
{
    AppSetting::TcpServerIP = ui->lineEdit_ip->text();
    AppSetting::TcpServerPort = ui->lineEdit_port->text().toInt() ;
    AppSetting::Loops = ui->lineEdit_loops->text().toInt();
    AppSetting::Threads = ui->lineEdit_threads->text().toInt();
    AppSetting::Headlen = ui->spinBox_headLen->value();
    AppSetting::HexSendTcpClient = ui->checkBox_hexsend->isChecked();
    AppSetting::HexReceiveTcpClient = ui->checkBox_hexreceive->isChecked();

}


void MainWindow::on_pushButton_ping_clicked()
{
    setProcessBar(0);
    ui->pushButton_ping->setEnabled(false);
    bool connect_succ = false;
    QStatusBar* sb = statusBar();

    connect_succ = sockManager.connect_server(AppSetting::TcpServerIP , AppSetting::TcpServerPort);
    if(connect_succ){
        int delay = sockManager.getDelay();
        sb->showMessage( tr("delay %1 ms").arg(delay));
    }else{
        sb->showMessage( tr("connect error"));
    }
    ui->pushButton_ping->setEnabled(true);
}





void MainWindow::slot_recive()
{

    if( AppSetting::Threads==1 && AppSetting::Loops==1){
        //setProcessBar(50);
        msleep(20);
    }

    int len = 0;
    QByteArray recLen = sockManager.read(AppSetting::Headlen);

    for(int i=0;i<recLen.length();i++){
        len += ( recLen.at(i) * pow(256,recLen.length()-i-1) );
    }

    QByteArray recData = sockManager.read(len);
    if( recData.isEmpty() || recData.length()!= len )
    {
        //ui->pushButton_start->setEnabled(true);
        //ui->statusBar->showMessage("recive error",10);
        QMessageBox::warning(this, tr("recive"),  tr("recive error"));
        return;
    }


    int msec = sockManager.getDelay();
    QString recString;
    if(AppSetting::HexReceiveTcpClient){
        recString = myHelper::byteArrayToHexStr(recData);
    }else{
        recString = myHelper::byteArrayToAsciiStr(recData);
    }
    ui->textEdit_output->setPlainText(recString);

    //ui->pushButton_start->setEnabled(true);


    //setProcessBar( (recCount/(AppSetting::Loops*2) *100)+50 );

    ui->statusBar->showMessage( tr("time: %1 ms ").arg(msec) );
}


void MainWindow::slot_openfile()
{
    QString path =
            QFileDialog::getOpenFileName(this,
                tr("Open File"),  ".",   tr("Text Files(*.txt);;csv(*.csv)"));
    if(!path.isEmpty()) {
        //QByteArray QBpath =  path.toLocal8Bit();
        //std::ifstream file( QBpath.toStdString() );
        //std::ifstream file( path.toStdString() );
        QFile file(path);

        if ( !file.open(QIODevice::ReadOnly | QIODevice::Text) )
        {
            QMessageBox::warning(this, tr("Read File"),  tr("Cannot open file:\n%1").arg(path));
            return;
        }

        getSendMsgFromCsv(file);
        file.close();

        sockManager.time_start();
        while( !m_msg_queue.empty() ){
            sockManager.write( m_msg_queue.front() );
            m_msg_queue.pop();
        }
        //csv.write( vec, std::cout );
        //QDataStream
        //ui->textEdit_input->setPlainText()
    }

}



void MainWindow::on_pushButton_start_clicked()
{
    recCount = 0;

    QString data = ui->textEdit_input->toPlainText();
    if (data.isEmpty()) {
        ui->statusBar->showMessage( tr("input data is empty") );
        return;
    }

    if (!sockManager.isWritable()) {
        ui->statusBar->showMessage( tr("socket error") );
        return;
    }

    data = data.simplified();
    data = data.remove(' ');
    if( AppSetting::HexSendTcpClient ){
        if( data.contains( QRegExp("[^0-F]") ) ){
            QMessageBox::warning(this, tr("Data error"),  tr("contain invalid character"));
            return ;
        }
    }

    //ui->pushButton_start->setEnabled(false);

    for( int i =0;i<AppSetting::Loops ;i++){
        addSendMsgToQueue( data ,m_msg_queue );
        //setProcessBar( i/(AppSetting::Loops*2) *100 );
    }

    sockManager.time_start();
    while( !m_msg_queue.empty() ){
        sockManager.write( m_msg_queue.front() );
        m_msg_queue.pop();
    }
}



int MainWindow::getSendMsgFromCsv(QFile& file)
{
    Q_ASSERT(file.isReadable());

    QString qstr = file.fileName();
    QByteArray ba =  qstr.toLocal8Bit();

    std::ifstream stdif( ba.toStdString() );

    Csv csv( stdif );

    vector< vector<string> > vec;
    if( csv.read(vec) <=0 ){
        QMessageBox::warning(this, tr("Read File"),  tr("Cannot open file do not contain Chinese char:\n%1").arg(qstr));
        return -1;
    }

    int count = 0;
    for( vector<vector<string> >::iterator iter1 = (vec.begin()+1 );iter1!=vec.end();iter1++)
    {
        QByteArray ba = QByteArray::fromStdString( (*iter1).at(sendmsg) );
        if( ba.length()>0 ){
            addSendMsgToQueue( ba ,m_msg_queue);
            count++;
        }
    }


    return count;
}

void MainWindow::addSendMsgToQueue(QString data, std::queue<QByteArray> &m_msg_queue)
{
    QByteArray buffer;
    if (AppSetting::HexSendTcpClient) {
        buffer = myHelper::hexStrToByteArray(data);
    } else {
        buffer = myHelper::asciiStrToByteArray(data);
    }
    myHelper::addHeadLen(buffer, AppSetting::Headlen);

    m_msg_queue.push(buffer);
}
