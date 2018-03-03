#ifndef STKCLASS_H_INCLUDED
#define STKCLASS_H_INCLUDED
#include<vector> //do not forget

template<typename T>

class stk{
private:
    std::vector<T> s;
public:
    void push(T const& elem);
    T pop();
    int sz();
    T top();
};

template<typename T>
void stk<T>::push(T const &elem){
    s.push_back(elem);
}
template<typename T>
T stk<T>::pop(){
   if(s.empty())
        std::cout<<"Empty stack!\n";
   else
        s.pop_back();
}
template<typename T>
int stk<T>::sz(){
    return s.size();
}
template<typename T>
T stk<T>:: top(){
    if(s.size()>0)
        return s.back();//the last element
    return -1;
}

#endif // STKCLASS_H_INCLUDED
