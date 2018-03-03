#include<iostream>
#include<string>

using namespace std;
int com[30][30];
void cpuCombination(){
    for(int i=0; i<=26; i++){
        com[i][0]=com[i][i]=1;
        for(int j=1; j<i; j++){
            com[i][j]=com[i-1][j]+com[i-1][j-1];
        }
    }
}

int main(){
    string str;
    cpuCombination();

    while(cin>>str){
        bool f=true;
        int ans=0;
        int len=str.length();
        for(int i=1; i<len; i++){
            if(str[i-1] > str[i]){
                f=false;
                break;
            }
            ans+=com[26][i];
        }
        if(!f) {
            cout<<0<<endl;
            continue;
        }
        for(int i=0; i<len; i++){
            char ch = ( i ==0 ? 'a':(str[i-1]+1));
            for(char j=ch; j<str[i]; j++)
                ans+=com['z' -j][len-1-i];
        }

        cout<<ans+1<<endl;
    }
}
