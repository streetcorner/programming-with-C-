#include<iostream>
#include<string>
#include<algorithm>
#include<array>
using namespace std;

int cmp(string a,string b){
    string tmp1,tmp2;
    tmp1=a; tmp2=b;
    transform(tmp1.begin(),tmp1.end(),tmp1.begin(), ::tolower);
    transform(tmp2.begin(),tmp2.end(),tmp2.begin(), ::tolower);
    return tmp1< tmp2;
}

int main(){
    //array<string,4> str={"ddd","Ccc","bbb","aaa"};
    string str[]={"ddd","Ccc","bbb","aaa"};
    //sort(str.begin(),str.end());
    sort(str,str+4, cmp);
    for(int i=0;i <4;i++){
        cout<<str[i]<<" "<<endl;
    }
}

