#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Bird{
public:
    int age;
    int nol;
    string color;

    void eat(){
        cout<<"Bird is Eating"<<endl;
    }

    void fly(){
        cout<<"Bird is Flying "<<endl;
    }
};

class sparrow:public Bird{ //here INHERITANCE Happens as sparrow is inheriting bird
    public:
    sparrow(int age, int nol, string color){
        this->age=age;
        this->nol = nol;
        this->color = color;
    }
    void grassing(){
        cout<<"Bird is grassing"<<endl;
    }
};

class peigon:public Bird{
    public:
    void guttering(){
        cout<<"Peigon is guttering"<<endl;
    }
};



int main(){

    sparrow s(1,1,"red");
    cout<<s.color <<endl;
    s.eat();
    s.grassing();
    
    
    peigon p;
    p.eat();
    p.guttering();


    return 0;
}