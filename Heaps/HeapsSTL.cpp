#include<iostream>
#include<queue>
using namespace std;


// for more information on stl in heap 
//  visit - https://en.cppreference.com/w/cpp/container/priority_queue


int main(){

    // min heap creation 
    priority_queue<int, vector<int>, greater<int> > pq;

    // insertion
    pq.push(100);
    pq.push(90);
    pq.push(70);

    cout << "Top element of heap: " << pq.top() << endl;

    pq.pop();

    cout << "Top element of heap: " <<pq.top() << endl;



    // // create Max-heap
    // priority_queue<int> pq;

    // // insertion
    // pq.push(10);
    // pq.push(20);
    // pq.push(30);
    // pq.push(40);
    // pq.push(50);

    // cout << "Top element of Heap : " << pq.top() << endl;

    // pq.pop();

    // cout << "Top Element of heap : " << pq.top() << endl;

    // cout << "size of max heap: " << pq.size() << endl;

    // if(pq.empty()){
    //     cout << "Empty" <<endl;
    // }
    // else{
    //     cout << "Not Empty" << endl;
    // }

    return 0;
}