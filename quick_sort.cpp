#include <array>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>

using namespace std;



int  partition(vector<int> &arr, int s, int e)
{

    int pivot= arr[e];

    int piv_index=s;

    for(int i=s;i<e;i++)
    {
        if(arr[i]<=pivot)
        {
            swap(arr[i],arr[piv_index]);
            piv_index++;
        }
    }

    swap(arr[e],arr[piv_index]);

    return piv_index;

}

void quicksort(vector<int> &arr, int s, int e)
{


    if(s<e)
    {
        int p_index= partition(arr,s,e);

        quicksort(arr,s,p_index-1);
        quicksort(arr,p_index+1,e);

    }
}


int main()
{
    int n=5;
  

    vector<int>arr(n);
    arr[0]=3;
    arr[1]=1;
    arr[2]=2;
    arr[3]=7;
    arr[4]=5;

    quicksort(arr,0,n-1);

    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }


}
