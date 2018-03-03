/*
 * Author:Wang Yumeng(Lesly)
 * Title:#Project2 object.cpp
 * Abstract:This program is to realize a json by C++.
 * Content: 1 object is a jsonObjet.
            2 jsonParser is also wrote in this file, for the convenience of the function call.
*/
#include"Value.h"
#include"Object.h"
#include<stdlib.h>
Object::Object(){}
Object::Object(std::string s) {
    int p = 0;
    *this = read_object(s, p);
}

Object::~Object(){}

Value & Object::operator[] (const std::string & key){
    return obj_map[key];
}

std::string Object::to_json(){
    std::string str="{";
    for(auto i=obj_map.begin(); i!=obj_map.end();i++ ){
        auto j=i;
        if(++j == obj_map.end())
            str+="\""+ i->first +"\""+ ":" + i->second.to_json();
        else
            str+= "\""+ i->first +"\"" + ":" +i->second.to_json()+",";
    }
    str+= "}";
    return str;
}

std::map<std::string,Value>::iterator Object::find(std::string str){
    //string str = cha;
    return obj_map.find(str);
}

std::map<std::string,Value>::iterator Object::begin(){
    return obj_map.begin();
}

std::map<std::string,Value>::iterator Object::end(){
    return obj_map.end();
}

void Object::insert(const std::string &key,const Value &val){
    obj_map.insert(std::pair<std::string,Value>(key,val));
}

void Object::erase(const std::string &str){
    obj_map.erase(find(str));
}

int Object::size() const {
    return obj_map.size();
}

void Object::clear(){
    obj_map.clear();
}


//read until the next position of char ch;
void Object::read_char(const std::string & str, int & p, char ch){
    while(str[p]!= ch){
        p++;
    }
    p++;
}
Object Object::read_object(const std::string & str, int & p){
    Object obj;
    read_char(str, p, '{');
    while (1) {
        std::string key = read_string(str, p);
        read_char(str, p, ':');
        Value val = read_value(str, p);
        // insert key:val to obj.
        obj[key] = val;
        if (str[p] == '}') {
            read_char(str, p, '}');
            break;
        }
        else {
            read_char(str, p, ',');
        }
    }
    return obj;
}

Value Object::read_value(const std::string & str, int & p){
    Value val;
    if (str[p] == '{') {
        val = read_object(str, p);
    }
    else if (str[p] == '\"') {
        val = read_string(str, p);
    }
    else if (str[p] == '[') {
        val = read_array(str, p);
    }
    else if (str[p] == 't' || str[p] == 'f') {
        val = read_bool(str, p);
    }
    else if (str[p] == '-' || isdigit(str[p])) {//isdigit will return true only if all the characters are digits.
        val = read_number(str, p);
    }
    return val;

}
Array Object::read_array(const std::string & str, int & p){
    Array ary;
    read_char(str, p, '[');
    do{
        if(str[p] == ',') read_char(str, p, ',');
        Value val=read_value(str, p);
        ary.push_back(val);
    }while(str[p] == ',' && str[p] != ']');

    if(str[p] ==']')   read_char(str, p, ']');
    return ary;
}

std::string Object::read_string(const std::string & str, int & p){
    read_char(str, p, '\"');
    std::string tmpStr = "";//to restore the key
    while(str[p]!= '\"'){
        tmpStr.append(1,str[p]);
        p++;//read_char(str, p, str[p]);//equals to p++,to read the next char
    }
    read_char(str, p, '\"');//equals to p++
    return tmpStr;
}
bool Object::read_bool(const std::string & str, int & p){
    if(str[p] == 'f'){
        read_char(str, p, 'e');
        return false;
    }
    else{
        read_char(str, p, 'e');
        return true;
    }
}
Value Object::read_number(const std::string & str, int & p){
    Value val;
    bool isPositive =true, isInt=true;
    if(str[p] =='-'){
        isPositive=false;
        read_char(str, p, '-');
    }
    std::string strVal="";
    //read either it's a double or int
    while(str[p]=='.' || isdigit(str[p])){
        if(str[p] =='.') isInt=false;
        strVal+= str[p];
        p++;
    }
    if(isInt){
        int intVal = atoi((char*)strVal.c_str());
        if(!isPositive) intVal = 0-intVal;
        val =Value(intVal);
    }
    else{
        float floatVal = atol((char*)strVal.c_str());
        if(!isPositive) floatVal = 0-floatVal;
        val = Value(floatVal);
    }
    return val;
}



