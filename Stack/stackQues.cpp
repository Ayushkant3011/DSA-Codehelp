#include<iostream>
#include<stack>
using namespace std;


// FIND MIDDLE ELEMENT OF A STACK

void solve(stack<int> &st, int & pos,int &ans){
    // base case
    if(pos == 1){
        ans = st.top();
        return; 

    }
    // 1 case hum solbe krenge 
    pos --;
    int temp = st.top();
    st.pop();

    // recursion
    solve(st,pos,ans);

    // bactrack
    st.push(temp); 
}


int getMiddleElement(stack<int> &st){
    int size = st.size();
    if(st.empty()){
        return -1;
    }
    else{
        // stack is not empty
        // odd
        int pos = 0;
        if(size & 1){
            pos = size /2 +1;
        }
        else{
            // even
            pos = size /2;
        }
        int ans = -1;
        solve(st,pos,ans);
        return ans;
    }
}


// INSERT AT BOTTOM
void insertAtBottom(stack<int> &st,int &element){
    // base case
    if(st.empty()){
        st.push(element);
        return;
    }
    // 1 case solve krnge
    int temp = st.top();
    st.pop();

    // baaki recursion dekhege
    insertAtBottom(st,element);

    // backtrack
    st.push(temp);
}

void reverseStack(stack<int> &st){
    // base case
    if(st.empty()){
        return;
    }
    // 1 case solve karo 
    int temp = st.top();
    st.pop();

    // recursion
    reverseStack(st);

    // backtracking
    insertAtBottom(st,temp);
}

void insertSorted(stack<int> &st,int element){
    // base case
    if(st.empty() || element > st.top()){
        st.push(element);
        return;
    }

    // 1 case solve karo 
    int temp = st.top();
    st.pop();

    // recursion
    insertSorted(st,element);

    // backtrack
    st.push(temp);   
}

void sortStack(stack<int> &st){
    // base case
    if(st.empty()){
        return;
    }

    // 1 case solve karo 
    int temp = st.top();
    st.pop();

    // recursion
    sortStack(st);

    // backtrack
    insertSorted(st,temp);

}

int main(){
    stack<int> st;
    st.push(10);
    st.push(7);
    st.push(12);
    st.push(5);
    st.push(11);
    // int element = 400;

    // insertAtBottom(st,element);

    // reverseStack(st);

    // // cout << " With Reverse : "<<endl;
    // insertSorted(st,25);
    // insertSorted(st,15);
    // insertSorted(st,5);

    sortStack(st);
    while( !st.empty() ){
        cout << st.top() << " ";
        st.pop();
    }

    // int mid = getMiddleElement(st);
    // cout<<"Middle Element : "<<mid <<endl;

    return 0;
}