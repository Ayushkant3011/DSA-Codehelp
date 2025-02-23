#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

void prtarray(int *arr,int size,int index){
    // Base case
    if(index>= size){
        return;
    }
    // processing
    cout<<arr[index]<<" ";

    // recursive call
    prtarray(arr,size,index+1);
}

bool searcharray(int arr[],int size,int target,int index){
    // Base Case
    if(index>=size){
        return false;
    }
    if(arr[index] == target){
        return true;
    }

    // Recursive call
    bool aagekaans= searcharray(arr,size,target,index+1);
    return aagekaans;
}

void findmin(int arr[],int size,int index,int &mini){
    // base case
    if(index>=size){
        return;
    }
    // processing
    mini=min(mini,arr[index]);

    // recursive call

    findmin(arr,size,index+1,mini);
}

void solve(int arr[],int size,int index,vector<int> &ans){
    // Base case
    if(index>=size){
        return;
    }
    // processing
    if(arr[index]%2==0){
        // even
        ans.push_back(arr[index]);
    }
    // recursive call
    solve(arr,size,index+1,ans);
}

void printdigits(int num, vector<int>& ans){
    // base case
    if(num==0){
        return;
    }
    // processing
    int digit=num%10;
    // update num
    num=num / 10;

    // recursive call
    printdigits(num,ans);

    // processing
    ans.push_back(digit);
    
}

int main(){
    int  number=4217;
    
    vector<int> ans;

    printdigits(number,ans);

    for(int number: ans){
        cout<<number<<endl;
    }
//     int arr[]={11,20,31,40,50};
//     int size=5;
//     int index=0;
//     vector<int> ans;
//     int target=50;

//     solve(arr,size,index,ans);

//     // printing vector
//    for(int num: ans){
//     cout<<num<<" ";
//    } 

//     int mini =INT_MAX;
    // findmin(arr,size,index,mini);

    // cout<<"Minimum No in array: "<<mini<<endl;
    // cout<<"Target found or not: "<<searcharray(arr,size,target,index)<<endl;

    // prtarray(arr,size,index);
    
    
    return 0;
}