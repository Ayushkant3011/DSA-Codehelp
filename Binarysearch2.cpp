#include<iostream>
using namespace std;

int getQuo(int divisor,int dividend){
    int s=0;
    int e=dividend;
    int ans=-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        if(mid*divisor==dividend){
            return mid;
        }
        if(mid*divisor<dividend){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }

    return ans;
}

int searchnearSort(int arr[],int n,int target){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        if(mid-1>=0 && arr[mid-1]==target){
            return true;
        }
        if(arr[mid]==target){
            return mid;
        }
        if(mid+1<n && arr[mid+1]==target){
            return mid+1;
        }
        if(target>arr[mid]){
            // right
            s=mid+2;
        }
        else{
            e=mid-2;
        }
        mid=s+(e-s)/2;
    }
}


int findoddocc(int arr[],int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        // single element
        if(s==e){
            return s;
        }

        // mid checck
        if(mid & 1){ // mid&1 -> true-> odd pe ho 
            if(mid-1>=0 && arr[mid-1]==arr[mid]){
                // right me jaaunga
                s=mid+1;
            }
            else{
                // left me jaao 
                e=mid-1;
            }
        }
        else{
            // even
            if(mid+1<n && arr[mid]==arr[mid+1]){
                // right me jaao 
                s=mid+2;
            }
            else{
                // yaa toh right part pe khada hu 
                // yaa ans ke uppr khada hu
                //  thats why e=mid krr raha hu
                // kyonki e=mid-1 se ans lost ho skta h
                e=mid; 
            }
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

int main(){

    // int divisor =7;
    // int dividend=29;
    // int divisor =1;
    // int dividend=-35;

    // // int n=-5;
    // // cout<<abs(n)<<endl;//absolute value means -ve ko +ve send kiya gaya hai 

    // int ans=getQuo(abs(divisor),abs(dividend));

    // // now we need to decide k sign konsa lagaye +ve yaa -ve

    // if(divisor>0 && dividend<0 || (divisor<0 && dividend>0)){
    //     ans=0-ans;
    // }

    // cout<<"Final Ans: "<<ans<<endl;


    // int arr[]={20,10,30,50,40,70,60};// nearly sorted array
    // int n=7;
    // int target=40;

    // int targetIndex=searchnearSort(arr,n,target);

    // if(targetIndex==-1){
    //     cout<<"Element not Found"<<endl;
    // }
    // else{
    //     cout<<"Element found At index: "<<targetIndex<<endl;
    // }

    // int arr[]={10,10,2,2,3,3,5,5,6,6,7,7,10};
    // int n=13;
    // single arr 
    int arr[]={10};
    int n=1;


    int ansIndex=findoddocc(arr, n);

    cout<<"Final answer is : "<<arr[ansIndex]<<endl;

    return 0;
}