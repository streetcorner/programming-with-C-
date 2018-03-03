#include<iostream>
#include<map>
#include<math.h>
using namespace std;

const int NUM=4;
const string name[]={"Beijing","London","Sydney","Chicago"};

struct Lon_La{
    double lon,la;
};

Lon_La pos[]={
    {116,40},{-0.5,51.5},{151,-34},{-87.6, 41.8}
};
double dis(Lon_La city1, Lon_La city2){
    double alpha = sin(city1.la)*sin(city2.la) +cos(city1.la)*cos(city2.la)*cos(city1.lon-city2.lon);
    return 6371* acos(alpha);
}
int main(){
    map <string,Lon_La> city;
    for(int i=0; i<NUM; i++){
        city[name[i]] = pos[i];
    }
    string cityname1,cityname2;
    cout<<"Please input the name of the city"<<endl;
    cin>>cityname1>>cityname2;
    cout<<city[cityname1].lon<<","<<city[cityname1].la<<endl;
    cout<<city[cityname2].lon<<","<<city[cityname2].la<<endl;
    cout<<"The distance between "<<cityname1<<" and " <<cityname2<<" is "
        <<dis(city[cityname1],city[cityname2]);

}
