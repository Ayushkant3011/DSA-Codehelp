#include<iostream>
using namespace std;

class Stack{
    public:
    int* arr;
    int size;
    int top;

    Stack(int size){
        arr = new int[size]; // memory provided 
        this->size = size;
        this->top = -1;
    }

    void push(int data){
        if(top == size-1){
            cout << "Stack OverFlow" << endl;
            return;
        }
        else{
            top ++;
            arr[top] = data;
        }
    }

    void pop(){
        if(top == -1){
            cout << "Stack UnderFlow" << endl;
        }
        else{
            top --;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    int getTop(){
        return arr[top];
    }

    int getSize(){
        return top+1;
    }

    void print(){
        cout<<"TOP : "<<top <<endl;
        cout<<"Top element :"<<getTop()<<endl;
        cout << "Stack : ";
        for(int i =0;i <getSize();i++){
            cout<<arr[i]<< " ";
        }
        cout<<endl<<endl;
    }
};


int main(){
    // creation statically
    Stack st(8); 

    // stack push
    st.push(10);
    st.print();

    st.push(20);
    st.print();

    st.push(30);
    st.print();

    cout<< "Top Element : "<<st.getTop() << endl;
    cout << "Size : " << st.getSize() << endl;

    if(st.isEmpty()){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not Empty "<<endl;
    }

    // // stack push
    // st.push(10);
    // st.print();

    // st.push(20);
    // st.print();

    // st.push(30);
    // st.print();

    // // stack push here we are checking about the overflow condition
    // st.push(10);
    // st.print();

    // st.push(20);
    // st.print();

    // st.push(30);
    // st.print();

    // st.pop();
    // st.print();

    // st.pop();
    // st.print();

    // st.pop();
    // st.print();

    return 0;
}