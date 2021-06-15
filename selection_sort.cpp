// seelction sort-> idea is based on finding the smallest element from the right most side and then swap it with the curr indice




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

#define pb push_back
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pi 3.141592653589793238

using namespace std;

void selection_sort(int arr[], int n )
{

    for(int i=0;i<n-1;i++)
    {
        int minm=arr[i];
        int min_ind=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<minm)
            {
                minm=arr[j];
                min_ind=j;
            }
        }

        swap(arr[i], arr[min_ind]);
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }



    return ;
}

int main()
{
    int arr[]= { 5,8,4,6,2,4,3};
    int n =7;

    selection_sort(arr,n);
}
