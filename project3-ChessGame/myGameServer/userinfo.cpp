#include "userinfo.h"
#include "QDataStream"


userInfo::userInfo(QObject *parent) : QObject(parent)
{
    isFive=false;
    isGo=false;

    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(tcpRecv()));

    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(tcpDisconnected()));

}

void userInfo::tcpSend(Object obj){
    QByteArray block; //用于暂存我们要发送的数据
    QDataStream out(&block,QIODevice::WriteOnly);//使用数据流写入数据
    out.setVersion(QDataStream::Qt_4_6); //设置数据流的版本，客户端和服务器端使用的版本要相同

   // QString str="fall";

    out << QString::fromStdString(obj.to_json());
    qDebug()<<"out" << QString::fromStdString(obj.to_json());

    tcpSocket->write(block);

}

void userInfo::tcpRecv()

{
   QDataStream in(tcpSocket);
   // QPoint chess;
   QString str;
   in >> str;

   //qDebug() << "in "<<str;
   Object obj(str.toStdString());
   QString message = QString::fromStdString(obj["message"].to_string());

   qDebug()<< message ;
    if(message=="five"){
        if(!isFive){
            isFive =true;
            isGo=false;
            emit newFive();
        }
        //qDebug() << "isFive "<<isFive ;
    }
    else if(message =="go"){
        if(!isGo){
            isGo=true;
            isFive=false;
            emit newGo();
        }
    }

    else if(message=="click"){
        //判断是否放子
       // qDebug()<< "isfive" <<isFive;
        int messagex =obj["x"].to_int();
        int messagey =obj["y"].to_int();

        if(isFive && fiveGame.putStone(messagex,messagey,id))
        {
            qDebug()<<"five putstone"<<messagex<< messagey;
            obj["message"]="putStone";

            int result =fiveGame.checkStone(messagex, messagey);
            //判断是否胜利
            qDebug()<<"result "<<result;

            //if game was over
            if(result !=0)
                obj["gameOver"]="yes";
            else obj["gameOver"]="no";

            //send message to user
            tcpSend(obj);

            //send message to other user
            obj["message"]="otherPutStone";
            emit putStone(obj);

            //else emit changeTurn("yourTurn",1,1);
        }

        if(isGo && goGame.putStone(messagex,messagey,id)){

             //qDebug()<<"go putstone"<<messagex<< messagey;
             obj["stone"]=id;
             obj["message"]="putStone";
             obj["ifRemoveStone"]=0;
             if(goGame.removeStone(messagex,messagey)){
                 obj["removeStone"]=goGame.returnRemove();
                 obj["ifRemoveStone"]=1;
                 qDebug()<<"remove stone";
             }
             tcpSend(obj);

             obj["message"]="otherPutStone";
             emit goPutStone(obj);//
             emit putStone(obj);
        }
    }
    //qDebug()<< str << messagex<<messagey;
}

//removeStone
void userInfo::changeBoard(Object obj){
    //qDebug()<< "changeBoard"<<QString::fromStdString(obj["message"].to_string())<<isGo;
    if( QString::fromStdString( obj["message"].to_string())== "otherPutStone" && isGo){
        goGame.changeBoard( obj["x"].to_int(), obj["y"].to_int(), 3-id);

       // qDebug()<<"changeBoard<<3-id";
    }
    if( obj["ifRemoveStone"].to_int()== 1){
        int num,x,y;
        Array ary= obj["removeStone"].to_array();
        for(int i=0; i< ary.size(); i++){
            num =ary[i].to_int();
            x= num / 100;
            y= num % 100;
            goGame.changeBoard(x, y, 0);
            qDebug()<<"changeStone"<< x<<y;
        }
    }
    //qDebug()<<"changeBoard";
}

void userInfo::tcpDisconnected()
{
    emit removeTcpSocket(tcpSocket);
   // tcpSocket->disconnectFromHost();
}
