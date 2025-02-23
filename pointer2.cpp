#include<iostream>
using namespace std;


// void solve(int* p){ //Pass by value
//     p=p+1;
// }

void solve(int* &p){
    p=p+1;
}

int main(){
    
    int a=5;
    int* p=&a;
    
    cout<<"p: "<<p<<endl;
    cout<<"&p: "<<&p<<endl;
    cout<<"*p: "<<*p<<endl;
    solve(p);

    cout<<"p: "<<p<<endl;
    cout<<"&p: "<<&p<<endl;
    cout<<"*p: "<<*p<<endl;


    // int a=10;
    // int* p=&a;
    // int** q=&a;
    
    return 0;
}