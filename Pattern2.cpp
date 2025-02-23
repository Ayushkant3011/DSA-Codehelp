#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter Value of n :";
    cin>>n;

    cout<<"Full Pyramid"<<endl;

    for (int row = 0; row < n; row++)
    {
        //space
        for (int col = 0; col < n-row-1; col++)
        {
            cout<<" ";
        }
        //Stars
        for (int col = 0; col < row+1; col++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    
    cout<<"Inverted Full Pyramid"<<endl;
    for (int row = 0; row < n; row++)
    {
        // Spaces
        for (int col = 0; col < row; col++)
        {
            cout<<" ";
        }
        // Stars
        for (int col = 0; col < n-row;col++)
        {
            cout<<"* ";
        }cout<<endl;
    }    
    cout<<"Diamond Pattern"<<endl;

    for (int row = 0; row < n; row++)
    {
        //space
        for (int col = 0; col < n-row-1; col++)
        {
            cout<<" ";
        }
        //Stars
        for (int col = 0; col < row+1; col++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    for (int row = 0; row < n; row++)
    {
        // Spaces
        for (int col = 0; col < row; col++)
        {
            cout<<" ";
        }
        // Stars
        for (int col = 0; col < n-row;col++)
        {
            cout<<"* ";
        }cout<<endl;
    }
    
    cout<<"Hollow Pyramid"<<endl;
    for (int row = 0;  row< n; row++)
    {
        // spaces
        for (int col = 0; col < n-row-1; col++)
        {
            cout<<" ";
        }
        // stars
        for (int col = 0; col < row+1; col++)
        {
            if (col==0 || col==row+1-1)
            {
                cout<<"* ";
            }
            else
            {
                cout<<"  ";
            }
        }cout<<endl;
    }
    
    cout<<"Inverted Hollow Pyramid"<<endl;
    for (int row = 0;  row< n; row++)
    {
        // spaces 
        for (int col = 0; col < row; col++)
        {
            cout<<" ";
        }
        // stars
        for (int col = 0; col < n-row; col++)
        {
            if (col==0 || col==n-row-1)
            {
                cout<<"* ";
            }
            else
            {
                cout<<"  ";
            }
        }cout<<endl;
    }

    cout<<"Hollow Diamond"<<endl;
    for (int row = 0;  row< n; row++)
    {
        // spaces
        for (int col = 0; col < n-row-1; col++)
        {
            cout<<" ";
        }
        // stars
        for (int col = 0; col < row+1; col++)
        {
            if (col==0 || col==row+1-1)
            {
                cout<<"* ";
            }
            else
            {
                cout<<"  ";
            }
        }cout<<endl;
    }
    for (int row = 0;  row< n; row++)
    {
        // spaces
        for (int col = 0; col < row; col++)
        {
            cout<<" ";
        }
        // stars
        for (int col = 0; col < n-row; col++)
        {
            if (col==0 || col==n-row-1)
            {
                cout<<"* ";
            }
            else
            {
                cout<<"  ";
            }
        }cout<<endl;
    }   

    return 0;
}