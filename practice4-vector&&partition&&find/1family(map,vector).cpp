#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<map>
#include<vector>
#include<iostream>
using namespace std;

int main(){
    map<string, vector<string>> fam;
    fam["Wang"];
    fam["Wang"].push_back("wang yumeng");
    fam["Wang"].push_back("wang xuhong");

    fam["Li"];
    fam["Li"].push_back("li nan");
    fam["Li"].push_back("li mengke");

    cout<<fam["Wang"][0]<<endl;
    cout<<fam["Li"][0]<<endl;
}

//class Child{
//    string kid;
//    Child(string str):kid(str){}
//};
//class Family{
//    map<string, Child> fam_map;
//    vector<string> & operator[] (const std::string & key){
//        return fam_map[key];
//    }
//    void add_child(const string & key, const string & val){
//        fam_map[key].push_back(val);
//    }
//    string to_string(){
//        std::string str="";
//        str+= "{";
//        for(auto i=fam_map.begin(); i!=fam_map.end();i++ ){
//                auto j=i;
//                if(++j == fam_map.end())
//                {
//                    str+= i->first + ":" ;
//                    for(int k=0;k< i ->second.size(); k++){
//                        str+= i->second[k]+", ";
//                    }
//                }
//                else{
//                    str+= i->first + ":" ;
//                    for(int k=0;k< i ->second.size(); k++){
//                        str+= i->second[k]+", ";
//                    }
//                }
//                    str+=", ";
//        }
//        str+= "}";
//        return str;
//    }
//};
