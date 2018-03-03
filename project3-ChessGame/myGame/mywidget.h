#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QtNetwork/QtNetwork>
#include <QMessageBox>
#include <QtMath>
#include "Value.h"
#include "Object.h"
#include "Array.h"

class myWidget : public QWidget
{
    Q_OBJECT
public:
    const static int SIZE =30;//每格尺寸
    const  static int WIDTH=540;
    const  static int X0 =15, Y0= 15;

    const  static int ROAD=19;

    QPainter *paint;
    bool isFive, isGo;
    bool myTurn;
    int localColor;
    int board[ROAD][ROAD];

    explicit myWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void initBoard();
private:
    QTcpSocket *tcpSocket;
    QString message;  //存放从服务器接收到的字符串
    int messagex, messagey;
    quint16 tcpPort;//端口号
    quint16 blockSize;  //存放文件的大小信息
signals:

public slots:

    void newConnect(); //连接服务器
    void tcpRecv();  //接收数据
    void tcpSend(Object); //发送数据
    //选择游戏go或者five
    void chooseGo();
    void chooseFive();
    void displayError(QAbstractSocket::SocketError);  //显示错误
};

#endif // MYWIDGET_H
