#include<array>
#include<iostream>
#include<stdio.h>

using namespace std;


#define SIZE 10
int arr[SIZE];
int f=-1; //front 
int r=-1; // rear

void enque(int x)
{
    if(r==SIZE-1)
    {
        cout<<"OverFlow\n";
        return;
    }

    if(f==-1)f++;
    arr[++r]=x;

}

bool isEmpty()
{
    if(f==-1)
    {
        return true;
    }
    return false;
}


void deque()
{
    if(isEmpty())
    {
        cout<<"UnderFlow\n";
        return;
    }

    if(f==r)
    {
        
        f=-1;
        r=-1;
        return;
    }

    f++;
    return;

}   

void display()
{
    if(isEmpty())
    {
        cout<<"Empty\n";
        return;
    }

    for(int i=f;i<=r;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{


    enque(5);
    enque(8);
    enque(1);
    enque(-3);
    display();
    deque();
    deque();
    enque(5);
    display();



    
}
