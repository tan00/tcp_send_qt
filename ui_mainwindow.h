/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Open;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit_input;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_ip;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_port;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinBox_headLen;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_loops;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_threads;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox_hexsend;
    QCheckBox *checkBox_hexreceive;
    QTextEdit *textEdit_output;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_ping;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_start;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menuTool;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1001, 623);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textEdit_input = new QTextEdit(centralWidget);
        textEdit_input->setObjectName(QStringLiteral("textEdit_input"));
        textEdit_input->setEnabled(true);

        gridLayout_2->addWidget(textEdit_input, 0, 0, 1, 1);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMaximumSize(QSize(260, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_ip = new QLineEdit(frame);
        lineEdit_ip->setObjectName(QStringLiteral("lineEdit_ip"));
        lineEdit_ip->setMaxLength(15);

        horizontalLayout->addWidget(lineEdit_ip);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_port = new QLineEdit(frame);
        lineEdit_port->setObjectName(QStringLiteral("lineEdit_port"));
        lineEdit_port->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_port->setMaxLength(5);

        horizontalLayout_2->addWidget(lineEdit_port);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spinBox_headLen = new QSpinBox(frame);
        spinBox_headLen->setObjectName(QStringLiteral("spinBox_headLen"));
        spinBox_headLen->setWrapping(false);
        spinBox_headLen->setMaximum(9);

        horizontalLayout_3->addWidget(spinBox_headLen);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_loops = new QLineEdit(frame);
        lineEdit_loops->setObjectName(QStringLiteral("lineEdit_loops"));
        lineEdit_loops->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_loops->setMaxLength(7);

        horizontalLayout_4->addWidget(lineEdit_loops);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_threads = new QLineEdit(frame);
        lineEdit_threads->setObjectName(QStringLiteral("lineEdit_threads"));
        lineEdit_threads->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_threads->setMaxLength(7);

        horizontalLayout_5->addWidget(lineEdit_threads);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        checkBox_hexsend = new QCheckBox(frame);
        checkBox_hexsend->setObjectName(QStringLiteral("checkBox_hexsend"));
        checkBox_hexsend->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_2->addWidget(checkBox_hexsend);

        checkBox_hexreceive = new QCheckBox(frame);
        checkBox_hexreceive->setObjectName(QStringLiteral("checkBox_hexreceive"));
        checkBox_hexreceive->setMaximumSize(QSize(236, 16777215));
        checkBox_hexreceive->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_2->addWidget(checkBox_hexreceive);


        verticalLayout->addLayout(verticalLayout_2);


        gridLayout_2->addWidget(frame, 0, 1, 1, 1);

        textEdit_output = new QTextEdit(centralWidget);
        textEdit_output->setObjectName(QStringLiteral("textEdit_output"));
        textEdit_output->setEnabled(true);
        textEdit_output->setAcceptDrops(false);
        textEdit_output->setReadOnly(false);

        gridLayout_2->addWidget(textEdit_output, 1, 0, 1, 1);

        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_ping = new QPushButton(frame_2);
        pushButton_ping->setObjectName(QStringLiteral("pushButton_ping"));

        gridLayout->addWidget(pushButton_ping, 0, 0, 1, 1);

        pushButton_stop = new QPushButton(frame_2);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));

        gridLayout->addWidget(pushButton_stop, 0, 1, 1, 1);

        pushButton_start = new QPushButton(frame_2);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        QIcon icon;
        QString iconThemeName = QStringLiteral("start");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        pushButton_start->setIcon(icon);

        gridLayout->addWidget(pushButton_start, 1, 0, 1, 1);


        gridLayout_2->addWidget(frame_2, 1, 1, 1, 1);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout_2->addWidget(progressBar, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1001, 26));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menuTool = new QMenu(menuBar);
        menuTool->setObjectName(QStringLiteral("menuTool"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(pushButton_stop, pushButton_ping);
        QWidget::setTabOrder(pushButton_ping, textEdit_input);
        QWidget::setTabOrder(textEdit_input, pushButton_start);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menuTool->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menu_File->addAction(action_Open);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "TCP SEND", Q_NULLPTR));
        action_Open->setText(QApplication::translate("MainWindow", "&Open", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "IP", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Port", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "HeadLen", Q_NULLPTR));
        spinBox_headLen->setSuffix(QString());
        label_4->setText(QApplication::translate("MainWindow", "Loops", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Threads", Q_NULLPTR));
        checkBox_hexsend->setText(QApplication::translate("MainWindow", "HexSend", Q_NULLPTR));
        checkBox_hexreceive->setText(QApplication::translate("MainWindow", "HexRec", Q_NULLPTR));
        pushButton_ping->setText(QApplication::translate("MainWindow", "connect", Q_NULLPTR));
        pushButton_stop->setText(QApplication::translate("MainWindow", "stop", Q_NULLPTR));
        pushButton_start->setText(QApplication::translate("MainWindow", "start", Q_NULLPTR));
        menu_File->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuTool->setTitle(QApplication::translate("MainWindow", "Tool", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
