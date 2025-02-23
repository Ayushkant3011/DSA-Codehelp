#include<iostream>
using namespace std;


class Heap{
    public:
        int *arr;
        int capacity;
        int size;


        Heap(int capacity){
            this->arr = new int[capacity];
            this->capacity = capacity;
            // size = current number of elements in heap
            this->size =0;
        }

        void insert(int val){
            if(size == capacity){
                cout << "Heap Overflow" << endl;
                return;
            }
            // size increase kar jaaega 
            size ++;
            int index = size;
            arr[index] = val;

            // take the val to its correct position
            while(index > 1){
                int parentIndex = index/2;
                if(arr[index] > arr[parentIndex]){
                    swap(arr[index], arr[parentIndex]);
                    index = parentIndex;
                }
                else{
                    break;
                }
            }
        }

        void printHeap(){
            for(int i = 1; i<=size; i++){
                cout << arr[i] << " ";
            }
        }

        int deleteFromHeap(){
            int answer = arr[1];

            // replacement
            arr[1] = arr[size];
            // last element ko delete uski original position se 
            size --;

            int index = 1;
            while(index < size){
                int leftIndex = 2*index;
                int rightIndex = 2*index +1;

                //  find out karna hai sabse bada kaun 
                int largestKaIndex = index ;
                if(leftIndex <= size && arr[largestKaIndex] < arr[leftIndex]){
                    largestKaIndex = leftIndex;
                }
                if(rightIndex <= size && arr[largestKaIndex] < arr[rightIndex]){
                    largestKaIndex = rightIndex;
                }

                // no chnge 
                if(index == largestKaIndex){
                    break;
                }
                else{
                    swap(arr[index], arr[largestKaIndex]);
                    index = largestKaIndex;
                }
            }
            return answer;
        }
};

void heapify(int *arr, int n, int index){ //heapify this index
    int leftIndex = 2*index;
    int rightIndex = 2*index + 1;
    int largestKaIndex = index;

    // teeno me se max laao
    if(leftIndex <= n && arr[leftIndex] > arr[largestKaIndex]){
        largestKaIndex = leftIndex;
    }
    if(rightIndex <= n && arr[rightIndex] > arr[largestKaIndex]){
        largestKaIndex = rightIndex;
    }

    // after these 2 conditions largestkaindex will be pointing towared largest element among
    if(index != largestKaIndex){
        swap(arr[index], arr[largestKaIndex]);
        // abb recursion sambhal lega 

        index = largestKaIndex;
        heapify(arr, n, index);
    }
}

void buildHeap(int arr[], int n){
    for(int index = n/2;index>0; index--){
        heapify(arr, n, index);
    }
}


void heapSort(int arr[],int n){
    while(n != 1){
        swap(arr[1], arr[n]); // yaha pe (n-1) laga ke glti karenge yeh question 1 based indexing pe solve ho raha hai 
        n--;
        heapify(arr, n, 1);
    }
}

int main(){
    int arr[] = {-1,5,10,15,20,25,12};
    int n =6;
    
    buildHeap(arr, 6);
    
    cout << "Printing heap: " <<endl;
    for(int i=1; i<=6; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);

    cout << "Printing heap: " <<endl;
    for(int i=1; i<=6; i++){
        cout << arr[i] << " ";
    }
    cout << endl;


    
    // Heap h(20);

    // // Insertion 
    // h.insert(10);
    // h.insert(20);
    // h.insert(5);
    // h.insert(11);
    // h.insert(6);

    // cout << "Printing the Heap " << endl;
    // h.printHeap();

    // int ans = h.deleteFromHeap();
    // cout << "Answer: " << ans << endl;

    // cout << "Printing the Heap " << endl;
    // h.printHeap();
     
    return 0;
}