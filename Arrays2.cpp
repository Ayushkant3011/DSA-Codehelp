#include<iostream>
using namespace std;

void solve(int& a){
    a++;
    cout<<"Inside Solve function: "<<a<<endl;


}

int getunique(int arr[],int n){
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        ans=ans^arr[i];
    }
    return ans;
}


int main(){

    int arr[]={10,20,30};
    int n=3;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<arr[i]<<", "<<arr[j]<<endl;
        }
        
    }
    cout<<"Triplets"<<endl;
    int brr[]={1,2,3,4};
    int m=3;
        for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0;k < m; k++)
            {
                cout<<brr[i]<<" "<<brr[j]<<" "<<brr[k]<<endl;
            }
            
        }
        
    }



    // int arr[]={2,10,11,10,2,13,15,13,15};
    // int n=9;

    // int finalans= getunique(arr,n);

    // cout<<"Final answer is : "<<finalans<<endl;



    // int a=50;
    // cout<<a<<endl;
    // int& b=a;
    // // reference Variable-> same memory location,different names
    // cout<<b<<endl;

    // int a =5;
    // solve(a);

    // cout<<"Printing in Main "<<a<<endl;

    return 0;
}