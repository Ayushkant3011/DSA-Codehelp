#include<iostream>
#include<string.h>
using namespace std;

int findlength(char ch[],int size){
    int length=0;

    for(int i=0;i<size;i++){
        if(ch[i]=='\0'){
            // ruk jaao 
            break;
        }
        else{
            length++;
        }
    }
    return length;
}

void reversestr(char ch[],int n){
    int i=0;
    int j=n-1;

    while(i<=j){
        swap(ch[i],ch[j]);
        i++;
        j--;
    }
}


void uppercase(char ch[],int n){
    int index=0;

    while(ch[index]!='\0'){
        char currchar=ch[index];
        // check if lowercase, convert it into upper case
        if(currchar>='a' && currchar<='z'){
            ch[index]=currchar-'a'+'A';
        }
        index++;
    }
}

void replacechar(char ch[],int n){
    int index=0;

    while(ch[index]!='\0'){
        char curr=ch[index];

        if(curr=='@'){
            ch[index]=' ';
        }
        index++;
    }
}

bool palindrome(char ch[],int n){
    //n--> length of string

    int i=0;
    int j=n-1;

    while(i<=j){
        if(ch[i]==ch[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    //agar yahan pohoch gye ho 
    // iska matbal palindrome hai 
    // return karo true
    return true;
}


int main(){
    int a =5;
    string str="Ayush";
    string str2="Kant";

    str.append(str2);
    cout<<str;




    // string name;
    // cin>>name;

    // cout<<"Length: "<<name.length()<<endl;
    // cout<<"Empty or not: "<<name.empty()<<endl;
    // cout<<"at Particular position : "<<name.at(0)<<endl;
    // cout<<"Front Pos : "<<name.front()<<endl;
    // cout<<"Back Pos : "<<name.back()<<endl;




    // string name;

    // // cin>>name;
    // getline(cin,name);// spaces ke saath input lena hai toh 

    // cout<<"Printing : "<<name<<endl;

    // cout<<"Printing first character : "<<name[0]<<endl;

    // int index=0;
    // while(name[index]!='\0'){
    //     cout<<"Index:"<<index<<" character: "<<name[index]<<endl;
    //     index++; 
    // }
    // cout<<"Printing at index 6 : "<<name[5]<<endl;

    // int value=(int)name[5];

    // cout<<"Value: "<<value<<endl;

    // char ch[100];

    // // cin>>ch;
    // cin.getline(ch,100);
    // int len=findlength(ch,100);

    // bool ispalindrome=palindrome(ch,len);

    // if(ispalindrome){
    //     cout<<"Valid"<<endl;
    // }
    // else{
    //     cout<<"Invalid"<<endl;
    // }


    // cout<<"Before: "<<ch<<endl;
    // replacechar(ch,100);
    // // uppercase(ch,100);
    // cout<<endl<<"After : "<<ch<<endl;


    // cout<<"Before : "<<ch<<endl;
    // int len=findlength(ch,100);
    // reversestr(ch,len);

    // cout<<"After : "<<ch<<endl;

    // int len=findlength(ch,100);

    // cout<<"Length of string : "<<len<<endl;

    // cout<<"Printing Length: "<<strlen(ch)<<endl; 


    // char ch[10];
    
    // input in char array
    // cin>>ch; // single line me input le skte hai char array me 
    // agar input me space ke saath hoga toh sirf first wala print hoga cchar array ke case me

    // cin.getline(ch,100);

    // cout<<"Printing the value of ch: "<<ch;

    // int arr[4];
    // // input
    // for(int i=0;i<4;i++){
    //     cin>>arr[i];
    // }

    return 0;
}