#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include<vector>
#include<string>

class Value;

class Array{
    std::vector <Value> v_vec;
public:
    Array();
    ~Array();

    Value & operator[](int index);
    void push_back(const Value & val);

    std::string to_json();
    std::vector<Value>::iterator begin();
    std::vector<Value>::iterator end();
    bool empty() const;
    bool find(int x);
    int size() const;
    void clear();
};


#endif // ARRAY_H_INCLUDED
