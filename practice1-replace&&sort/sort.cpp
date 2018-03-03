#include<iostream>
#include<algorithm>
#include<math.h>

struct Node{
    double x,y;

};

double dis(Node a){
    double tmp= (double)(a.x *a.x+ a.y*a.y);
    return sqrt(tmp);
}
bool cmp(Node a, Node b){
    /*do not need to sqrt*/
    //return (a.x *a.x+ a.y*a.y)< (b.x *b.x+ b.y*b.y);
    return dis(a) > dis(b);
}
int main(){
    Node a[10];
    for(int i=0; i<10; i++){
        a[i].x =i;
        a[i].y =i;
    }
    //std::sort(b.begin(),b.end(),cmp);
    std::sort(a,a+10,cmp);
    for(int i=0; i<10; i++){
        std::cout<<a[i].x<<std::endl;
    }

}
