#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QListWidget>
#include <QPushButton>
#include <QTcpSocket>
#include <QTcpServer>
#include "userinfo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    userInfo *user1,*user2;

    QTcpServer *tcpServer;
    int numOfUser,numOfFive,numOfGo;

    quint16 tcpPort;

    QList<userInfo*> userList;
    QList<QString> userNameList;
    QList<int> userIdList;


    QListWidget *information;

    QPushButton *start;
    QPushButton *end;
    QString btnStyle;

signals:
    void gameStart(Object);

private slots:
    void sendMessage();
    void addFive();
    void addGo();
    void startService();
    void tcpDisconnected();
    void endService();


    /*
    void tcpConnect();
    //void tcpSendFile(int, int, QString, QByteArray);
    void removeUser(int);
    */

};

#endif // MAINWINDOW_H
