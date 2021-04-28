//Kadanes algorithm is used for finding the maximum sum subarray in a given array which contains integer 

#include<iostream>
#include<array>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }


   
    int max_sum[n]; // it reperesent the dp array which contains the maximum sum till ith place 

    max_sum[0]=max(0,arr[0]);

    int global_ans=0;
    global_ans=max(global_ans,max_sum[0]);


    for(int i=1;i<n;i++)
    {
        max_sum[i]=max(arr[i],max_sum[i-1]+arr[i]);
        global_ans=max(global_ans,max_sum[i]); // update the global_ans varibale for every max_sum[i] 
    }

    cout<<global_ans<<"\n";

}
