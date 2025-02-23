#include<iostream>
#include<limits.h>
using namespace std;

void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool linearsearch(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return true;
        }
    }
    return false;
}

void countzeroOne(int arr[],int size){
    int zerocount=0;
    int onecount=0;

    for(int i=0;i<size;i++){
        if(arr[i]==0){
            zerocount++;
        }
        if(arr[i]==1){
            onecount++;
        }
    }

    cout<<"Zero count: "<<zerocount<<endl;
    cout<<"One count : "<<onecount<<endl;
}

int mininarray(int arr[],int size){

    int minans=INT_MAX;
    for(int i=0;i<size;i++){
        if(arr[i]<minans){
            minans=arr[i];
        }
    }
    return minans;
}

void reversearray(int arr[],int size){
    int left=0;
    int right=size-1;
    int temp;
    while(left<=right){

        temp=arr[left];
        arr[left]=arr[right];
        arr[right]=temp;

        left++;
        right--;
    }

    // print Array
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    //Creation of an array

    // int money[127];
    // char alpha[26];
    // bool flags[27];
    // int a=5;
    // cout<<"Size of a: "<<sizeof(a)<<endl;

    // cout<<"Address of a: "<<&a<<endl;
    // cout<<"Base Adress of Money : "<<&money<<endl;

    // cout<<"Size of Array: "<<sizeof(money)<<endl;
    // int arr[]={1,2,3,4,5,65};

    // int brr[5]={1,2,3,4,5};

    // int crr[5]={2,3};

    // int drr[2]={1,2,3,4,5}; //this will throw the error as the size of array is less than the value

    // cout<<brr[3]<<endl; //Accessing array values through index
    // cout<<brr[1]<<endl;
    // cout<<brr[4]<<endl;
    
    // int n=5;
    // for (int i = 0; i <n; i++)
    // {
    //     cout<<brr[i]<<" ";
    // }cout<<endl;
    //Taking input in an array
    // int arr[5];
    // int n =5;
    // for(int i=0;i<n;i++){
    //     cout<<"Enter the value for index "<<i<<" ";
    //     cin>>arr[i];
    //     cout<<endl;
    // }
    //Printing array
    // for (int i = 0; i <n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    int brr[5]={2,4,6,8,10};
    int target=10;
    int n=5;

    bool flag=0;
    // 0-> not found
    // 1-> found

    // for(int i=0;i<n;i++){
    //     if(arr[i]==target){
    //         flag=1;
    //         break;
    //     }
    // }

    // if(flag==1){
    //     cout<<"Found"<<endl;
    // }
    // else{
    //     cout<<"Not found"<<endl;
    // }
    // bool ans=linearsearch(arr,n,target);
    // printarray(arr,n);

    // if (ans==1){
    //     cout<<"Found"<<endl;
    // }
    // else{
    //     cout<<"Target Not found"<<endl;
    // }
    // int arr[]={0,0,0,1,1,0,1,0,1,0,1,0,1,1,1};
    // //zero=7
    // //one=8
    // int size=15;

    // countzeroOne(arr,size); 
    // cout<< INT_MIN<<endl;
    // cout<< INT_MAX<<endl;


    int arr[]={10,8,31,4,3,1,51};
    int size=7;

    int min=mininarray(arr,size);

    cout<<"Minimum number is : "<<min<<endl;

    reversearray(arr,size);

    return 0;
}