#include<iostream>
using namespace std;

int findmissing(int arr[],int n){
    int s=0;
    int e=n-1;
    int m=s+(e-s)/2;
    int ans=-1;

    while(s<=e){
        int diff=arr[m]-m;

        if (diff ==1){
            // right me jaao
            s=m+1;
        }
        else{
            ans=m;
            e=m-1;
        }
        m=s+(e-s)/2;
    }

    if(ans+1==0)
        return n+1;

        
    return ans+1;
}


int main(){

    int arr[]={1,2,3,4,6,7,8,9};
    int n=8;

    cout<<"Missing Element is: "<<findmissing(arr,n);



    return 0;
}