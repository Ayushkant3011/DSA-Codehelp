#include "mystring.h"
#include <cstring> //strcopy

// definition of all the functions declared in Mystring.h

Mystring::Mystring(){
    data = new char[1];
    length = 0;
    data[0] = '\0';
}

Mystring::Mystring(const char *str){
    data =new char[strlen(str) + 1];
    length =strlen(str);
    strcpy(data,str);
}

Mystring::Mystring(const Mystring &other);{
    data = new char[other.legnth +1];
    length = other.legnth;
    strcpy(data,other.data);
}

Mystring::~Mystring(){
    delete [] data;
}

int Mystring::size() const{
    return length;
}

bool Mystring::empty() const{
    return length == 0;
}

const char*Mystring::c_str() const{
    return data;
}

std::ostream&operator<<(std::ostream&os, const Mystring &str){
    os << str.cstr();
    return os;
}