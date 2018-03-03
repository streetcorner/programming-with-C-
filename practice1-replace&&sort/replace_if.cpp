#include<iostream>
#include<algorithm>
#include<vector>
#include"Myreplace_if.h"
//谓词，是一种条件
bool predicate(int a){
    if(a<9 & a>2) return 1;
    else return 0;
}
int main(){
    std::vector <int> a;//12 elem
    for(int i=0;i <12;i++)
        a.push_back(i);
    for(int n:a)
        std::cout<<n<<std::endl;
    //std::replace_if(a.begin(),a.end(),predicate,0);
    Myreplace_if(a.begin(),a.end(),predicate,0);
    for(int n:a)
        std::cout<<n<<std::endl;
}
