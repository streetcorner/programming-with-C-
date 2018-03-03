#include<iostream>
#include<set>

using namespace std;

int main(){
    int t,n,val;
    cin>>t;
    while(t--){
        cin>>n;
        multiset <int> mset;
        for(int i=0; i <n; i++){
            cin>>val;
            mset.insert(val);
        }
        int sum=0;
        while(mset.size() >1){
            int a=* mset.begin();
            mset.erase(mset.begin());
            int b=* mset.begin();
            mset.erase(mset.begin());
            sum+= a+b;
            mset.insert(a+b);
        }
        cout<<sum<<endl;
    }

}
