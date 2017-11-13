#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "appSetting.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initConfig()
{
    AppSetting::ReadConfig();

    ui->lineEdit_ip->setText( AppSetting::TcpServerIP );
    ui->lineEdit_port->setText( AppSetting::TcpServerPort );
    ui->spinBox_headLen->setValue(  AppSetting::HEADLEN  );
    ui->lineEdit_loops->setText( AppSetting::LOOPS );
    ui->lineEdit_threads->setText( AppSetting::THREADS );
    ui->checkBox_hexsend->setChecked(AppSetting::HexSendTcpClient)  ;
    ui->checkBox_hexreceive->setChecked(AppSetting::HexReceiveTcpClient);
}

