#include<map>
#include<string>
#include<iostream>

int main(){
    std::map<std::string,int> words;

    std::cout<<"Please input a sentence:"<<std::endl;
    std::string word;
    while(std::cin>>word){
        if(word == "#") break;
        words[word]++;
    }
    for(auto i=words.begin();i!=words.end();i++){
        std::cout<<i->first <<"   "<<i->second<<std::endl;
    }
}
