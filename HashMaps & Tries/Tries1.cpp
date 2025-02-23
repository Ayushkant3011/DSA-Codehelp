#include<iostream>
using namespace std;


class TrieNode{
    public:
        char value;
        TrieNode* children[26]; // array of ptr
        bool isTerminal;

        TrieNode(char val){
            this->value = val;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            this->isTerminal = false;
        }
};

// Insertion
void insertword(TrieNode* root, string word){
    // cout << "Recieved Word : " << word << " for insertion" << endl;
    // base case
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch -'a';
    TrieNode* child ;
    if(root->children[index] != NULL){
        // present
        child = root->children[index];
    }
    else{
        // absent 
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recursion 
    insertword(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word){
    // base case
    if(word.length() == 0){
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch-'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        // present or found 
        child = root->children[index];
    }
    else{
        // not found 
        return false;
    }

    // baaki recursion 
    bool recursionAns = searchWord(child, word.substr(1));
    return recursionAns;
}

void deleteWord(TrieNode* root, string word){
    // base case
    if(word.length() == 0){
        root->isTerminal = false;
        return;
    }

    // 1 case mera 
    char ch = word[0];
    int index = ch-'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        // prseent
        child = root->children[index];
    }
    else{
        // not present 
        return;
    }
    // baaki recursion tera
    deleteWord(child,word.substr(1)); 
}

int main(){
    TrieNode* root = new TrieNode('-');

    insertword(root, "cater");
    insertword(root, "care");
    insertword(root, "com");
    insertword(root, "lover");
    insertword(root, "loved");
    insertword(root, "load");
    insertword(root, "lov");
    insertword(root, "bat");
    insertword(root, "cat");
    insertword(root, "car");
    
    cout << "Insertion Done" << endl;

    if(searchWord(root,"loved") ){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }

    deleteWord(root, "loved");

    if(searchWord(root,"loved") ){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }

    return 0;
}