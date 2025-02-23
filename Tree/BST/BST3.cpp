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
    cout << "Enter Data: " << endl;
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cout << "Enter Data: " << endl;
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

void preOrder(Node* root){
    // N L R
    if(root == NULL)
        return;
    cout << root->data<< " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    // L N R
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root){
    // L R N 
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

Node* minValue(Node* root){
    if(root == NULL){
        cout << "No Min value " << endl;
        return NULL;
    }
    Node* temp = root;
    while( temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxValue(Node* root){
    if(root == NULL){
        return NULL;
    }

    // if tree has nodes > 0 count
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

bool searchInBST(Node* root, int target){
    // Base Case
    if(root == NULL){
        return false;
    }

    // 1 case mai solve karunga
    if(root->data == target){
        return true;
    }

    // baaki recursion dekhega
    bool leftAns = false;
    bool rightAns = false;
    if(target > root->data){
        rightAns = searchInBST(root->right,target);
    }
    else{
        leftAns = searchInBST(root->left,target);
    }

    return leftAns || rightAns;
}

Node* deleteFromBST(Node* root, int target){
    // target ko dhundo 
    // target ko delete karo 
    // base case
    if(root == NULL){
        return NULL;
    }

    if(target == root->data){
        // abb delete karenge
        // 4 cases honge 

        // case1 -- leaf node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // case 2 left non null and right null
        else if(root->left != NULL && root->right == NULL){
            Node* childSubtree = root->left;
            delete root;
            return childSubtree;
        }

        // case3 left null hai aur right non null 
        else if(root->left == NULL && root->right != NULL){
            Node* childSubtree = root->right;
            delete root;
            return childSubtree;
        }

        // case 4 left aur right dono non null honge 
        else{
            // a left subtree ki max value laao
            Node* maxi = maxValue(root->left);
            // replacement 
            root->data = maxi->data;

            // delete actual maxi node 
            root->left = deleteFromBST(root->left, maxi->data);
            return root;
        }
    }
    else if(root->data > target){
        // left me chalo 
        root->left = deleteFromBST(root->left,target);
    }
    else{
        // right me jaao 
        root->right = deleteFromBST(root->right, target);
    }
}

Node* bstFronInorder(int inorder[],int s, int e){
    // Base Case
    if(s>e){
       return NULL; 
    }

    // 1 case solve krna hai 
    int mid = (s+e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);

    // Baaki recursion 
    root->left = bstFronInorder(inorder, s, mid-1);
    root->right = bstFronInorder(inorder, mid+1, e);

    return root;
}

// convert this BST into a sorted doubly linked list 
void convertBSTtoDLL(Node* root,Node* &head){
    if(root == NULL){
        return;
    }

    // RNL

    // R
    convertBSTtoDLL(root->right,head);
    // N
    root->right = head;
    if(head != NULL)
        head->left = root;
    head = root;

    // L
    convertBSTtoDLL(root->left, head);
}

void prtLL(Node* head){
    Node* temp = head;
    cout << "Printing the entire List: " << endl;
    while(temp != NULL){
        cout << temp->data << "->" ;
        temp = temp->right;
    }cout<<endl;
}

Node* convertDLLtoBST(Node* &head, int n){
    // base case 
    if(head == NULL || n <=0){
        return NULL;
    }

    // LNR
    cout << "Solving left part" << endl;
    // L
    Node* leftSubtree = convertDLLtoBST(head , n/2);

    // N
    cout << "Creating current node: " << head->data << endl;
    Node* root = head;
    root->left = leftSubtree;
    head = head->right;

    // R
    cout << "solving right part " << endl;
    Node* rightSubtree = convertDLLtoBST(head, n-n/2-1);
    root->right = rightSubtree;
    return root;
}

int main(){

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->right = second;
    second->left = first;
    second->right = third;
    third->left = second;

    Node* head = first;


    Node* root = convertDLLtoBST(head,3);
    levelOrder(root);

    // int inorder[] = {10,20,30,40,50,60,70};
    // int size = 7;
    // int start =0;
    // int end = size-1;
    // Node * root = bstFronInorder(inorder,start, end);

    // levelOrder(root);

    // Node* head = NULL;
    // convertBSTtoDLL(root, head);
    // prtLL(head);


    // Node* root = NULL;
    // createBST(root);

    // levelOrder(root);

    // cout << endl << "Inorder: ";
    // inOrder(root);

    // cout << endl << "Preorder: ";
    // preOrder(root);
    // cout << endl << "Postorder: ";
    // postOrder(root);

    // cout << endl;
    // Node* minNode = minValue(root);
    // if(minNode == NULL){
    //     cout << " No Node in Tree" << endl;
    // }
    // else{
    //     cout << "Min Value:" << minNode->data << endl;
    // }


    // cout << endl;
    // Node* maxNode = maxValue(root);
    // if(maxNode == NULL){
    //     cout << " No Node in Tree" << endl;
    // }
    // else{
    //     cout << "Max Value:" << maxNode->data << endl;
    // }


    // int target = -1;
    // cout << "Enter the value of Target: " << endl;
    // cin >> target;
    // while(target != -1){
    //     deleteFromBST(root,target);
    //     cout << "printing level order: " << endl;
    //     levelOrder(root);

    //     cout << "Enter the value of Target: " << endl;
    //     cin >> target;        
    // }

    // int t;
    // cout << "Enter the target : " << endl;
    // cin>>t;

    // while(t != -1){
    //     bool ans = searchInBST(root,t);
    //     if(ans == true){ 
    //         cout << "Found" << endl;
    //     }
    //     else{
    //         cout << "Not Found" << endl;
    //     }

    //     cout << "Enter the Target: " << endl;
    //     cin>>t;
    // }


    return 0;
}