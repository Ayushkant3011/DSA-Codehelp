#include<iostream>
#include<stack>
#include<queue>
using namespace std;

// REVERSE QUEUE by using STACK
void reverseQueue(queue<int> &q){
    stack<int> s;

    // one by one queue se element lo and stack me daalo 
    while(!q.empty() ){
        int frontElemet = q.front();
        q.pop();

        s.push(frontElemet);
    }
    // one bye one stack se lo and queue me push karo 

    while( !s.empty() ){
        int element = s.top();
        s.pop();

        q.push(element);
    }
}

void reverse(queue<int>& q){
    // base case
    if(q.empty()){
        return;
    }

    int temp= q.front();
    q.pop();

    reverse(q);

    q.push(temp);
}

void reverseFirstk(queue<int>& q,int k){
    stack<int> s;
    int n = q.size();

    if(k > n || k == 0){
        return;
    }
    // push first k element into stack
    for(int i=0;i<k;i++){
        int temp = q.front();
        q.pop();

        s.push(temp);
    }
    // push all k element into queue
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        q.push(temp);
    }
    // pop and push first(n-k) elements into queue 
    for(int i =0;i<(n-k);i++){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}


void interLeaveQueue(queue<int>& first){
    queue<int> second;

    // PUSH first half of the first queue into second
    int size = first.size();
    for(int i =0; i<size/2;i++){
        int temp = first.front();
        first.pop();

        second.push(temp);
    }

    // Merge both the halves
    // into the original queue named as first
    for(int i =0; i<size/2; i++){
        int temp = second.front();
        second.pop();

        first.push(temp);

        temp = first.front();
        first.pop();
        first.push(temp);
    }
}


int main(){
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    // reverse(q);
    // reverseFirstk(q,4);
    interLeaveQueue(q);

    cout << "Printing Queue: " <<endl;
    while( !q.empty() ){
        int element = q.front();
        q.pop();
        cout<< element << " ";
    }


    return 0;
}