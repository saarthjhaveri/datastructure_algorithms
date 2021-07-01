#include<stack>
#include<iostream>
#include<stdio.h>

using namespace std;


#define SIZE 10
int arr[SIZE];
int top=-1;


 bool isEmpty()
 {
     if(top==-1)
     {
         return true;
     }
     return false;
 }

 void push(int val)
 {
     if(top==SIZE-1)
     {
         cout<<"Stack OverFlow\n";
     }
     else
     {
         arr[++top]=val;
     }
 }

 void pop()
 {
     if(isEmpty())
     {
         cout<<"Stack Underflow\n";
     }
     else
     {
         top--;
     }
 }

 void display_stack()
 {
     int x=top;

     if(isEmpty())
     {  
         cout<<"Stack is empty\n";
     }
     else
     {
         cout<<"Stack elements are \n";
         while(x)
         {
               cout<<arr[x]<<" ";
               x--;
         }
         cout<<arr[x]<<" ";

         cout<<"\n";
     }

 }
 void show_top()
 {
     if(isEmpty())
     {
             cout<<"Stack is empty\n";
     }
     else
     {
         cout<<"Element at the top is "<<arr[top]<<"\n";
     }
 }


int main()
{
    pop();
    push(6);
    push(-3);
    push(8);
    show_top();
    pop();
    push(10);
    display_stack();
    pop();
    pop();
    push(3);
    display_stack();
  
}
