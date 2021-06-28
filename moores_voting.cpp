#include<array>
#include<iostream>
#include<stdio.h>

using namespace std;



int solver(int arr[], int n)
{
    int count=1;
    int majority=arr[0];
    
    for(int i=1;i<n;i++)
    {
        if(majority==arr[i])
        {
            count++;
        }
        else{
            count--;
        }

        if(count==0)
        {
            majority=arr[i];
            count++;
        }
    }


    if(count>0)
    {
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==majority)c++;
        }

        if(c>n/2)return majority;
    }

    return -1;


    
}
int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }


    //find the majority element if present in the array ie  element whose freq>n/2 if not found return -1


    cout<<solver(arr,n);

}
