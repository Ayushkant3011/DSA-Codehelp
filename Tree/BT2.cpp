#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data=val;
        this->left = NULL;
        this->right = NULL;
    }

};


// it returns root node of the created tree
Node* createTree(){
    cout<< "Enter Value for Node: " << endl;
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }
    // step 1-- create node
    Node* root = new Node(data);

    // step 2-- create left sub tree
    // cout << "Left of Node: " << root->data <<endl;
    root->left=createTree();
    // step3-- create right sub tree
    // cout << "right of Node: " << root->data <<endl;
    root->right=createTree();

    return root;

}

void preOrder(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    // N L R
    // N
    cout<< root->data << " ";
    // L
    preOrder(root->left);
    // R
    preOrder(root->right);
}

void inOrder(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    // L N R
    // L
    inOrder(root->left);
    // N
    cout << root->data << " ";
    // R
    inOrder(root->right);
}

void postOrder(Node* root){
    // Base Case
    if(root ==  NULL ){
        return;
    }

    // L R N
    // L
    postOrder(root->left);
    // R
    postOrder(root->right);
    // N
    cout << root->data << " ";
}

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    // asli traversal satrt krte h 

    while(q.size() > 1 ){
        Node* front = q.front();
        q.pop();
        if(front==NULL){
            cout << endl;
            q.push(NULL);
        }
        else{
            // valid node wala case
            cout << front->data << " ";

            if(front->left != NULL){
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            }    
        }

        
    }
}

int searchInorder(int inorder[], int size, int target){
    for(int i =0; i<size; i++){
        if(inorder[i] == target){
            return i;
        }
    }
    return -1;
}
// niche waale function me preindex jo hai woh by reference pass hoga  
Node* constructTreeFromPreAndInorderTraversal(int preOrder[], int inOrder[], int &preIndex, int inOrderStart, int inOrderEnd, int size){
    // base case
    if(preIndex >= size || inOrderStart > inOrderEnd){
        return NULL;
    }

    // 1 case mai solve karunga 
    int element = preOrder[preIndex];
    preIndex++;
    Node* root = new Node(element);
    // element search karna padega inorder me 
    int position = searchInorder(inOrder, size, element);

    // baaki recursion dekhega
    root->left = constructTreeFromPreAndInorderTraversal(preOrder,inOrder,preIndex,inOrderStart, position-1,size);

    root->right = constructTreeFromPreAndInorderTraversal(preOrder, inOrder,preIndex,position+1,inOrderEnd,size);

    return root;
}

int main(){
    int inOrder[] = {10, 8, 6, 2, 4, 12};
    int preOrder[] = {2, 8, 10, 6, 4, 12};
    int size =6;
    int preOrderIndex =0;
    int inOrderStart =0;
    int inOrderEnd = 5;

    Node* root = constructTreeFromPreAndInorderTraversal(preOrder,inOrder,preOrderIndex,inOrderStart,inOrderEnd,size);
    cout<< "Printing the entire Tree: " << endl;
    levelOrder(root);

    return 0;
}