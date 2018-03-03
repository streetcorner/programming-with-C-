#include<map>
#include<set>
#include<string>
#include<iostream>

int main(){
    std::map <int,int> numMap;
    std::multiset <int> numSet;
    int num;
     std::cout<<"Please input the number of your numbers:"<<std::endl;
    std::cin>>num;
    while(n--){
        std::cin>>num;
        if(num == -1) break;
        numMap[num]++;
        numSet.insert(num);
    }
     for(auto i=numMap.begin();i!=numMap.end();i++){
        std::cout<<i->first <<"   "<<i->second<<std::endl;
    }
    std::cout<<std::endl;
     for(auto i=numSet.begin();i!=numSet.end();i++){
        std::cout<<*i<<std::endl;
    }
}

