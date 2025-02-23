#include<iostream>
using namespace std;

int binarysearch(int arr[],int n,int target){
    int start=0;
    int end=n-1;
    // there is some flow in below line
    // int mid=(start+end)/2; // integer overflow hone ki sambhawana hai 
    // BEST PRACTICE
    int mid=start+(end-start)/2;

    while(start<= end){
        // found
        if(arr[mid]==target){
            return mid;
        }
        else if(target >arr[mid]){
            // right side
            start=mid+1;
        }
        else if(target<arr[mid]){
            // left side
            end=mid-1;
        }
        // mid update // galti hogi har baar 
        mid=(start+end)/2;
    }

    // agar yaha tak pauhce ho iska matbal element not found 
    return -1;
}

int findfirstocc(int arr[],int n,int target){
    int s=0;
    int e=n-1;
    // int mid=(s+e)/2; ---> integer overflow hone ki umeed hai 
    // BEST PRACTICE
    int mid=s+(e-s)/2;
    
    int ans=-1;


    while(s<=e){
        if(arr[mid]==target){
            // ans stored
            ans=mid;
            e=mid-1;
        }
        else if(target>arr[mid]){
            // right me jaao
            s=mid+1;
        }
        else if(target<arr[mid]){
            // left me jaao
            e=mid-1;
        }
        mid=(s+e)/2;
    }
    return ans;
}

int findlastocc(int arr[],int n,int target){
    int s=0;
    int e=n-1;
    // int mid=(s+e)/2; ---> integer overflow hone ki umeed hai 
    // BEST PRACTICE
    int mid=s+(e-s)/2;
    
    int ans=-1;


    while(s<=e){
        if(arr[mid]==target){
            // ans stored
            ans=mid;
            s=mid+1;
        }
        else if(target>arr[mid]){
            // right me jaao
            s=mid+1;
        }
        else if(target<arr[mid]){
            // left me jaao
            e=mid-1;
        }
        mid=(s+e)/2;
    }
    return ans;
}

int totalocc(int arr[],int n,int target){
    int firstocc=findfirstocc(arr,n,target);
    int lastocc=findlastocc(arr,n,target);
    int total=lastocc-firstocc+1;

    return total;
}



int main(){
    
    int arr[]={10,20,30,30,30,30,70,80,90};
    int target=30;
    int n=9;

    // int ansindex= binarysearch(arr,n,target);
    
    // if(ansindex==-1){
    //     cout<<"Element not found"<<endl;
    // }
    // else{
    //     cout<<"Element found at Index : "<<ansindex<<endl;
    // }
    // int ansind=findfirstocc(arr,n,target);
    // int ansind=findlastocc(arr,n,target);
    int ansind=totalocc(arr,n,target);

    // if(ansind==-1){
    //     cout<<"Element not found"<<endl;
    // }
    // else{
    //     cout<<"Element found at Index : "<<ansind<<endl;
    // }

    cout<<"Total Occurance : "<<ansind<<endl;


    return 0;
}