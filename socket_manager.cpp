#include "socket_manager.h"




bool SOCKET_MANAGER::connect_server(QString address, int port)
{
    abort();
    time_start();
    connectToHost(address , port);
    return waitForConnected(2000);
}


int SOCKET_MANAGER::getDelay()
{
    return startTime.elapsed();
}

void SOCKET_MANAGER::time_start()
{
    startTime.restart();
}
