//the final result should also %mod
#include<iostream>
#include<algorithm>

using namespace std;

#define mod 1000000007
int dog[51];

int main(){
    int n;
    cin>>n;
    int dogNum;
    long long ans;

    while(n--){
        cin>> dogNum;
        for(int i =0; i<dogNum; i++){
            cin>>dog[i];
        }
        sort(dog,dog+dogNum);
        ans= dog[0];
        for(int i=1; i<dogNum; i++ ){
            if(dog[i]-i <= 0){
                ans=0;
                break;
            }
            ans= (ans %mod) *(dog[i] -i);
        }
        cout<<ans%mod<<endl;
    }
}
