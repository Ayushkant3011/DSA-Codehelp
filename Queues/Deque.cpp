#include<iostream>
// #include<deque>
using namespace std;

// DOUBLY ENDED QUEUE
class Deque{
    public:
    int* arr;
    int size;
    int front;
    int rear;

    Deque(int size){
        arr = new int[size];
        this->size=size;
        front = -1;
        rear =-1;
    }
    void pushBack(int val){
        // overflow
        // empty-> first element 
        // circular nature
        // normal flow
        if((front ==0 && rear == size -1) || (rear == front-1)){ //yaha pe condition likhne me glti karte hai 
            cout<< "Overflow" << endl;
        }
        else if(front == -1 && rear ==-1){ //****
            front++;
            rear++;
            arr[rear] = val;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = val;
        }
        else{
            rear ++;
            arr[rear] = val;
        }
    }


    void pushFront(int val){
        if((front ==0 && rear == size -1) || (rear == front-1)){
            cout<< "Overflow" << endl;
        }
        else if(front ==-1 && rear ==-1){
            front ++;
            rear++;
            arr[front] = val;
        }
        else if(front ==0 && rear != size -1){ //circular nature
            front = size-1;
            arr[front] = val;
        }
        else{
            front --;
            arr[front] =val; 
        }
    }


    void popFront(){
       // overflow
        // empty-> first element 
        // circular nature
        // normal flow

        if(front == -1 && rear == -1){
            cout << "Underflow" << endl;
        }    
        else if(front == rear){
            arr[front] = -1;
            front =-1;
            rear=-1;
        }
        else if(front == size-1){
            arr[front] = -1;
            front =0;
        }
        else{
            arr[front] = -1;
            front++;
        }
    }

    void popBack(){
        // Underflow
        // single element
        // normal flow
        if(front == -1 && rear == -1){
            cout << "Underflow" << endl;
        }
        else if(front == rear){
            arr[rear] = -1;
            front=-1;
            rear =-1;
        }
        else if(rear ==0){
            arr[rear] = -1;
            rear = size -1;
        }
        else{
            arr[rear] = -1;
            rear --;
        }
    }
};

int main(){
    

    return 0;
}





// int main(){
//     deque<int> dq;

//     dq.push_back(10);
//     dq.push_front(20);
//     // dq.pop_back();
//     dq.pop_front();

//     cout<< dq.front() <<endl;
//     cout<< dq.back() <<endl;

//     cout << dq.size() << endl;

//     return 0;
// }