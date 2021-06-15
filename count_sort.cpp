 
// Counting sort is a sorting technique based on keys between a specific range. It works by counting the number of objects having distinct key values (kind of hashing).
//   Then doing some arithmetic to calculate the position of each object in the output sequence.

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

  
    //now make the final array which will correspond to the sorted array
    vector<int>final;
  

    for(int i=0;i<=maxm;i++)
    {
        while(freq[i]--)
        {
            final.push_back(i);
        }
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


