#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include<QDebug>
#include<QtMath>
#include "Array.h"

typedef int StoneType;
static const int ROAD=19;

template <int N>
class GameBoard {
    StoneType board[ROAD][ROAD];
    int block[361];
    int blockLen;
    Array removeBlock;
public:
    GameBoard(){
        for(int i=0;i<ROAD;i++)
            for(int j=0; j<ROAD; j++)
                board[i][j]=0;
    }
    void changeBoard(int x, int y, StoneType stone){
        board[x][y]=stone;
    }

    //是否可以放子,有气或者可以反杀的时候放子
    bool putStone(int x, int y, StoneType stone){
       //五子棋
       if(N==15){//如果没有子，就可以放子
            if(board[x][y]== 0){
                board[x][y]=stone;
                return true;
            }
            else return false;
        }
       //围棋
       else if(N==19){

           board[x][y]=stone;

           blockLen=1;
           block[0]=x*100+y;

           //找所下的棋子的block
           recursive(x,y);
           if(!hasQi()){ //既没有气也不能反杀
                qDebug()<<"hasqi";
               if(!removeStone(x,y)){
                    qDebug()<<"removestone";
                     board[x][y]=0;
                     return false;
                }
           }
           return true;
       }
    }

    //DFS
    void recursive(int x, int y){
        //left
        if(x-1 >=0 && board[x][y]==board[x-1][y] && !isInBlock(x-1,y)){//不超过边界+颜色相同+没入block
            block[blockLen]= (x-1)*100 +y;
            blockLen++;
            recursive(x-1, y);
        }
        //right
        if(x+1< 19 && board[x][y]== board[x+1][y] && !isInBlock(x+1,y)){
            block[blockLen]= (x+1)*100 +y;
            blockLen++;
            recursive(x+1, y);
        }
        //up
        if(y-1>= 0 && board[x][y]== board[x][y-1] && !isInBlock(x,y-1)){
            block[blockLen]= x*100 +y-1;
            blockLen++;
            recursive(x, y-1);
        }
        //down
        if(y+1< ROAD && board[x][y]== board[x][y+1] && !isInBlock(x,y+1)){
            block[blockLen]= x*100 +y +1;
            blockLen++;
            recursive(x, y+1);
        }
    }

    bool isInBlock(int x,int y){
        for(int i=0; i<blockLen; i++){
            if(block[i]== x*100+y) return true;
        }
        return false;
    }

    bool hasQi(){
        int x,y;
        for(int i=0; i<blockLen; i++){
            x = block[i]/100;
            y = block[i]%100;
            if(x-1>= 0 && board[x-1][y]==0) return true;
            if(y-1>= 0 && board[x][y-1]==0) return true;
            if(x+1< ROAD && board[x+1][y]==0) return true;
            if(y+1< ROAD && board[x][y+1]==0) return true;
        }
        return false;
    }

    void copyRemove(){//把可以移除的棋子复制到移除数组中
        for(int i=0; i<blockLen; i++){
           // qDebug()<<block[i]/ 100<<"," <<block[i]% 100 <<" =0";
            removeBlock.push_back( block[i]);
        }
        blockLen=0;
    }
    Array returnRemove(){
        for(int i=0; i<removeBlock.size(); i++)
            board[ removeBlock[i].to_int() / 100 ][ removeBlock[i].to_int()% 100]= 0;
        return removeBlock;
    }

    bool removeStone(int x, int y){
        removeBlock.clear();

        //qDebug()<<board[x][y]<<board[x][y-1]<<board[x][y+1]<<board[x-1][y]<<board[x+1][y];

        //left
        if(x-1 >=0 && board[x][y]!=board[x-1][y]&& board[x-1][y]!=0 && !removeBlock.find((x-1)*100+y)){//没超过边界+是对方的子+没在removeblock中
            blockLen=1;
            block[0]=(x-1)*100+y;

            recursive(x-1, y);

            //block中没有气，说明被反杀
            if(!hasQi()) copyRemove();
        }
        //right
        if(x+1 <ROAD && board[x][y]!=board[x+1][y] && board[x+1][y]!=0 && !removeBlock.find((x+1)*100+y)){//没超过边界+是对方的子+没在removeblock中
            blockLen=1;
            block[0]=(x+1)*100+y;

            recursive(x+1, y);

            //block中没有气，说明被反杀
            if(!hasQi()) copyRemove();
        }
        //up
        //qDebug()<<11<<board[x][y]<<" "<<board[x][y-1];
       //qDebug()<<11<<board[x][y]<<" "<<board[x][y+1];
        if(y-1 >=0 && board[x][y]!=board[x][y-1] && board[x][y-1]!=0 && !removeBlock.find( x*100+y-1)){//没超过边界+是对方的子+没在removeblock中
            //qDebug()<<11111;
            blockLen=1;
            block[0]=x*100+y-1;

            recursive(x, y-1);

            //block中没有气，说明被反杀
            if(!hasQi()) copyRemove();
        }
        //up
        if(y+1 <ROAD && board[x][y]!=board[x][y+1] && board[x][y+1]!=0 && !removeBlock.find( x*100+y+1)){//没超过边界+是对方的子+没在removeblock中
            //qDebug()<<2222;
            blockLen=1;
            block[0]=x*100+y+1;

            recursive(x, y+1);

            //block中没有气，说明被反杀
            if(!hasQi()) copyRemove();
        }
        if(removeBlock.size()==0 ) return false;
        else return true;
    }

    //是否出边界
    bool outOfEdge(int x) const{
        if(x<0 || x> (ROAD-1)) return true;
        return false;
    }

    //是否胜利
    StoneType checkStone(int x, int y) const{
        if( N==15){
            int cot=0;
            //竖上方
            for(int i=y-1; i > y-5; i--){
                if(outOfEdge(i)) break;

                if(board[x][y] == board[x][i]) cot++;
                else break;
            }
            //竖下方
            for(int i=y+1; i < y+5;i++){
                if(outOfEdge(i)) break;

                if(board[x][y] != board[x][i]) break;
                else cot++;
            }
           // qDebug()<<"cot"<<cot;

            if(cot >=4) return board[x][y];
            cot=0;

            //横左方
            for(int i=x-1; i > x-5;i--){
                if(outOfEdge(i)) break;
                if(board[x][y] != board[i][y]) break;
                else cot++;

            }
            //横右方
            for(int i=x+1; i < x+5;i++){
                if(outOfEdge(i)) break;
                if(board[x][y] != board[i][y]) break;
                else cot++;

            }
            if(cot >=4) return board[x][y];
            cot=0;

            //斜右上
            for(int i=x+1,j=y-1; i < x+5;i++,j--){
                if(outOfEdge(i)|| outOfEdge(j)) break;
                if(board[x][y] != board[i][j]) break;
                else cot++;

            }

            //斜左下
            for(int i=x-1, j=y+1; i > x-5;i--,j++){
                if(outOfEdge(i)|| outOfEdge(j)) break;

                if(board[x][y] != board[i][j]) break;
                else cot++;
            }
            if(cot >=4) return board[x][y];
            cot=0;

            //斜右下
            for(int i=x+1,j=y+1; i < x+5;i++,j++){
                if(outOfEdge(i)|| outOfEdge(j)) break;

                if(board[x][y] != board[i][j]) break;
                else cot++;

            }
            //斜左上
            for(int i=x-1, j=y-1; i > x-5;i--,j--){
                if(outOfEdge(i)|| outOfEdge(j)) break;

                if(board[x][y] != board[i][j]) break;
                else cot++;

            }
            if(cot >=4) return board[x][y];

            return 0;
        }

    }


    static const int boardSize() {
        return N;
    }
};

typedef GameBoard<15> FiveGameBoard;
typedef GameBoard<19> GoGameBoard;



#endif // GAMEBOARD_H
