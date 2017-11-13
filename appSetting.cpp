#include "AppSetting.h"
#include "myhelper.h"

#ifdef __arm__
int AppSetting::LeftPanelWidth = 150;
int AppSetting::RightPanelWidth = 200;
QString AppSetting::PlatForm = "A9";
#else
int AppSetting::LeftPanelWidth = 120;
int AppSetting::RightPanelWidth = 170;
QString AppSetting::PlatForm = "WIN";
#endif

QString AppSetting::SendFileName = "send.txt";
QString AppSetting::DeviceFileName = "device.txt";

bool AppSetting::HexSendTcpServer = false;
bool AppSetting::HexReceiveTcpServer = false;
bool AppSetting::DebugTcpServer = false;
bool AppSetting::AutoSendTcpServer = false;
int AppSetting::IntervalTcpServer = 1000;
int AppSetting::TcpListenPort = 6000;

bool AppSetting::HexSendTcpClient = false;
bool AppSetting::HexReceiveTcpClient = false;
bool AppSetting::DebugTcpClient = false;
bool AppSetting::AutoSendTcpClient = false;
int AppSetting::IntervalTcpClient = 1000;
QString AppSetting::TcpServerIP = "127.0.0.1";
int AppSetting::TcpServerPort = 6000;

bool AppSetting::HexSendUdpServer = false;
bool AppSetting::HexReceiveUdpServer = false;
bool AppSetting::DebugUdpServer = false;
bool AppSetting::AutoSendUdpServer = false;
int AppSetting::IntervalUdpServer = 1000;
int AppSetting::UdpListenPort = 6000;
QString AppSetting::UdpClientIP = "127.0.0.1";
int AppSetting::UdpClientPort = 6000;

void AppSetting::ReadConfig()
{
	if (!CheckConfig()) {
		return;
	}

	QString fileName = QString("%1/%2_Config.ini").arg(AppPath).arg(AppName);
	QSettings set(fileName, QSettings::IniFormat);

	set.beginGroup("AppConfig");
    AppSetting::LeftPanelWidth = set.value("LeftPanelWidth").toInt();
    AppSetting::RightPanelWidth = set.value("RightPanelWidth").toInt();
    AppSetting::PlatForm = set.value("PlatForm").toString();
    AppSetting::SendFileName = set.value("SendFileName").toString();
    AppSetting::DeviceFileName = set.value("DeviceFileName").toString();
	set.endGroup();

    set.beginGroup("TcpClientConfig");
    AppSetting::HexSendTcpClient = set.value("HexSendTcpClient").toBool();
    AppSetting::HexReceiveTcpClient = set.value("HexReceiveTcpClient").toBool();
    AppSetting::DebugTcpClient = set.value("DebugTcpClient").toBool();
    AppSetting::AutoSendTcpClient = set.value("AutoSendTcpClient").toBool();
    AppSetting::IntervalTcpClient = set.value("IntervalTcpClient").toInt();
    AppSetting::TcpServerIP = set.value("TcpServerIP").toString();
    AppSetting::TcpServerPort = set.value("TcpServerPort").toInt();
    set.endGroup();


//	set.beginGroup("TcpServerConfig");
//    AppSetting::HexSendTcpServer = set.value("HexSendTcpServer").toBool();
//    AppSetting::HexReceiveTcpServer = set.value("HexReceiveTcpServer").toBool();
//    AppSetting::DebugTcpServer = set.value("DebugTcpServer").toBool();
//    AppSetting::AutoSendTcpServer = set.value("AutoSendTcpServer").toBool();
//    AppSetting::IntervalTcpServer = set.value("IntervalTcpServer").toInt();
//    AppSetting::TcpListenPort = set.value("TcpListenPort").toInt();
//	set.endGroup();


//	set.beginGroup("UdpServerConfig");
//    AppSetting::HexSendUdpServer = set.value("HexSendUdpServer").toBool();
//    AppSetting::HexReceiveUdpServer = set.value("HexReceiveUdpServer").toBool();
//    AppSetting::DebugUdpServer = set.value("DebugUdpServer").toBool();
//    AppSetting::AutoSendUdpServer = set.value("AutoSendUdpServer").toBool();
//    AppSetting::IntervalUdpServer = set.value("IntervalUdpServer").toInt();
//    AppSetting::UdpListenPort = set.value("UdpListenPort").toInt();
//    AppSetting::UdpClientIP = set.value("UdpClientIP").toString();
//    AppSetting::UdpClientPort = set.value("UdpClientPort").toInt();
//	set.endGroup();
}

void AppSetting::WriteConfig()
{
	QString fileName = QString("%1/%2_Config.ini").arg(AppPath).arg(AppName);
	QSettings set(fileName, QSettings::IniFormat);

	set.beginGroup("AppConfig");
    set.setValue("LeftPanelWidth", AppSetting::LeftPanelWidth);
    set.setValue("RightPanelWidth", AppSetting::RightPanelWidth);
    set.setValue("PlatForm", AppSetting::PlatForm);
    set.setValue("SendFileName", AppSetting::SendFileName);
    set.setValue("DeviceFileName", AppSetting::DeviceFileName);
	set.endGroup();

    set.beginGroup("TcpClientConfig");
    set.setValue("HexSendTcpClient", AppSetting::HexSendTcpClient);
    set.setValue("HexReceiveTcpClient", AppSetting::HexReceiveTcpClient);
    set.setValue("DebugTcpClient", AppSetting::DebugTcpClient);
    set.setValue("AutoSendTcpClient", AppSetting::AutoSendTcpClient);
    set.setValue("IntervalTcpClient", AppSetting::IntervalTcpClient);
    set.setValue("TcpServerIP", AppSetting::TcpServerIP);
    set.setValue("TcpServerPort", AppSetting::TcpServerPort);
    set.endGroup();

//	set.beginGroup("TcpServerConfig");
//	set.setValue("HexSendTcpServer", AppSetting::HexSendTcpServer);
//	set.setValue("HexReceiveTcpServer", AppSetting::HexReceiveTcpServer);
//	set.setValue("DebugTcpServer", AppSetting::DebugTcpServer);
//	set.setValue("AutoSendTcpServer", AppSetting::AutoSendTcpServer);
//	set.setValue("IntervalTcpServer", AppSetting::IntervalTcpServer);
//	set.setValue("TcpListenPort", AppSetting::TcpListenPort);
//	set.endGroup();

//	set.beginGroup("UdpServerConfig");
//	set.setValue("HexSendUdpServer", AppSetting::HexSendUdpServer);
//	set.setValue("HexReceiveUdpServer", AppSetting::HexReceiveUdpServer);
//	set.setValue("DebugUdpServer", AppSetting::DebugUdpServer);
//	set.setValue("AutoSendUdpServer", AppSetting::AutoSendUdpServer);
//	set.setValue("IntervalUdpServer", AppSetting::IntervalUdpServer);
//	set.setValue("UdpListenPort", AppSetting::UdpListenPort);
//    set.setValue("UdpClientIP", AppSetting::UdpClientIP);
//    set.setValue("UdpClientPort", AppSetting::UdpClientPort);
//	set.endGroup();
}

void AppSetting::NewConfig()
{
	WriteConfig();
}

bool AppSetting::CheckConfig()
{
	QString fileName = QString("%1/%2_Config.ini").arg(AppPath).arg(AppName);

	//如果配置文件大小为0,则以初始值继续运行,并生成配置文件
	QFile file(fileName);

	if (file.size() == 0) {
		NewConfig();
		return false;
	}

	//如果配置文件不完整,则以初始值继续运行,并生成配置文件
	if (file.open(QFile::ReadOnly)) {
		bool ok = true;

		while (!file.atEnd()) {
			QString line = file.readLine();
			line = line.replace("\r", "");
			line = line.replace("\n", "");
			QStringList list = line.split("=");

			if (list.count() == 2) {
				if (list.at(1) == "") {
					ok = false;
					break;
				}
			}
		}

		if (!ok) {
			NewConfig();
			return false;
		}
	} else {
		NewConfig();
		return false;
	}

	return true;
}

void AppSetting::WriteError(QString str)
{
	QString fileName = QString("%1/%2_Error_%3.txt").arg(AppPath).arg(AppName).arg(QDATE);
	QFile file(fileName);
	file.open(QIODevice::WriteOnly | QIODevice::Append | QFile::Text);
	QTextStream stream(&file);
	stream << DATETIME << "  " << str << "\n";
}

void AppSetting::NewDir(QString dirName)
{
	//如果路径中包含斜杠字符则说明是绝对路径
	//linux系统路径字符带有 /  windows系统 路径字符带有 :/
	if (!dirName.startsWith("/") && !dirName.contains(":/")) {
		dirName = QString("%1/%2").arg(AppPath).arg(dirName);
	}

	QDir dir(dirName);

	if (!dir.exists()) {
		dir.mkpath(dirName);
	}
}
