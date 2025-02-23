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

Node* insertIntoBST(Node* root,int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    // its not the first node
    if(data > root->data){
        root->right = insertIntoBST(root->right,data);
    }
    else{
        root->left = insertIntoBST(root->left,data);
    }
    return root;
}

void createBST(Node* &root){ // yaha pe root by reference hoga kyunki actual root me chnge kar rhe hai 
    // cout << "Enter Data: " << endl;
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        // cout << "Enter Data: " << endl;
        cin>>data;
    }

}

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data<< " ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right); 
            }
        }
    }
}

//Q. CBT + BST ---> convert it into valid MAX-HEAP
// this code will not work without node class or tree creation
void storeInorder(Node* root, vector<int>& in){
    if(root == NULL){
        return;
    }
    // LNR
    storeInorder(root->left, in);
    in.push_back(root->data);
    storeInorder(root->right,in);
}

void replaceUsingPostOrder(Node* root, vector<int>& in,int &index){
    if(root == NULL){
        return;
    }
    // LRN
    replaceUsingPostOrder(root->left,in, index);
    replaceUsingPostOrder(root->right,in, index);
    root->data = in[index];
    index++;
}

Node* convertBSTintoMaxHeap(Node* root){
    // 1 step: store inorder
    vector<int> inorder;
    storeInorder(root, inorder);
    // replace the node values with the stored inorder values using the post order traversal
    int index =0;

    replaceUsingPostOrder(root, inorder, index);
    return root;

}


int main(){
    Node* root = NULL;
    createBST(root);
    cout << "Printing the BST: " <<endl;
    levelOrder(root);

    cout << "Converting into Heap: " <<endl;

    root = convertBSTintoMaxHeap(root);
    cout << "Printing The Heap: " <<endl;
    levelOrder(root);


    return 0;
}













// / Q. Given BST to a valid heap or not
// class Info{
//     public:
//         int maxVal;
//         bool isHeap;

//         Info(int a, bool b){
//             this->maxVal = a;
//             this->isHeap = b;
//         }
// };

// Info checkMaxHeap(Node* root){
//     // Base Case
//     if(root == NULL){
//         Info temp;
//         temp->maxVal = INT_MIN;
//         temp->isHeap = true;
//         return temp;
//     }

//     if(root->left == NULL && root->right == NULL){
//         Info temp;
//         temp->maxVal = root->data;
//         temp->isHeap = true;
//         return temp;
//     }

//     Info leftAns = checkMaxHeap(root->left);
//     Info rightAns = checkMaxHeap(root->right);
//     // 1 case mai solve karunga 

//     if(root->data > leftAns->maxVal && root->data > rightAns->maxVal && leftAns->isHeap && rightAns->isHeap){
//         Info ans; 
//         ans->maxVal = root->data;
//         ans->isHeap = true;
//         return ans;
//     }
//     else{
//         Info ans;
//         ans->maxVal = max(root->data, max(leftAns->maxVal,rightAns->maxVal));
//         ans->isHeap = false;
//         return ans;
//     }
// }