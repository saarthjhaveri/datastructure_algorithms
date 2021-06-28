#include<array>
#include<iostream>
#include<stdio.h>

//we can find kth smallest or kth largest element in an array in time much lesser than o(nlogn) and without any auxillary space 

using namespace std;


int solver(int arr[], int k, int start, int end)
{
    int pivot= arr[end];
    int piv_index=start;

    for(int i=start;i<end;i++)
    {
        if(arr[i]<=pivot)
        {
            swap(arr[i],arr[piv_index]);
            piv_index++;
        }
    }

    swap(arr[end],arr[piv_index]);

    if(piv_index==k-1)
    {
        return arr[piv_index];
    }
    else if(piv_index>k-1)
    {
        return solver(arr,k,start,piv_index-1);
    }
    else
    {
        return solver(arr,k,piv_index+1,end);
    }


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

    int k;// find the indice of the kth smallest element in an array 
    cin>>k;

    cout<<solver(arr,k,0,n-1);
}
