#include<iostream>
using namespace std;


// Node Creation
class Node{
    public:
    int data;
    Node* next;

    Node(){
        cout << "Default Ctor" <<endl;
        this-> next =NULL;
    }

    Node(int data){
        // cout << "Parameterised Ctor" << endl;
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        cout<< "Dtor call for "<< this->data<<endl;
    }
};

void prtLL(Node* head){
    // Actual ptr nahi chedna hai 
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << "-> ";
        temp = temp->next ; 
    }
    cout<<endl;

}

int getlen(Node* head){
    Node* temp= head;

    int count =0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(Node* &head,Node* &tail,int data){
    if(head == NULL){
        // empty LL

        // step 1- create new node
        Node* newNode = new Node(data);
        // update
        head = newNode;
        tail = newNode;
    }

    else{
    // create a new node
    Node* newNode = new Node(data);

    // attach new node to head node
    newNode->next = head;

    // update head;
    head = newNode;
    }
    
}

void insertAtTail(Node* &head,Node* &tail,int data){
    if(head == NULL){
        // empty ll
        // step 1 create new node
        Node* newNode = new Node(data);
        // step 2 single node hai list me thats why head and tail same pe hoga 
        head = newNode;
        tail = newNode;

    }
    else{
        //Non empty ll

        // Step 1- create new node
        Node* newNode = new Node(data);

        // Step 2- tail node ko attach karo newnode se
        tail->next = newNode;
        // Step 3-- update tail
        tail = newNode;

    }
}

void createTail(Node* head, Node* &tail){
    Node* temp =  head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    // jab yeh loop khatam hogya hoga then aapka temp wala pointer khada hoga last node pe 
    //  tab tail = temp krke, tail ko last node pe le aao 
    tail = temp;
}


void insertAtPos(Node* &head,Node* &tail,int data,int position){
    int length = getlen(head);

    if(position == 1){
        insertAtHead(head,tail,data);
    }
    else if(position == length+1){ //yaha galti ki thi pehle length hi thi
        insertAtTail(head,tail,data);
    }
    else{
        // Insert at middle of LL
        // step 1-- new code
        Node* newNode = new Node(data);
        // step 2- traverse prev/curr to position
        Node* prev = NULL;
        Node* curr = head;

        while(position != 1){
            prev = curr;
            curr = curr->next;
            position--;
        }
        // step 3-- attach prev to new node
        prev->next = newNode;
        // step 4 attach newnode to curr
        newNode->next = curr;
    }
}

void delNode(Node* &head,Node* &tail,int position){
    // empty list
    if(head == NULL){
        cout << "LL is Empty "<< endl;
        return;
    }
    
    int len = getlen(head);

    // delete from head
    if(position == 1){
        // first node ko delete kar do 
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else if( position == len){
        // tail ko delete karna hai
        
        // find prev
        Node* prev = head;
        while(prev->next != tail){
            prev = prev->next;

        }

        // prev node ka link null karo 
        prev->next  = NULL;

        // node delete karo 
        delete tail;

        // update tail 
        tail = prev;
    }

    else{
        // middle me koi node delete karn hai

        // step 1 = set prev and curr
        Node* prev = NULL;
        Node* curr = head;

        while(position != 1){
            position --;
            prev = curr;
            curr = curr->next;
        } 

        // step 2 prev-.next me curr ka next node add karo 
        prev->next = curr->next;

        // step 3 isolate node 
        curr->next = NULL;

        // step4 delete node
        delete curr;
    }
}

int main(){
    
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,50);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,10);

    prtLL(head);

    // insertAtPos(head,tail,5,1);
    // insertAtPos(head,tail, 1000,51);

    // prtLL(head);

    // cout<<endl;

    delNode(head,tail,3);
    prtLL(head);
    cout<<endl;


    // delNode(head,tail,1);
    // prtLL(head);
    // cout<<endl;



     
    // creation of node
    // Node a; Static object creation
    // Node* first= new Node(10);
    // Node* second= new Node(20);
    // Node* third = new Node(30);
    // Node* fourth = new Node(40);
    // Node* fifth = new Node(50);
    // Node* tail = fifth;

    // first-> next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    // LL create ho chuki h;

    // Node* head = first;
    // cout << "LL Print" << endl;
    // prtLL(head);
    
    // // cout<< "Len of LL : " << getlen(head)<<endl; 
    // // cout << "Insert At Head: "<<endl;
    // // insertAtHead(head,tail,500);
    // cout << "Insert At Tail: "<<endl;
    // insertAtTail(head,tail, 500);

    // prtLL(head);


    return 0;
}