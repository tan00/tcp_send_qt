#ifndef SOCKET_MANAGER_H
#define SOCKET_MANAGER_H
#include <QTcpSocket>
#include <QString>
#include <QTime>

class SOCKET_MANAGER:public QTcpSocket
{
    Q_OBJECT

public:

    bool connect_server(QString address, int port);
    int  getDelay();
    void time_start();

signals:


private:
    QTime startTime;  //用于记录网络操作耗费的时间

};

#endif // SOCKET_MANAGER_H
