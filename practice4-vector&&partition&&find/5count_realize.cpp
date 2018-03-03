#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
using namespace std;

const double D_EPSINON = 0.000001;
const float F_EPSINON = 0.000001;

template<class T1,class T2>
int Count(T1 first, T1 last, const T2 val){
    int ct=0;
    for(; first!=last; first++){
        if(*first == val)
            ct++;
    }
    return ct;
}
template<class T1>
int Count(T1 first, T1 last, const double val){
    int ct=0;
    for(; first!=last; first++){
        if(fabs(*first -val)< D_EPSINON)
            ct++;
    }
    return ct;
}
template<class T1>
int Count(T1 first, T1 last, const float val){
    int ct=0;
    for(; first!=last; first++){
        if(fabs(*first -val)< F_EPSINON)
            ct++;
    }
    return ct;
}
int main(){
    double db = 3.33;
    int in= 45;
    string str= "China";
    vector<double> d_vec={0.1, 0.4, 5.3, 3.33, 3.3300000002, 4.4, 3.330};
    vector<int> i_vec= { 3, 45, 53, 32, 33, 45, 66, 43, 54 ,44, 45};
    vector<string> s_vec= {"aaaa", "Polytech", "China", "Nice"};

    cout<<db<<endl;
    cout<<"The num of double "<<db<<": "<<Count(d_vec.begin(),d_vec.end(),db)<<endl;
    cout<<"The num of int "<<in<<": "<<Count(i_vec.begin(),i_vec.end(),in)<<endl;
    cout<<"The num of string "<<str<<": "<<Count(s_vec.begin(),s_vec.end(),str)<<endl;

}
