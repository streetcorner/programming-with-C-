#include "mywidget.h"


myWidget::myWidget(QWidget *parent) : QWidget(parent)
{
    //init board
    initBoard();
    isFive = false;
    isGo = false;
    myTurn=false;

    tcpSocket = new QTcpSocket(this);
    newConnect(); //请求连接

    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(tcpRecv()));
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
}

void myWidget::initBoard(){
    for(int i=0; i<ROAD;i++){
        for(int j=0; j<ROAD; j++){
            board[i][j]=0;
        }
    }
}

void myWidget::newConnect(){
    blockSize = 0; //初始化其为0

    tcpSocket->abort(); //取消已有的连接

    tcpPort = 22222;

    tcpSocket->connectToHost("127.0.0.1", tcpPort);

    //连接到主机，这里从界面获取主机地址和端口号
}

void myWidget::tcpRecv()

{
    QDataStream in(tcpSocket);

    in.setVersion(QDataStream::Qt_4_6);//设置数据流版本，这里要和服务器端相同
    QString str;
    in >> str; //将接收到的数据存放到变量中
    qDebug()<<"in" << str;

    Object obj(str.toStdString());
    QString message = QString::fromStdString(obj["message"].to_string());
    int messagex, messagey;

    //qDebug()<< message << messagex << messagey;

    if(message == "black") localColor=1;
    else if(message == "white") localColor=2;
    else if(message == "putStone"){
        //putstone
        messagex =obj["x"].to_int();
        messagey =obj["y"].to_int();
        myTurn=false;
        //qDebug()<< "putstone and update"<< messagex << messagey<<localColor;
        board[messagex][messagey]=localColor;

        qDebug()<<"2"<<board[messagex][messagey]<< isFive;
        if(isFive){
            update();
            //judge if game was over
             QString gameOver = QString::fromStdString(obj["gameOver"].to_string());
             if(gameOver== "yes")
                 QMessageBox::information(this,"Result","You win!!!");
        }
        else if(isGo){
            if (obj["ifRemoveStone"].to_int()==1){
                qDebug()<<"removestone";
                int num,x,y;
                //Array ary= obj["removeStone"].to_array();
                for(int i=0; i< obj["removeStone"].to_array().size(); i++){
                    num =obj["removeStone"][i].to_int();
                    x= num / 100;
                    y= num % 100;
                    qDebug()<<"removestone"<<num<<x<<y;
                    board[x][y]=0;
                }
            }
            update();
        }
    }
    else if(message == "otherPutStone"){

        messagex =obj["x"].to_int();
        messagey =obj["y"].to_int();

       // qDebug()<< "other putstone and update"<< messagex << messagey<<localColor;
        if(localColor==1)//1 represents black
            board[messagex][messagey]=2;
        else board[messagex][messagey]=1;

        //judge if game was over
        if(isFive){
            update();
            QString gameOver = QString::fromStdString(obj["gameOver"].to_string());

            if(gameOver== "yes")
                QMessageBox::information(this,"Result","You lose...");
            else if(gameOver =="no")
                myTurn=true;
        }
        else if(isGo){
            if (obj["ifRemoveStone"].to_int()==1){
                int num,x,y;
                //Array ary= obj["removeStone"].to_array();
                for(int i=0; i< obj["removeStone"].to_array().size(); i++){
                    num =obj["removeStone"][i].to_int();
                    x= num / 100;
                    y= num % 100;
                    qDebug()<<"removeStone"<<num <<x<<y;
                    board[x][y]=0;
                }
            }
             update();
             myTurn=true;
        }

    }

    else if(message =="gameStart"){
        myTurn =true;
    }
    else if(message =="changeTurn"){
        myTurn=true;
    }


    //显示接收到的数据
}

void myWidget::tcpSend(Object obj){
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6); //设置数据流的版本，客户端和服务器端使用的版本要相同

    out <<QString::fromStdString( obj.to_json());

    qDebug() <<"out obj:"<< QString::fromStdString( obj.to_json());

    tcpSocket->write(datagram);

}

void myWidget::chooseFive(){
    Object obj;
    obj["message"] ="five";
    qDebug()<<"choosefive" <<QString::fromStdString( obj.to_json());

    tcpSend(obj);
}

void myWidget::chooseGo(){
    Object obj;
    obj["message"] ="go";
    //qDebug()<<"choosego" <<QString::fromStdString( obj.to_json());
    tcpSend(obj);
}

void myWidget::displayError(QAbstractSocket::SocketError)

{

    qDebug() << tcpSocket->errorString(); //输出错误信息

}


void myWidget::paintEvent(QPaintEvent *){
    paint=new QPainter;
    paint->begin(this);
    //画棋盘
    paint->setPen(Qt::black);
    for(int i =0; i<19;i++){
        paint->drawLine(QPointF(X0+i*SIZE,Y0), QPointF(X0+i*SIZE,Y0+WIDTH));
    }
    for(int i =0; i<19;i++){
        paint->drawLine(QPointF(X0,Y0+i*SIZE), QPointF(X0+WIDTH,Y0+i*SIZE));
    }
    paint->setBrush(QBrush(Qt::SolidPattern));//设置画笔形式
    for(int i=0; i<ROAD;i++){
        for(int j=0; j<ROAD; j++){
            if(board[i][j] ==1){
                paint->setBrush(QBrush(Qt::black));//设置画笔形式
                paint->setPen(Qt::black);
                paint->drawEllipse(i*SIZE, j*SIZE,SIZE,SIZE);
            }
            else if(board[i][j] ==2){
                paint->setBrush(QBrush(Qt::white));//设置画笔形式
                paint->setPen(Qt::white);
                paint->drawEllipse(i*SIZE, j*SIZE,SIZE,SIZE);
            }
        }

    }
    paint->end();
    //painter.drawLine(QPointF(0,0), QPointF(100,100));
}
//释放鼠标，下棋
void myWidget::mouseReleaseEvent(QMouseEvent *e)
{
    int x,y;
    x =e->pos().rx()/SIZE;
    y =e->pos().ry()/SIZE;

   // qDebug()<<"mouserelease"  <<  x <<" " << y;
    //qDebug()<<"isFive "<<isFive;
    //qDebug()<<"isGo "<<isGo;
    qDebug()<<"myturn "<<myTurn;

    if(myTurn &&(isFive || isGo)){
            Object obj;
            obj["message"]="click";
            obj["x"]=x;
            obj["y"]=y;
            tcpSend(obj);
            //qDebug()<<"choose"<<QString::fromStdString(obj.to_json());
    }

}
