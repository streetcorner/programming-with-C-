/*

1
6
1 2 13 14 15 16
5
add 5
add 3
mid
add 20
mid
*/

#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main(){
    int t,n,m,val;
    string str;
    cin>>t;
    while(t--){
        priority_queue<int> q1;
        priority_queue<int, vector<int>, greater<int> >q2;

        cin>>n;
        for(int i=0;i <n; i++){
            cin>>val;
            q1.push(val);
            if(!q2.empty() && q2.top()< q1.top()){
                int cur1 = q1.top();
                int cur2 = q2.top();
                q1.pop();
                q2.pop();
                q1.push(cur2);
                q2.push(cur1);
            }
            if((q1.size()-q2.size()) > 1){
                int cur=q1.top();
                q1.pop();
                q2.push(cur);
            }

        }

        cin>>m;
        while(m--){
            string op;
            cin>>op;
            if(op=="add"){
                cin>>val;
                q1.push(val);
                if(!q2.empty() && q2.top()< q1.top()){
                    int cur1 = q1.top();
                    int cur2 = q2.top();
                    q1.pop();
                    q2.pop();
                    q1.push(cur2);
                    q2.push(cur1);
                }
                if((q1.size()-q2.size()) > 1){
                    int cur=q1.top();
                    q1.pop();
                    q2.push(cur);
                }
            }
            else if(op=="mid"){
                cout<<q1.top()<<endl;
            }
        }
    }
}
