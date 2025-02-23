#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
private:
    string gf;

public:
    int id;
    int age;
    bool present;
    string name;
    int nos;
    int *v;

    // ctor: Default ctor: assigns garbage value
    // no khokhla student
    Student()
    {
        cout << "Student ctor called" << endl;
    }

    // paremeterized ctor
    Student(int id, int age, bool present, string name, int nos, string gf)
    {
        this->id = id;
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;
        this->gf = gf;
        this->v = new int(10); // dynamically created
        cout << "Student paremeterized ctor called" << endl;
    }

    Student(int id, int age, bool present, string name, int nos)
    {
        this->id = id;
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;
        cout << "Student paremeterized ctor w/o gf called" << endl;
    }

    // copy ctor
    Student(const Student &srcobj){
        cout << "Student copy ctor called" << endl;

        this->age=srcobj.age;
        this->gf=srcobj.gf;
        this->id=srcobj.id;
        this->name=srcobj.name;
        this->present=srcobj.present;
    }


    void study()
    {
        cout << "studying" << endl;
    }
    void sleep()
    {
        cout << "sleeping" << endl;
    }
    void bunk()
    {
        cout << "bunking" << endl;
    }

    // by using getter and setter method we can access and provide data to privately defined data members
    string getGfname(){
        return gf;
        // return this->gf;
    }

    void setGfname(string gf){
        this->gf=gf;
        // return this->gf;
    }

    // destructor is created
    ~Student()
    {
        cout << "Student dtor called" << endl;
        delete v; // deleting the dynamically created variable
    }

private:
    void gfchatting()
    {
        cout << "Chatting" << endl;
    }

    void cheating()
    {
        cout << "Cheating" << endl;
    }
};

int main()
{
    // cout << sizeof(Student) << endl;
    // Student s1;

    // Student s2(1, 12, 1, "Chota Bheem", 1, "Chutki");
    // cout << s2.name << endl;
    // cout << s2.id << endl;

    // Student s3(2, 15, 0, "Lokesh", 5);
    // cout << s3.name << endl;

    // // alocating on heap
    // Student *s4 = new Student(3, 34, 1, "Chintu", 6);
    // cout << s4->name << endl;
    // cout << (*s4).name << endl;

    // delete s4; // no LEAK

    // s1.name = "Goli";
    // s1.age = 12;
    // s1.id = 1;
    // s1.nos = 5;
    // s1.present = 1;

    // Student s2;
    // s2.name = "Chota Bheem";
    // s2.age = 11;
    // s2.id = 2;
    // s2.nos = 1;
    // s2.present = 0;

    // copy ctor
    // Student s1(1, 12, 1, "Chota Bheem", 1, "Chutki");
    // Student s2 = s1;
    // Student s2(s1);

    // Student s2 = s1;

    // cout << s1.name << endl;
    // cout << s2.name << endl;
    // {
    // Student s1(1, 12, 1, "Chota Bheem", 1, "Chutki");
    // // Student s2;
    // // s2=s1;

    // // cout<<s1.name<<endl;
    // // cout<<s2.name<<endl;

    // cout<<s1.name<<endl;
    // } // here we have created a scope by using curly braces.        
    Student s1(1, 12, 1, "Chota Bheem", 1, "Chutki");       
    cout<<s1.name<<endl;

    cout<<s1.getGfname()<<endl;
    s1.setGfname("Indumati");

    cout<<s1.getGfname()<<endl;


    return 0;
}
