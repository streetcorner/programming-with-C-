#ifndef USERINFO_H
#define USERINFO_H
#include <QObject>
#include <QtNetWork/QtNetwork>
#include <QDebug>
#include <QMessageBox>
#include "gameboard.h"
#include "Value.h"
#include "Object.h"
#include "Array.h"

class userInfo : public QObject
{
    Q_OBJECT
public:

    explicit userInfo(QObject *parent = 0);
    //QString nickName;
    //QHostAddress userAddress;
    quint16 userPort;

    QTcpSocket *tcpSocket;
    int id;
    int messagex,messagey;
    bool isFive,isGo;

   FiveGameBoard fiveGame;
   GoGameBoard goGame;


signals:
    void removeTcpSocket(QTcpSocket *);
    void newFive();
    void newGo();

    void putStone(Object);
    void goPutStone(Object);
   // void changeTurn(QString, int, int);
    void userWin(Object);

private slots:
    void tcpRecv();
    void tcpSend(Object);
    void tcpDisconnected();
    void changeBoard(Object);

};


#endif // USERINFO_H
