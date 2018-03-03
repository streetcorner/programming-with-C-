#include<iostream>
#include<vector>
#include"stkclass.h"
#include "Stack.h"


int main(){
    stk <int> s;
    //Stack<int> s;
    s.push(4);
    std::cout<<"size: "<<s.sz()<<std::endl;
    std::cout<<"top: "<<s.top()<<std::endl;


    s.pop();
    std::cout<<"size: "<<s.sz()<<std::endl;
    std::cout<<"top: "<<s.top()<<std::endl;
}

