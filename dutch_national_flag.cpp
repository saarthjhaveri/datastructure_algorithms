/*algorithm 


0.0... 1 1 1 .... 2 2 2 ....
            {     }
            unknown region 
our task is to minimze the unknown region 
so we start by keeping a pointer low=0,mid=0,high=n-1;


if(arr[mid]=0)swap(arr[mid],arr[low]) // coz we have to keep 0's on left
if(arr[mid]=1) mid++ //just increase 1
else swap(arr[mid],arr[high]) //coz we have to keep 2's on right side 

*/


#include<iostream>

using namespace std;



void dnfsort(int arr[], int n)
{
    int low=0;
    int mid=0;
    int high=n-1;


    while(mid<high)
    {
        if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
        else{
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        /* code */

    }

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    
}
int main()
{
    int n =8;
    int arr[]={2,1,1,2,0,1,0,0};  //arr can consist only of 0 1 or 2


    dnfsort(arr,n);



}
