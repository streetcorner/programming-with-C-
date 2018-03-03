/*
2 ABBAJJKZKZ
3 GACCBDDBAGEE
3 GACCBGDDBAEE
1 ABCBCA
0
*/
//attention: c++中对bool数组的默认值不确定，所以需要初始化
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int main(){
    int numOfBed,curNum,awayNum;
    string customer;
    bool cus[27];
    while(cin>> numOfBed  && numOfBed != 0){
        memset(cus,false,sizeof(cus));
        cin>>customer;
        int curNum =0,ans=0;
        for(int i =0; i<customer.length(); i++){
            int index = customer[i] -'A';
            if(!cus[index]){
                if(curNum< numOfBed){
                    cus[index]=true;//
                    curNum++;
                }
                else//
                    ans++;
            }
            else{
                cus[index]=false;//leave
                curNum--;
            }
            //cout<<"curNum: "<<curNum<<endl;
        }
        int awayNum =ans/2;
         if(awayNum==0)
            cout<<"All customers tanned successfully."<<endl;
        else
            cout<<awayNum<<" customer(s) walked away."<<endl;
    }
}
