/*
 * Author:Wang Yumeng(Lesly)
 * Title:#Project2 main.cpp
 * Abstract:This program is to realize a json by C++.
 * Content: test almost all the function of the json.
*/
#include <iostream>
#include "Value.h"
#include "Object.h"
#include "Array.h"

using namespace std;

int main()
{
    Object obj;
    obj["title"] = "Thinking in C++";
    obj["price"] = 116.01f;
    obj["pages"] = 927;
    obj["haveLunch"] = true;
    obj["authors"] = Array();
    obj["authors"].push_back("Bruce Eckel");
    obj["authors"].push_back("Chuck Allison");
    obj["pub_info"] = Object();
    obj["pub_info"]["name1"] = "China";
    obj["pub_info"]["name2"] = "Machine";
    obj["pub_info"]["name3"] = "Press";

    cout <<"Testing to_json:\n"<< obj.to_json()<<endl<<endl;

    //cout << obj["price"].to_float() << std::endl;
    //cout << obj["authors"][1].to_string() << std::endl;
    //cout << obj["pub_info"]["name2"].to_string() << std::endl<<std::endl;

    string str = "{\"authors\":[\"Bruce Eckel\",\"Chuck Allison\"],\"haveLunch\":true,\"pages\":927,\"price\":116.01,\"pub_info\":{\"name1\":\"China\",\"name2\":\"Machine\",\"name3\":\"Press\"},\"title\":\"Thinking in C++\"}";
string str1="{\"ifRemoveStone\":1,\"message\":\"putStone\",\"removeStone\":[1313, 1213],\"stone\":2,\"x\":14,\"y\":13}";
    Object obj2(str);
    Object obj1(str1);
    cout<<obj1.to_json()<<endl;
    cout<<"Testing jsonParser(Wrote in Object class):\n" << obj2.to_json() << endl<<endl;


    cout<<"The size of the array:\n"<<obj["authors"].to_array().size()<<endl;
    if(!obj["authors"].to_array().empty())
        obj["authors"].to_array().clear();
    cout<<"After cleared, the size of the array:\n"<<obj["authors"].to_array().size()<<endl<<endl;
    cout<<"The size of the object:\n"<<obj["pub_info"].to_object().size()<<endl;
    obj["pub_info"].to_object().erase("name2");
    cout<<"After erase \"name2\", the size of the object:\n"<<obj["pub_info"].to_object().size()<<endl;

}
