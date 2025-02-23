#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void printFirstNegative(int *arr, int n,int k){
    deque<int> dq;

    // process first k elements 
    for(int index =0; index<k; index++){
        int element = arr[index];
        if(element < 0){
            dq.push_back(index);
        }
    }

    // process remaining windows -> removal and addition
    for(int index=k; index < n; index++){
        // aage badhne se pehle purani windo ka answeer nikaaldo 
        if(dq.empty()){
            cout << "0 " <<endl;
        }
        else{
            cout<< arr[dq.front()] << " ";
        }
        // cout << dq.front() << " ";
        // removal -- jo bhi index out of range hai queue se remove krdo
        if(index - dq.front() >= k){
            dq.pop_front();
        }

        // addition
        if(arr[index] < 0){
            dq.push_back(index);
        }
    }

    // last window ka ans print kardo 

    if(dq.empty()){
        cout << "0 " <<endl;
    }
    else{
        cout<< arr[dq.front()] << " ";
    }
}


int main(){
    int arr[] = {2,-5,4,-1,-2,0,5};
    int size = 7;
    int k = 3;

    printFirstNegative(arr,size,k);

 
    return 0;
}