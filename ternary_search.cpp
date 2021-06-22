//this algorithm works pretty much same as binary search but the only difference between the two is that this partitions the array in three part rather than two.

//TC analysis -> binary_search = O(2*logn) (base2);
//Tc analysis -> ternary_search = O(4logn) (base3);

//after computation ie by using simple mathemaics we can see that tc of binary search is less than ternary iwe why binary search is often used.
  


#include<iostream>
#include<stdio.h>


using namespace std;


bool ternary_search(int arr[],int l, int r , int key)
{
    if(l<=r)
    {
        int mid1= l+ (r-l)/3;
        int mid2= mid1+(r-l)/3;

        if(arr[mid1]==key || arr[mid2]==key)
        {
            return true;
        }
    
        if(key<arr[mid1])
        {
            return ternary_search(arr,l,mid1-1,key);
        }
        else if(key>arr[mid2])
        {
            return ternary_search(arr,mid2+1,r,key);
        }
        else
        {
            return ternary_search(arr,mid1+1,mid2-1,key);
        }
    }
    else
    {
        return 0;
    }
}

int main()
{

    int key= 13;
    int n=10;

    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int left=0;
    int right=n-1;



    if(!ternary_search(arr,left,right,key))
    {
        cout<<"NOT FOUND\n";
    }

    else
    {
        cout<<"FOUND\n";
    }

}

/*
program output :
FOUND
*/
