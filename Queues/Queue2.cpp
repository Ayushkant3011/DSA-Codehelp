#include<iostream>
#include<queue>
#include<string>
using namespace std;




int main(){
    string str = "ababc";
    queue<char> q;
    int freq[26]={0};

    for(int i=0; i<str.length();i++){
        char ch = str[i];
        freq[ch-'a']++;
        q.push(ch);


        // Answer find karo 

        while(!q.empty()){
            char frontCharacter = q.front();
            if(freq[frontCharacter-'a']>1){
                // yaani ye answe nahi h 
                q.pop();
            }
            else{
                // == 1 wala case 
                // iska matbal yehi ans hai
                cout<<frontCharacter << " ->";
                break;
            }
        }
        if(q.empty()){
            // koi ans nahi mila 
            cout << "#" << " ->";
        }
    }

    return 0;
}