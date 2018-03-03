#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    user1 = new userInfo(this);
    user2 = new userInfo(this);
    numOfUser=0;
    numOfFive=0;
    numOfGo=0;
    ui->setupUi(this);
    this->setFixedSize(500, 400);
    this->setWindowTitle("Server");

    tcpServer = new QTcpServer(this);
    if(!tcpServer->listen(QHostAddress::LocalHost,tcpPort))

        {  //监听本地主机的6666端口，如果出错就输出错误信息，并关闭

            qDebug() << tcpServer->errorString();

            close();

        }

     connect(tcpServer,SIGNAL(newConnection()),this,SLOT(sendMessage()));

    //连接信号和相应槽函数

    information = new QListWidget(this);
    information->setGeometry(10, 10, 480, 300);

    btnStyle = "QPushButton{font-size: 30px;}";
    start = new QPushButton("start", this);
    start->setStyleSheet(btnStyle);
    start->setGeometry(50, 330, 150, 60);
    end = new QPushButton("end", this);
    end->setStyleSheet(btnStyle);
    end->setGeometry(300, 330, 150, 60);
    end->setEnabled(false);

    //service
    connect(start, SIGNAL(clicked(bool)), this, SLOT(startService()));
    connect(end, SIGNAL(clicked(bool)), this, SLOT(endService()));

    //when disconnected numOfUser--
    connect(user1->tcpSocket, SIGNAL(disconnected()), this, SLOT(tcpDisconnected()));
    connect(user2->tcpSocket, SIGNAL(disconnected()), this, SLOT(tcpDisconnected()));

    //add user and judge if the game should begin
    connect(user1, SIGNAL(newFive()), this, SLOT(addFive()));
    connect(user2, SIGNAL(newFive()), this, SLOT(addFive()));

    connect(user1, SIGNAL(newGo()), this, SLOT(addGo()));
    connect(user2, SIGNAL(newGo()), this, SLOT(addGo()));

    //game begin
    connect(this, SIGNAL(gameStart(Object)), user1, SLOT(tcpSend(Object)));

    //putStone and judge if gameOver, if not,changeTurn
    connect(user1, SIGNAL(putStone(Object)), user2, SLOT(tcpSend(Object)));
    connect(user2, SIGNAL(putStone(Object)), user1, SLOT(tcpSend(Object)));

    //record the remove stones and send to another user
    connect(user1, SIGNAL(goPutStone(Object)), user2, SLOT(changeBoard(Object)));
    connect(user2, SIGNAL(goPutStone(Object)), user1, SLOT(changeBoard(Object)));

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tcpDisconnected(){
    numOfUser--;
}

void MainWindow::addFive(){
    numOfFive++;
    if(numOfFive==2){
        numOfFive=0;
        Object obj;
        obj["message"] ="gameStart";
        emit gameStart(obj);
    }
}

void MainWindow::addGo(){
    numOfGo++;
    if(numOfGo==2){
        numOfGo=0;
        Object obj;
        obj["message"] ="gameStart";
        emit gameStart(obj);
    }
}

//一连接上就发送信息。
void MainWindow::sendMessage(){

    QByteArray block; //用于暂存我们要发送的数据
    QDataStream out(&block,QIODevice::WriteOnly);//使用数据流写入数据
    out.setVersion(QDataStream::Qt_4_6); //设置数据流的版本，客户端和服务器端使用的版本要相同

    //一建立连接就发送先手
    Object obj;
    if(numOfUser ==0)
        obj["message"]="black";
    else if(numOfUser ==1 )
        obj["message"]="white";

     out << QString::fromStdString( obj.to_json());

    QTcpSocket *clientConnection= tcpServer->nextPendingConnection();//获取已经建立的连接的子套接字
    if(numOfUser ==0 ){

        user1->tcpSocket->setSocketDescriptor(clientConnection->socketDescriptor());
        numOfUser++;
        user1->id =numOfUser;
    }
    else if(numOfUser ==1 ){

        user2->tcpSocket->setSocketDescriptor(clientConnection->socketDescriptor());
        numOfUser++;
        user2->id =numOfUser;

    }

   // connect(clientConnection,SIGNAL(disconnected()),clientConnection,SLOT(deleteLater()));
    clientConnection->write(block);
   // clientConnection->disconnectFromHost();//发完就断开
    information->addItem("send message successful!!!");
}

void MainWindow::startService()
{
    //新建服务器
    tcpServer = new QTcpServer(this);
    tcpPort = 22222;
    tcpServer->listen(QHostAddress::Any, tcpPort);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(sendMessage()));
    start->setEnabled(false);
    end->setEnabled(true);
    information->addItem("Server started.");
}

void MainWindow::endService()
{
    delete tcpServer;
    userList.clear();
    userIdList.clear();
    //userNameList.clear();
    start->setEnabled(true);
    end->setEnabled(false);
    information->addItem("Server closed.");
}
