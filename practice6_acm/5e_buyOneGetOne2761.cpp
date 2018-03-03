//就算每个文件一组例子，输出结果的最后应该有空行
#include<iostream>
#include<algorithm>

#define M 1000001

using namespace std;

int high[M],low[M];
bool cmp(int a, int b){
    return a> b;
}
int main(){
    int hi, lo, ans=0;
    cin>>hi>>lo;
    for(int i=0;i <hi; i++){
        cin>>high[i];
    }
    for(int i=0;i <lo; i++){
        cin>>low[i];
    }
    sort(high, high+hi, cmp);
    sort(low, low+lo, cmp);
    low[lo] =0;
    for(int i=0,j=0; i<hi; i++){
        while(high[i] <= low[j])
            j++;
        if(low[j]==0){
             break;
        }
        ans++;
        j++;
    }
    ans+= hi;
    cout<<ans<<endl;
}
