#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(){
    vector<int> i_vec;
    cout<<"Please input a sequence of ints:(the end is -1)"<<endl;
    int a;
    while(cin>>a && a!=-1){
        i_vec.push_back(a);
    }
    cout<<"Please cin a target:"<<endl;
    cin>>a;

    cout<<"There are "<< count(i_vec.begin(),i_vec.end(),a)<< "s "<<a<<endl;

}
