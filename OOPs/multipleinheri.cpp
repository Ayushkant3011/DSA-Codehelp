#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Person{
    public:
    void walk(){
        cout << "Walking....." << endl;
    }
};

class Teacher: virtual public Person{
    public:
    void teach(){
        cout << "Teaching" << endl;
    }
};

class Researcher:virtual public Person{
    public:
    void research(){
        cout << "Researching..." << endl;
    }
};

// Multiple Inheritance
class professor : public Teacher, public Researcher{
    public:
    void bore(){
        cout << "Boring " << endl; 
    }
};

int main(){

    professor p;
    // p.walk();

    // Diamond Problem
    // Solution 1 --> Scope Resolution
    // p.Teacher::walk();
    // p.Researcher::walk();


    // Solution 2 --> Virtual 
    p.walk();

    return 0;
}