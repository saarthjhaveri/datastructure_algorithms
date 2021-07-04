#include<array>
#include<iostream>
#include<stdio.h>

using namespace std;


#define SIZE 20
int arr[SIZE];
int f=SIZE/2; //front 
int r=SIZE/2; // rear



bool isEmpty()
{
    if(f==r)
    {
        cout<<"EMPTY\n";
        return true;
    }
    return false;
}

bool isFULL()
{
    if(f==-1 || r==SIZE-1)
    {
        cout<<"FULL\n";
        return true;
    }

    return false;
}




void ENQUE_FRONT(int x)
{
    if(isFULL())
    {
        return;
    }

    arr[f--]=x;

}

void ENQUE_BACK(int x)
{
    if(isFULL())
    {
        return;
    }

    arr[++r]=x;
}

void DEQUE_FRONT()
{
    if(isEmpty())
    {
        return;
    }
 
        f++;
       cout<<arr[f]<<"\n";
}

void DEQUE_BACK()
{
    if(isEmpty())
    {
        return;
    }
    cout<<arr[r]<<"\n";

    r--;
}


int main()
{
    ENQUE_FRONT(10);
    ENQUE_BACK(-9);
    ENQUE_FRONT(2);
    ENQUE_FRONT(33);
    DEQUE_BACK();
    DEQUE_FRONT();
    ENQUE_BACK(30);
    ENQUE_FRONT(77);
    DEQUE_BACK();
    DEQUE_FRONT();

}
