/*use vector to impliment stack*/
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<vector>

template<typename T>
class Stack{
private:
    std::vector<T> v;
public:
    void push(T const& elem){
        v.push_back(elem);
    }
    void pop(){
        v.pop_back();
    }
    int sz(){
        return v.size();
    }
    T top(){
        if(!v.empty()){
            return v.back();
        }
        return -1;
    }

};
#endif // STACK_H_INCLUDED
