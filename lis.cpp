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

int main()
{
    int n;
    cin>>n;

    vector<int>A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }


    vector<int>ans;

    ans.pb(A[0]);


    for(int i=1;i<n;i++)
    {
        if(A[i]>ans[ans.size()-1])
        {
            ans.pb(A[i]);
        }
        else
        {

            if(A[i]<=ans[0])
            {
                ans[0]=A[i];
                continue;
            }
            int low=0;
            int high= ans.size()-1;


            while(low<=high)
            {

                int mid= low+(high-low)/2;
                if(mid==0)
                {
                  low++;
                }
               else if(ans[mid]>=A[i] && ans[mid-1]<A[i])
                {
                    ans[mid]=A[i];
                    break;
                }
                else if(ans[mid]<A[i])
                {
                   
                     low=mid+1;
                }
                else
                {
                    high=mid-1;
                }

            }


        }
        
    }


    cout<<"length is "<<ans.size()<<"\n";

    // for(int i=0;i<ans.size();i++)
    // {
    //     cout<<ans[i]<<"  ";
    // }
}
