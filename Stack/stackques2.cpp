#include<iostream>
#include<stack>
#include<string>
using namespace std;


bool checkredundant(string &str){
    stack<char> st;

    for(int i =0;i<str.length();i++){
        char ch = str[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' ){
            st.push(ch);
        }
        else if(ch == ')'){

            int opecount = 0;
            while(!st.empty() && st.top() != '('){
                char temp = st.top();
                if(temp == '+' || temp == '-' || temp == '*' || temp == '/' ){
                    opecount++;
                }
                st.pop();   
            }
            // yaha tabhi pohocge tab jab aapke stack ke top pe opening bracket hoga 
            st.pop();

            if(opecount == 0){
                return true;
            }
        }
    }
    // agar mai yaha tak paucha hu iska matlab har ekk brakcet ke beech me operator mila hi hoga 
    return false;
}


int main(){
    string str = "((a+b) * (c+d)))";

    bool ans = checkredundant(str);

    if(ans == true){
        cout << "Redundant present" <<endl;
    }
    else{
        cout << "Redundant not present" <<endl;
    }


    return 0;
}