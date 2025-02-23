#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    node(){
        this->prev =NULL;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data << "-> ";
        temp = temp->next;
    }
}

int findLen(Node* &head){
    Node* temp = head;
    int len = 0;
    
    while(temp != NULL){
        len++;
        temp = temp->next;
    }

    return len;
}

void insertAtHead(Node* &head,Node* &tail,int data){
    // LL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        // LL is not empty 
        Node* newNode = new Node(data);
        newNode->next =head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(Node* &head,Node* &tail,int data){
    // LL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        // LL is not empty 
        Node* newnode = new Node(data);
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void insertAtPos(Node* &head,Node* &tail,int data,int pos){
    // LL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        int len = findLen(head);
        if(pos == 1){
            insertAtHead(head,tail,data);
        }
        else if(pos == len +1){
            insertAtTail(head,tail,data);
        }
        else{
            // insert in middle 
            // Step 1 create node
            Node* newNode = new Node(data);
            // step2 set prev and curr 
            Node* prevnode = NULL;
            Node* currnode =head;
            while(pos != 1){
                pos--;
                prevnode = currnode;
                currnode = currnode->next;
            }

            // step3 pointers update kare
            prevnode->next = newNode;
            newNode->prev = prevnode;
            newNode->next = currnode;
            currnode->prev = newNode;
        }
    }
}

void deleteNode(Node* &head,Node* &tail,int pos){
    int len = findLen(head);
    if(head ==NULL){
        // Ll is empty
        cout<<"LL is Empty Cant delete" << endl;
        return;
    }
    if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }

    if(pos == 1){
        // delete from head
        Node* temp = head; 
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else if( pos == len){
        // delete from tail
        Node* prevNode = tail->prev;
        prevNode->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = prevNode;
    }
    else{
        // delete from middle 
        // step 1 set preNode/currNode/NextNode
        Node* prevNode = NULL;
        Node* currNode= head;
        while(pos != 1){
            pos--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node* nextNode = currNode->next;
        

        prevNode->next = nextNode;
        currNode->prev = NULL;
        currNode->next = NULL;
        nextNode->prev = prevNode;

        delete currNode;
    }
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,40);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,10);
    
    print(head);
    cout<<endl;

    // insertAtTail(head,tail,1000);
    // insertAtPos(head,tail,1000,5);

    // print(head);
    deleteNode(head,tail,1);
    print(head);
    cout<<endl;

    deleteNode(head,tail,2);
    print(head);
    cout<<endl;

    deleteNode(head,tail,2);
    print(head);
    cout<<endl;

    deleteNode(head,tail,1);
    print(head);

    cout<<"Length of LL is "<<findLen(head)<<endl;

    deleteNode(head,tail,1);
    print(head);

    return 0;
}