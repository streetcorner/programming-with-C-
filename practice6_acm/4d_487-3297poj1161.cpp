//auto cannot be used in toj
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<stdio.h>

using namespace std;

int main(){
    map<string ,int> num;
    int n;
    string str="";
    char ch;

    cin>>n;
    while (n--){
        while(1){
            cin>>ch;

            if((ch=='-')) continue;

            if(ch=='A' ||ch=='B'||ch=='C')
                ch='2';
            else if(ch=='D' ||ch=='E'||ch=='F')
                ch='3';
            else if(ch=='G' ||ch=='H'||ch=='I')
                ch='4';
            else if(ch=='J' ||ch=='K'||ch=='L')
                ch='5';
            else if(ch=='M' ||ch=='N'||ch=='O')
                ch='6';
            else if(ch=='P' ||ch=='R'||ch=='S')
                ch='7';
            else if(ch=='T' ||ch=='U'||ch=='V')
                ch='8';
            else if(ch=='W' ||ch=='X'||ch=='Y')
                ch='9';
            str+=ch;
            if(str.length()== 7){
                str.insert(3,"-");
                num[str]++;
                str="";
                break;
            }
        }
    }
    bool f= true;
     for(map<string,int>::iterator i= num.begin(); i!= num.end(); i++){
        //cout<<i->first<<" "<<i->second<<endl;
        if(i->second > 1){
            f=false;
            cout<<i->first<<" "<<i->second<<endl;
        }
    }
    if(f) cout<<"No duplicates."<<endl;

}
