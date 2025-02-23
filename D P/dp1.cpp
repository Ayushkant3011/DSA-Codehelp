#include<iostream>
#include<vector>
using namespace std;

// GET THIS SOLUTION IN LEETCODE 509
// plain recursion
int solveRec(int n){
    // base case 
    if(n == 0 || n == 1){
        return n;
    }
    // recursive relation

    int ans = solveRec(n-1) + solveRec(n-2);
    return ans;
}


int main(){
    int n;
    cout << "Enter Number to get Fibonacci: " ;
    cin>>n;
    int ans = solveRec(n);
    return ans;
    
    return 0;
}