#include<iostream>
#include<queue>
using namespace std;




int main(){
    // creation
    queue<int> q;
    
    // insertion
    q.push(5);

    // size
    cout<<"Size of Queue : " << q.size() << endl;

    // empty
    if(q.empty()==true){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout << "Queue is not empty" <<endl;
    }

    // remove
    q.pop();
        // size
    cout<<"Size of Queue : " << q.size() << endl;
    // empty
    if(q.empty()==true){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout << "Queue is not empty" <<endl;
    }

    q.push(20);
    q.push(30);
    q.push(40);

    // front
    cout<<"Front elemet : "<<q.front()<<endl;
    cout<<"Rear elemet: " <<q.back()<<endl;

    return 0;
}