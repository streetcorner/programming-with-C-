#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

bool pred(string str){
    return (str.length() >= 5);
}
int main(){
    vector<string> words={"aaaaaaaa","bbbb","ccc","dddddd","eeeee","ff","ggggg"};
    vector<string>::iterator it = partition(words.begin(),words.end(),pred);
    for(auto i=words.begin(); i!=it; i++){
        cout<<*i<<" ";
    }
}
