#include<iostream>
#include<queue>
using namespace std;

// Q. Find kth smallest element 
int getKthSmallest(int arr[], int n,int k){
    priority_queue<int> pq;

    // First k element ko process karo 
    for(int i=0; i<k; i++){
        int element = arr[i];
        pq.push(element);
    }
    // Remaining element ko tabhi insert karenge jab vo root se chote honge
    for(int i=k; i<n; i++){
        int element = arr[i];
        if(element <pq.top()){
            pq.pop();
            pq.push(element);
        }
    }

    int ans = pq.top();
    return ans;
}

// Q. Find kth Greatest element 
int getkthGreatest(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int> > pq;

    // First k element ko process karo 
    for(int i=0; i<k; i++){
        int element = arr[i];
        pq.push(element);
    }
    // Remaining element ko tabhi insert karenge jab vo root se chote honge
    for(int i=k; i<n; i++){
        int element = arr[i];
        if(element > pq.top()){
            pq.pop();
            pq.push(element);
        }
    }

    int ans = pq.top();
    return ans;  
}



int main(){

    // int arr[]= {3,5,4,6,9,8,7};
    // int n=7;
    // int k =3;
    // cout << "3rd Greatest no is: " << getkthGreatest(arr, n, k) << endl;
    
    
    return 0;
}