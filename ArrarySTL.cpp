#include<iostream>
#include<vector>
using namespace std;

void printarr(int a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<endl;
    }
}

void printvec(vector<int>v){
    cout<<"Printing Vector"<<endl;
    int size=v.size();
    for (int i = 0; i < size; i++)
    {
        // cout<<v[i]<<endl;
        cout<<v.at(i)<<endl;
    }
    
}

void printvec2(vector<char>v){
    cout<<"Printing Vector Method 2"<<endl;
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
}


int main(){

    vector<char> v;
    v.push_back('a');
    v.push_back('b');
    v.push_back('d');

    cout<<"Front Element: "<<v[0]<<endl;
    printvec2(v);
    // printvec(v);


    vector<int>arr; //default with no data,0 size
    vector<int>arr2(5, 2);// init with n size with specific data
    
    arr2.push_back(20);
    printvec(arr2);
    
    vector<int>arr3={1,2,3,4,5};
    printvec(arr3);

    // how to copy vector

    vector<int>arr5={1,2,3,4,5};
    vector<int>arr6(arr5);

    printvec(arr6);


    // in vector dont tell size of vector, just keep inserting
    // vector<int>v; //array hi hai 

    // // taking input from user
    // int n;
    // cin>>n;
    // for (int i = 0; i < n; i++)
    // {
    //     int d;
    //     cin>>d;
    //     v.push_back(d);
    // }
    // printvec(v);
    
    // // I want to clear the vector

    // v.clear();

    // printvec(v);

    // insert
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);

    // printvec(v);
    // cout<<"Deleting using vector"<<endl;
    // // pop--> delete--> END se hoga 
    // v.pop_back();
    // printvec(v);

    // int arr[5]={1,2,3,4,5}; // static memory Allocation
    
    // printarr(arr,5);

    // int n;
    // cout<<"Enter Value of n: ";
    // cin>>n;
    // // dynamic memory Allocation
    // int *arr=new int[n]; // each element would be 0, or garbage value

    // // taking n elements input and inserting in an array
    // for (int i = 0; i < n; ++i)
    // {
    //     int data;
    //     cin>>data;
    //     arr[i]=data;
    // }

    // // want to add more elements
    // arr[n]=80;
    

    // printarr(arr,n);

    return 0;
}