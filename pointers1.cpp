#include<iostream>
using namespace std;




int main(){
    int a=100;
    int* ptr=&a;
    // cout<<a<<endl;
    // cout<<"Address of A: "<<&a<<endl;

    // char ch='k';
    // // pointer creation
    // int* ptr=&a;
    // char* cptr=&ch;

    // //Accessing value stored at address stored in ptr
    // cout<<ptr<<endl;
    // cout<<"Accessing: "<<*ptr<<endl;
    // cout<<&ptr<<endl;

    // cout<<sizeof(ptr)<<endl;
    // cout<<sizeof(cptr)<<endl;

    // cout<<a<<endl;
    // cout<<&a<<endl;
    // // cout<<*a<<endl; // this will give error
    // cout<<ptr<<endl;
    // cout<<*ptr<<endl;
    // cout<<&ptr<<endl;
    // cout<<(*ptr)++<<endl;
    // cout<<++(*ptr)<<endl;
    // cout<<*ptr=(*ptr)/2<<endl;
    // cout<<*ptr=*ptr-2<<endl;

    int arr[5]={10,20,30,40,50};

    cout<<*(arr+1)<<endl;
    cout<<arr<<endl;

    char ch='a';
    char* cptr=&ch;
    cout<<cptr;


    return 0;
}