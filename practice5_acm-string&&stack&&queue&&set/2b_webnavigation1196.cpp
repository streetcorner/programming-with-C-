/*
VISIT http://acm.ashland.edu/
VISIT http://acm.baylor.edu/acmicpc/
BACK
BACK
BACK
FORWARD
VISIT http://www.ibm.com/
BACK
BACK
FORWARD
FORWARD
FORWARD
QUIT
*/

#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    stack<string> forStack,backStack;
    string str,url="http://www.acm.org/";
    while(cin>>str && str!="QUIT"){
        if(str=="VISIT"){
            backStack.push(url);
            cin>>url;
            cout<<url<<endl;
            while(!forStack.empty())
                forStack.pop();
        }
        else if(str=="BACK"){
            if(!backStack.empty()){
                forStack.push(url);
                url = backStack.top();
                cout<<url<<endl;
                backStack.pop();
            }
            else
                cout<<"Ignored"<<endl;
        }
        else if(str=="FORWARD"){
            if(!forStack.empty()){
                backStack.push(url);
                url =forStack.top();
                cout<<url<<endl;
                forStack.pop();
            }
            else
                cout<<"Ignored"<<endl;
        }
    }
}
