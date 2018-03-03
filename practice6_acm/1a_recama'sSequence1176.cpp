#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

#define M 500001
#define MAX 10000000

int a[M];
bool p[MAX];

int main(){

    memset(p, false, sizeof(p)); //¿ÉÐ´

    a[0]=0;
    p[0]=true;

    for(int i=1; i<M; i++){
        a[i] =a[i-1]-i;
        if( a[i] <0 || p[a[i]] )
            a[i]= a[i-1]+i;
       // cout<<a[i]<<endl;
        p[a[i]] = true;
    }

    int n;
    while(cin>>n && n!= -1){
        cout<<a[n]<<endl;
    }
}
