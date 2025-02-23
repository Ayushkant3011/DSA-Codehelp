#include<iostream>
#include<stack>
using namespace std;




int main(){

    string str = "HelloJee";
    stack<char> st;

    for(int i =0; i<str.length() ;i++){
        char ch = str[i];
        st.push(ch);
    }

    cout<<endl;

    while( !st.empty() ){
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
    // // creation of stack
    // stack<int> st;

    // // insertion
    // st.push(10);
    // st.push(20);
    // st.push(30);

    // cout<< "Size of Stack is : " << st.size() << endl;

    // // remove
    // st.pop();

    // // chck empty
    // if(st.empty()){
    //     cout << "Stack empty" << endl;
    // }
    // else{
    //     cout << "Not Empty" << endl;
    // }

    // // top element 
    // cout << st.top() << endl;

    return 0;
}