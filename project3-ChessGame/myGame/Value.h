#ifndef VALUE_H_INCLUDED
#define VALUE_H_INCLUDED

#include<sstream>
#include<string>
#include"Array.h"
#include"Object.h"


enum ValueType
{
    INT,        // JSON's int
    FLOAT,      // JSON's float 3.14 12e-10
    BOOL,       // JSON's boolean (true, false)
    STRING,     // JSON's string " ... "
    OBJECT,     // JSON's object { ... }class Array{
    ARRAY,      // JSON's array [ ... ]
    NIL         // JSON's null
};
class Value{
    std::string v_string;
    float v_float;
    int v_int;
    bool v_bool;
    Object v_object;
    Array v_array;
    ValueType type;
public:
    Value();
    Value(std::string v);
    //array.push_back(const string), the string may  be recognized as char*,but not string.
    Value(char *v) ;
    Value(float v);
    Value(int v);
    Value(bool v);
    Value(Object v);
    Value(Array v);
    ~Value();

    std::string & to_string();

    float & to_float();

    int & to_int();

    bool & to_bool();

    Object & to_object();

    Array & to_array();

    //for class object
    Value& operator[](const std::string & key);
    //for class array
    Value& operator[](const int & num);

    Value & operator=(const std::string & v);

    Value & operator=(const char * v);

    Value & operator=(const float & v);

    Value & operator=(const int & v);

    Value & operator=(const bool & v);

    Value & operator=(const Object & v);

    Value & operator=(const Array & v);

    std::string to_json();

    ValueType get_type();

    void push_back(Value val);

};

#endif // VALUE_H_INCLUDED
