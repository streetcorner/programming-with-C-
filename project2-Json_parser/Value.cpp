/*
 * Author:Wang Yumeng(Lesly)
 * Title:#Project2 value.cpp
 * Abstract:This program is to realize a json by C++.
 * Content: 1 value can be composed of many type of data, including object and array.

*/
#include<iostream>
#include<sstream>
#include<string>
#include"Value.h"

Value::Value(){}
Value::Value(std::string v) : v_string(v),type(STRING) {}
//array.push_back(const string), the string may  be recognized as char*,but not string.
Value::Value(char *v) : v_string(v),type(STRING) {}
Value::Value(float v) : v_float(v), type(FLOAT) { }
Value::Value(int v) : v_int(v), type(INT) { }
Value::Value(bool v) : v_bool(v), type(BOOL) { }
Value::Value(Object v) : v_object(v), type(OBJECT) { }
Value::Value(Array v) : v_array(v), type(ARRAY) { }
Value::~Value(){}

std::string & Value::to_string(){
    return v_string;
}

float & Value::to_float(){
    return v_float;
}

int & Value::to_int(){
    return v_int;
}

bool & Value::to_bool(){
    return v_bool;
}

Object & Value::to_object(){
    return v_object;
}

Array & Value::to_array(){
    return v_array;
}

//for class object
Value& Value::operator[](const std::string & key){
    return v_object[key];
}

//for class array
Value& Value::operator[](const int & num){
    return v_array[num];
}

Value & Value::operator=(const std::string & v){
    v_string = v;
    type=STRING;
    //std::cout<<v_string<<"string"<<std::endl;
    return *this;
}

Value & Value::operator=(const char * v){
    v_string = v;
    type=STRING;
     //std::cout<<v_string<<"string"<<std::endl;
    return *this;
}

Value & Value::operator=(const float & v){
    v_float = v;
    type=FLOAT;
    return *this;
}

Value & Value::operator=(const int & v){
    v_int = v;
    type=INT;
    //std::cout<<v_string<<"int"<<std::endl;
    return *this;
}

Value & Value::operator=(const bool & v){
    v_bool = v;
    type=BOOL;
    //std::cout<<v_bool<<std::endl;
    return *this;
}

Value & Value::operator=(const Object & v){
    v_object = v;
    type=OBJECT;
    return *this;
}

Value & Value::operator=(const Array & v){
    v_array = v;
    type=ARRAY;
    return *this;
}

std::string Value::to_json(){
    std::string str;
    std::ostringstream os;
    switch(type){
    case STRING:
        str="\""+to_string()+"\"";
       // std::cout<<"stringsssssss"<<std::endl;
        break;
    case FLOAT:
        os<< to_float();
        str =os.str();
        break;
    case INT:
        os<< to_int();
        str = os.str();
       // std::cout<<"iiiiiiiiiii"<<std::endl;
        break;
    case BOOL:
        if(to_bool()) str="true";
        else str="false";
        //std::cout<<"bbbbbbbbbbbbbbbb"<<std::endl;
        break;
    case OBJECT:
        str = to_object().to_json();
        break;
    case ARRAY:
        str = to_array().to_json();
        break;
    case NIL:
        break;
    }
    return str;
}

ValueType Value::get_type(){
    return type;
}

void Value::push_back(Value val) {
    v_array.push_back(val);
}

