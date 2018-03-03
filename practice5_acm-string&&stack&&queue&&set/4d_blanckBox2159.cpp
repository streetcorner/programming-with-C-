/*
7 4
3 1 -4 2 8 -1000 2
1 2 6 6
*/


#include<iostream>
#include<queue>

using namespace std;

int main(){
    priority_queue<int> q1;
    priority_queue<int, vector<int>,greater<int> > q2;

    int m,n;
    cin>> m>> n;
    long long a[m];
    for(int i=0; i <m; i++)
        cin>> a[i];
    int ct=0,op;
    for(int i =0; i<n; i++){
        cin>> op;
        while(ct < op){
            q2.push(a[ct]);
            if(!q1.empty() && q2.top()<q1.top()){
                int cur2= q2.top();
                int cur1=  q1.top();
                q2.pop();
                q1.pop();
                q2.push( cur1);
                q1.push( cur2);
            }
            ct++;
        }
        cout <<q2.top()<<endl;
        q1.push(q2.top());
        q2.pop();
    }
}
