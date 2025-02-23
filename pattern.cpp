#include<iostream>
using namespace std;

int main(){

    // Pattern Square
    cout<<"Square Pattern"<<endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    //Pattern Rectangle

    cout<<"Rectangle pattern"<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }

    // Hollow Rectangle Pattern
    cout<<"Hollow Rectangle Pattern"<<endl;
    for(int row=0;row<5;row++){
        for(int col=0;col<5;col++){
            if(row==0 || row==4){
                cout<<"*  ";
            }
            else{
                if(col==0 || col==4){
                    cout<<"*  ";
                }
                else{
                    cout<<"   ";
                }
            }
        }
        cout<<endl;
    }
    //Half pyramid
    cout<<"Half Pyramid"<<endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <i+1 ; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
        
    }
    //Inverted Half Pyramid
    cout<<"Inverted Half Pyramid"<<endl;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    //Numeric Half pyramid
    cout<<"Numeric Half pyramid"<<endl;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < row+1; col++)
        {
            cout<<col+1<<" ";
        }
        cout<<endl;
        
    }
    //Inverted Numeric Half pyramid
    cout<<"Inverted Numeric Half pyramid"<<endl;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col <n- row; col++)
        {
            cout<<col+1<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}