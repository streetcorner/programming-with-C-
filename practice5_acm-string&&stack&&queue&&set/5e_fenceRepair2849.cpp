

//attention: 1 ���ִ���10^8,��longlong;
//           2  sort �ᳬʱ
//           3 multiset.erase(),���������ǵ�����
#include<iostream>
#include<set>
using namespace std;

int main(){
    int n;
    multiset <int> mset;
    cin>>n;
    int a;
    for(int i=0; i<n; i++){
        cin>>a;
        mset.insert(a);
    }
   // cout<<mset.size()<<endl;
    long long sum =0;
    while(mset.size()> 1 ){
        //cout<<mset.size()<<endl;
        int a =*mset.begin();
        mset.erase(mset.begin());
        int b =*mset.begin();
        mset.erase(mset.begin());
        sum += a +b ;
        mset.insert(a+b);
        //cout<<mset.size()<<endl;
    }
    cout<<sum<<endl;


}
