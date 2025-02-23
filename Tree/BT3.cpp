#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* createTree(){
    cout<< "Enter Value for Node: " ;
    int value;
    cin>> value;

    if(value == -1){
        return NULL;
    }

    // create Node
    Node* root = new Node(value);
    cout<< "Entering in left of: " <<value <<endl;
    root->left = createTree();

    cout << "Entering in right of : " << value << endl;
    root->right = createTree();
    return root;
}

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    cout << endl;

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


void prtLeftView(Node* root,int level, vector<int>&leftview){
    // base case
    if(root == NULL){
        return;
    }

    if(level == leftview.size()){
        // iska matbal left view ki node mil gyi h, store krlo
        leftview.push_back(root->data);
    }

    prtLeftView(root->left, level+1, leftview);
    prtLeftView(root->right, level+1, leftview);
}

void prtRightView(Node* root,int level, vector<int>& rightview){
    // base case
    if(root == NULL){
        return;
    }

    if(level == rightview.size()){
        // iska matbal left view ki node mil gyi h, store krlo
        rightview.push_back(root->data);
    }

    prtRightView(root->right, level+1, rightview);
    prtRightView(root->left, level+1, rightview);
}

void prtTopView(Node* root){
    map<int,int> hdToNodemap;
    queue<pair<Node* ,int> >q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second; // agar is horizontal dist ke liye ans nhi aaya hai toh store karlo 
        // if there is no entry for hd in map then create a new entry
        if(hdToNodemap.find(hd) == hdToNodemap.end()){
            hdToNodemap[hd] = frontNode->data;
        }

        // child ko dekhna hai abb 
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    cout << "Print Top View : " << endl;
    for(auto i:hdToNodemap){
        cout << i.second << " ";
    }
}

void prtBottomView(Node* root){
    map<int,int> hdToNodemap;
    queue<pair<Node* ,int> >q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second; // agar is horizontal dist ke liye ans nhi aaya hai toh store karlo 
        
        // overwrite ans so that the deeper nodes can be stored
        hdToNodemap[hd] = frontNode->data;

        // child ko dekhna hai abb 
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    cout << "Print Bottom View : " << endl;
    for(auto i:hdToNodemap){
        cout << i.second << " ";
    }
}

void prtLeftBoundary(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }
    cout << root->data << " ";
    if(root->left != NULL){
        prtLeftBoundary(root->left);
    }
    else{
        prtLeftBoundary(root->right);
    }
}

void prtLeafBoundary(Node* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        cout << root->data << " ";
    }

    prtLeafBoundary(root->left);
    prtLeafBoundary(root->right);
}

void prtRightBoundary(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }
    if(root->right != NULL){
        prtRightBoundary(root->right);
    }
    else{
        prtRightBoundary(root->left);
    }
    cout << root->data << " ";
}

void boundaryTraversal(Node* root){
    if(root == NULL){
        return;
    }
    prtLeftBoundary(root);
    prtLeafBoundary(root);

    if(root->right != NULL){
        prtRightBoundary(root->right);

    }
    else{
        prtRightBoundary(root->left);
    }
}


int main(){

    Node* root = createTree();
    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
    levelOrder(root);
    cout << endl;

    boundaryTraversal(root);

    // prtBottomView(root);
    // prtTopView(root);

    // vector<int> leftview;
    // prtLeftView(root, 0, leftview);

    // cout << "Print Left View : " << endl;
    // for(int i = 0; i<leftview.size();i++){
    //     cout << leftview[i] << " ";
    // }
    // cout << endl;
    // vector<int> rightview;
    // prtRightView(root, 0, rightview);

    // cout << "Print Right View : " << endl;
    // for(int i = 0; i<rightview.size();i++){
    //     cout << rightview[i] << " ";
    // }

    return 0;
}