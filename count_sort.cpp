#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<iostream>



using namespace std;

vector<int> count_sort(int arr[], int n)
{
    //find the maxm element in arr , and make an extra array of that size to store the freq 

int maxm= 0;

    for(int i=0;i<n;i++)
    {
        maxm=max(maxm, arr[i]);
    }



    vector<int>freq(maxm+1);

    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }

  
    //find the possible position of array elements in freq array;


    vector<int>position(maxm+1);
    position[0]= freq[0];

    for(int i=1;i<=maxm;i++)
    {
        position[i]= position[i-1]+freq[i];
    }

   for(int i=0;i<=maxm;i++)
   {
       position[i]--;
   }



    //now make the final array which will correspond to the sorted array acc to the indice 
    vector<int>final(n);
    
    for(int i=0;i<n;i++)
    {
        final[position[arr[i]]]=arr[i];
        position[arr[i]]--;
    }


return final;


}


int main()
{
    int arr[]= {1,3,2,5,3,2,6};


    vector<int>sorted_arr(7);

   sorted_arr=  count_sort(arr,7);
    for(int i=0;i<sorted_arr.size();i++)
    {
        cout<<sorted_arr[i]<<' ';
    }



}


