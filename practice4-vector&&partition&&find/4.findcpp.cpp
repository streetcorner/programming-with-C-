#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
using namespace std;

template<class T1,class T2>
T1 Find(T1 first, T1 last, T2 val){
    for(; first!=last; first++){
        if(*first == val)
            return first;
    }
    return last;
}


int main(){
    int in=78;
    string str="toilet";
    vector<int> i_vec ={ 0, 1, 33, 45, 78, 29, 2};
    list<string> s_list={"aa","glass","computer","toilet"};

    cout<<*Find(i_vec.begin(),i_vec.end(),in)<<endl;
    cout<<*Find(s_list.begin(),s_list.end(),str)<<endl;

}
