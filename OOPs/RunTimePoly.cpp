#include<iostream>
using namespace std;

class Animal{
    public:
    virtual void sound(){
        cout<<"Animal making sound "<< endl;
    }
};

class Dog:public Animal{
    public:
    void sound() override{ 
        cout << "Dog Barking " << endl;
    }
};

class cat : public Animal{
    void sound() override{ 
        cout << "Cat Meowing" << endl;
    }
};

void sound(Animal *animal){
    animal->sound(); //polymorphic
    // animal ka sound is behaving as per required object allocated at runtime
}

int main(){
    // Dog *dog = new Dog();
    // dog->sound();

    Animal *animal =new Dog();
    // we are using dynamic memory allocation because it is happening at runtime 
    sound(animal);

    animal = new cat();
    sound(animal);


    return 0;
}