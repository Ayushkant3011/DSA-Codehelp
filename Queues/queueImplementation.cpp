#include<iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int val){
        // check full
        if(rear == size -1){
            cout << "Queue Overflow" << endl;
            return;
        }
        else if(front == -1 && rear == -1){
            // empty case
            front++;
            rear++;
            arr[rear] = val;
        }
        else{
            // normal case
            rear++;
            arr[rear] = val;
        }
    }

    void pop(){
        // underflow
        if(front == -1 && rear == -1){
            cout << "Queue Underflow" << endl;
        }
        else if(front == rear){
            // empty case -> single ele
            arr[front] =-1;
            front = -1;
            rear = -1;
        }
        else{
            // normal case
            arr[front] = -1;
            front++;
        }
    }

    bool isEmpty(){
        if(front ==-1 && rear==-1){
            return true;
        }
        else{
            return false;
        }
    }

    int getSize(){
        if(front ==-1 && rear ==-1){
            return 0;
        }
        else{
            return rear-front+1;
        }
    }

    int getFront(){
        if(front == -1){
            cout << "No elemet" << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }



    void print(){
        cout<< "Printing Queue: ";
        for(int i =0 ; i<size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Making CRICULAR QUEUE
class Cqueue{
    public:
    int* arr;
    int size;
    int front;
    int rear;

    Cqueue(int size){
        arr = new int[size];
        this->size= size;
        front =-1;
        rear=-1;
    }

    void push(int val){
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

    void pop(){
        // Underflow
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

    void print(){
        cout<< "Printing Queue: ";
        for(int i =0 ; i<size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main(){
    // creation
    Cqueue q(5);
    q.print();

    q.push(10);
    q.print();

    q.push(20);
    q.print();

    q.push(30);
    q.print();    

    q.push(40);
    q.print();

    q.push(50);
    q.print();

    q.push(60);

    q.pop();
    q.pop();
    q.pop();
    q.print();

    q.push(100);
    q.print();

    q.push(110);
    q.print();    

    q.push(120);
    q.print();

    q.push(130);
    q.print();

    // // creation
    // Queue q(5);
    // q.print();

    // q.push(10);
    // q.print();

    // q.push(20);
    // q.print();

    // q.push(30);
    // q.print();

    // q.push(40);
    // q.print();

    // q.push(50);
    // q.print();

    // cout << "Size of Queue: "<<q.getSize() << endl;

    // q.pop();
    // q.print();

    // cout << "Size of Queue: "<<q.getSize() << endl;

    // cout<< "Queue is empty or not : " <<q.isEmpty() << endl;

    // q.push(100); //yaha pe overflow aaega kyunki insertion rear se hota hai aur rear me space empty nahi hai
    // q.print(); 



    return 0;
}