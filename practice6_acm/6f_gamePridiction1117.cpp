//cin×Ô¶¯ºöÂÔ¿ÕÐÐ
#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

bool cmp(int a, int b){
    return a> b;
}
int main(){
    int m,n,ca=0;
    int card[51];
    while(cin>>m>>n && !(m==0 &&n==0)){
        ca++;
        for(int i=0; i<n; i++){
            cin>>card[i];
        }
        sort(card, card +n,cmp);
        int cur=0,ans=0;
        for(int i=m*n,j=0; j<n; i--){
            //cout<<card[j]<<" "<<i<<" "<<endl;
            if(card[j] == i){
                cur++;
                if(ans< cur) ans=cur;
                j++;
            }
            else cur--;
            //cout<<cur<<endl;
        }
        printf("Case %d: %d\n",ca,ans);

    }
}
