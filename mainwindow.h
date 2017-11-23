#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <queue>
#include "socket_manager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setProcessBar(int val);




private slots:
    void slot_openfile();
    void slot_recive();

    void on_pushButton_ping_clicked();
    void on_pushButton_start_clicked();

private:
    Ui::MainWindow *ui;
    SOCKET_MANAGER sockManager;
    std::queue<QByteArray> m_msg_queue;

private:
    int recCount;
    int  getSendMsgFromCsv(QFile& file);
    void addSendMsgToQueue(QString data,  std::queue<QByteArray>& queue);

    //QNetwork

    void initConfig();
    void setConnect();
    void saveConfig();
    void freshSetting();

};

#endif // MAINWINDOW_H
