#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include<map>
#include<string>

class Value;

class Object{
    std::map <std::string, Value> obj_map;
public:
    Object();
    Object(std::string s);
    ~Object();

    Value & operator[] (const std::string & key);

    std::string to_json();

    std::map<std::string,Value>::iterator find(std::string str);

    std::map<std::string,Value>::iterator begin();
    std::map<std::string,Value>::iterator end();
    void insert(const std::string &key,const Value &val);
    void erase(const std::string &str);
    int size() const ;
    void clear();

    void read_char(const std::string & str, int & p, char ch);
    Value read_value(const std::string & str, int & p);
    Array read_array(const std::string & str, int & p);
    std::string read_string(const std::string & str, int & p);
    bool read_bool(const std::string & str, int & p);
    Value read_number(const std::string & str, int & p);
    Object read_object(const std::string & str, int & p);

};


#endif // OBJECT_H_INCLUDED
