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

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
   
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}
 
int main()
{
    int arr[]= { 5,8,4,6,2,4,3};
    int n =7;

    insertion_sort(arr,n);
}
