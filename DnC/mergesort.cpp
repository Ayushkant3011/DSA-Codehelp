#include<iostream>
using namespace std;


// Time Complexity --> O(nlogn)

void merge(int arr[],int s,int e){
   int mid =(s+e)/2;
    // left waali array ki length----> (mid-s+1)
    // right waali array ki length----> (e-mid)
    int lenleft=mid-s+1;
    int lenright=e-mid;

    // create left and right array

    int *left=new int[lenleft];
    int *right=new int[lenright];

    // copy values from original array to left array
    int k=s;
    // k --> starting index of left array values in original array
    for(int i=0;i<lenleft;i++){
        left[i]=arr[k];
        k++;
    }

    // right array me copy krna hai 
    k=mid+1;
    for(int i=0;i<lenright;i++){
        right[i]=arr[k];
        k++;
    }


    // Actual merge logic
    // left array is already sorted
    // right array is already sorted
    int leftindex=0; // for traversing we have created a leftindex
    int rightindex=0;
    // yehi par galti karenge 
    int mainarrindex=s;

    while(leftindex < lenleft && rightindex <lenright){
        if(left[leftindex]<right[rightindex]){
            arr[mainarrindex] = left[leftindex];
            mainarrindex++;
            leftindex++;
        }
        else{
            arr[mainarrindex] = right[rightindex];
            mainarrindex++;
            rightindex++;
        }
    }

    // 2more cases
    // 1 case--> left array exhaust but right array me element abhi bhi bache hai 
    while(rightindex < lenright){
        arr[mainarrindex] = right[rightindex];
        mainarrindex++;
        rightindex++;
    }

    // 2 case --> right array exhaust but left array me element abhi bhi bache hai
    while(leftindex < lenleft){
        arr[mainarrindex] = left[leftindex];
        mainarrindex++;
        leftindex++;
    } 

    // 1more step pending
    delete[] left;
    delete[] right;

}


void mergesort(int arr[],int s,int e){
    // Base case
    if(s >= e){
        return;
    }

    // break
    int mid= (s+e)/2;
    // s -> mid -> left
    // mid-1 -> e -> right

    // call recursion and sort left and right array
    // recursive call for left
    mergesort(arr,s,mid);

    // recursive call for right
    mergesort(arr,mid+1,e);

    // merge
    merge(arr,s,e);
}

int main(){
    int arr[]={2,1,6,9,4,5};
    int size=6;
    int s=0;
    int e=size-1;

    cout<<"Array before Merge Sort:"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    mergesort(arr,s,e);

    cout<<endl;

    cout<<"Array after Merge Sort:"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}