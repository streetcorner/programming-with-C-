/*
 * Author:Wang Yumeng(Lesly)
 * Title:#Project2 array.cpp
 * Abstract:This program is to realize a json by C++.
 * Content: array is an element of the jsonObject, it can be composed by Value.
*/
#include<iostream>
#include"Value.h"
#include"Array.h"

Array::Array(){}
Array::~Array(){}

Value & Array::operator[](int index){
    return v_vec[index];
}
void Array::push_back(const Value & val){
    Value v=val;
    //std::cout<<v.to_json()<<" array:push_back"<<std::endl;
    v_vec.push_back(val);
}

std::string Array::to_json(){
    std::string str ="[";
    for(int i=0; i <v_vec.size(); i++){
        if(i == v_vec.size()-1)
            str += v_vec[i].to_json();
        else
             str+= v_vec[i].to_json()+", ";
    }
    str+= "]";
    return str;
}
std::vector<Value>::iterator Array::begin(){
    return v_vec.begin();
}
std::vector<Value>::iterator Array::end(){
    return v_vec.end();
}
bool Array::empty() const{
    return v_vec.empty();
}
int Array::size() const {
    return v_vec.size();
}
void Array::clear(){
    v_vec.clear();
}
