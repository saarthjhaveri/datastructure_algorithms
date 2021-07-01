#include<stack>
#include<iostream>
#include<stdio.h>


//implementation of get min function in o(1) time using an extra stack where we are updating the minimum element till the number of elements pushed

using namespace std;

stack<int>elementStk;
stack<int>minStk;


int get_min()
{
    if(minStk.empty()){
        return -1;
    }
    else
    {
        return minStk.top();
    }

}

void pop()
{
    if(elementStk.empty())
    {
        return;
    }
    
    if(elementStk.top()== minStk.top())
    {
        minStk.pop();
        elementStk.pop();
    }
    else
    {
        elementStk.pop();
    }
}

void push(int val)
{
    elementStk.push(val);
    if(minStk.size()==0 || val<=minStk.top())
    {
        minStk.push(val);
    }
}

int stk_top()
{
   
  if (elementStk.empty()) return -1;
  return elementStk.top();
}



int main()
{

    push(3);
    push(7);
    push(9);
    push(10);
    pop();
    pop();
    cout<<"Current top is : "<<stk_top()<<"\n";
    cout<<"Minimum element is: "<<get_min()<<"\n";
    push(8);
    push(-2);
    push(13);
   cout<<"Current top is : "<<stk_top()<<"\n";
    cout<<"Minimum element is: "<<get_min()<<"\n";
    pop();
    pop();
    cout<<"Minimum element is: "<<get_min()<<"\n";
    
}
