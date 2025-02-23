#ifndef MYSTRING_H
#define MYSTRING_H

#include<iostream>

class Mystring{
    private:
    char*data; //Pointer to char array data
    int length; // size of my string

    public:
    // default ctor
    Mystring(); 

    // para ctor
    Mystring(const char *str);

    // copy ctor
    Mystring(const Mystring &other);

    ~Mystring();

    int size() const;

    bool empty() const;

    const char *c_str() const;



    // we have to overload insertion operator <<  for easy output
    friend std::ostream&operator<<(std::ostream&os, const Mystring &str);
};

#endif //MYSTRING_H