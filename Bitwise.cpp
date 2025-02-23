#include<iostream>
using namespace std;



int main(){

    int a=7;
    cout<<"Left shift: ";
    cout<<(a<<1)<<endl;
    cout<<(a<<2)<<endl;

    cout<<"Pre/post Incre/Decre"<<endl;
    int n=5;
    cout<<"Value is "<<n<<endl;;
    cout<<(a++)<<endl;
    cout<<(++a)<<endl;

    int b=10;
    cout<<(++b)*(b++)<<endl;

    cout<<"Break "<<endl;
    for(int i=0;i<=5;i++){
        cout<<i<<endl;
        if(i==4)
        break;
    }
    cout<<"Continue"<<endl;
    for (int i = 0; i <=5; i++)
    {
        cout<<"Hello jee"<<endl;
        
        cout<<"Kaise ho"<<endl;
        continue;
    }
    

    return 0;
}