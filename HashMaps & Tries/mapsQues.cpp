#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;


void countchar(unordered_map<char,int> &mapping, string str){
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        mapping[ch]++;
    }
}

int main(){
    string str= "lovebabbar";
    unordered_map<char, int> mapping;
    // map<char, int> mapping; // oredered map

    countchar(mapping, str);

    for(auto i: mapping){
        cout << i.first << " -> " << i.second << endl;
    }
    
    return 0;
}