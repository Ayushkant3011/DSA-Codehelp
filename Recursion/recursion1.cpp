#include<iostream>
using namespace std;

int factorial(int n){
    // Base Case
    if(n ==1)
        return 1;
    if(n==0)
        return 1;

    // Recursive realtion or call
    int ans=n*factorial(n-1);

    return ans;

    // processing
}

void counting(int n){
    // Base case
    if(n==1){
        cout<<1<<" ";
        return;
    }
    // Processing
    cout<<n<<" "; //agar recursice call se pehle cout krenge toh 5 4 3 2 1 aaega

    // Recursive Call
    counting(n-1);

    // Processing ----> after recursive call agar print krenge toh 1 2 3 4 5 6.....10 takk print hoga
    // cout<<n<<" ";
}

int pow(int n){
    // Base case
    if(n==0)
        return 1;

    int ans=2*pow(n-1);
    return ans;
}

int fib(int n){
    // Base case
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    int ans=fib(n-1)+fib(n-2);
    return ans;
}

int sum(int n){
    // Base Case
    if(n==1){
        return 1;
    }

    int ans=n+sum(n-1);
    return ans;
}

int main(){
    
    cout<<factorial(5)<<endl;
    counting(10);
    cout<<endl;

    cout<<pow(10)<<endl;

    cout<<fib(7)<<endl;


    cout<<sum(5)<<endl;   
    return 0;
}