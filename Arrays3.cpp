#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

void printarray(int arr[][4],int row,int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    
    }
    
}

void colwiseprint(int arr[][4],int row,int col){
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    
    }
}

bool findtarget(int arr[][4],int row,int col,int target){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j]==target)
            {
                return true;
            }
            
        }
        
    }
    // iss line pr tabhi aa skte ho,
    // jab saare ke saare elements check

    return false;
    
}


int findmax(int arr[][4],int row,int col){
    int maxans=INT_MIN;
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j]>maxans){
                maxans=arr[i][j];
            }
            
        }
        
    }
    return maxans;
    
}

int findmin(int arr[][4],int row,int col){
    int minans=INT_MAX;
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j]<minans){
                minans=arr[i][j];
            }
            
        }
        
    }
    return minans;
    
}

void rowsum(int arr[][4],int row,int col){
    for (int i = 0; i < row; i++)
    {
        int sum=0;
        for (int j = 0; j < col; j++)
        {
            sum=sum+arr[i][j];
        }
        cout<<sum<<endl;
        
    }
    
}

void colsum(int arr[][4],int row,int col){
    for (int i = 0; i < col; i++)
    {
        int sum=0;
        for (int j = 0; j < row; j++)
        {
            sum=sum+arr[j][i];
        }
        cout<<sum<<endl;
        
    }
    
}


void transpose(int arr[][4],int row,int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
        
    }
    
}

int main(){
    // create a 2D Array
    // int arr[3][3];

    // initialised array
    // int arr[4][4]={
    //     {1,2,3,4},
    //     {5,6,7,8},
    //     {9,10,12,11},
    //     {13,14,15,16}
    // };
    
    int brr[3][3]={{1,2,3},
                    {4,5,6},
                    {7,8,9}};
    // int crr[][4]={
    //     {1,2,3,4},
    //     {5,6,7,8},
    //     {9,10,1,11}
    // };
    int row=4;
    int col=4;

    // Diagonal sum;
    // int sum=0;
    // for (int i = 0; i < row; i++)
    // {
    //     sum=sum+brr[i][i];
    // }
    // cout<<"Diagonal sum: "<<sum<<endl;



    // cout<<"printing The max no :"<<findmax(arr,row,col)<<endl;
    // cout<<"printing The min no :"<<findmin(arr,row,col)<<endl;

    // cout<<"Row sum"<<endl;
    // rowsum(arr,row,col);

    // cout<<"Col Sum"<<endl;
    // colsum(arr,row,col);
    // printarray(arr,row,col);
    // colwiseprint(arr,row,col);

    // Taking input in 2D Array
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++){
    //         cout<<"Enter The input for row index: "<<i<<"Column Index: "<<j<<endl;
    //         cin>>arr[i][j];
    //     }
    // }


    // int arr[100][1000];
    
    // cout<<"Before Transpose"<<endl;
    // printarray(arr,row,col);

    // cout<<"Doing Transpose"<<endl;
    // transpose(arr,row,col);

    // cout<<"After transpose"<<endl;
    // printarray(arr,row,col);


    //--------VECTOR --------
    vector<int> v(5);

    v.push_back(1);
    v.push_back(3);

    // cout<<endl<<"Size of vector: "<<v.size();

    // cout<<endl<<"Printing vector: "<<endl;
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }cout<<endl;

    //--------VECTOR 2D--------
    vector<vector<int> > arr(5,vector<int>(10,-1));

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout<<arr[i][j]<<" ";
        }
         cout<<endl;      
    }
    

    return 0;
}


// lovebabbar3@gmail.com