//Bubble sort-> the sorting is based on pushing  the maximum element of array to the end of the array 


#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<iostream>



using namespace std;

void bubble_sort(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[]= { 2,3,4,1,2,3,10,1,5,8};

    int n=10;

    bubble_sort(arr,n);
}
