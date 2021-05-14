#include<vector>
#include<array>
#include<iostream>
#include<map>
#include<set>

using namespace std;


// Refer ques on gfg :- 
https://practice.geeksforgeeks.org/problems/interesting-queries4742/1/?category[]=Map&category[]=Map&problemStatus=unsolved&difficulty[]=2&page=1&query=category[]MapproblemStatusunsolveddifficulty[]2page1category[]Map#
int main()
{
    
    int n,k,q;  
    cin>>n>>q>>k;


    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int ans[q];

    int queries_l[q],queries_r[q];
    for(int i=0;i<q;i++)
    {
        cin>>queries_l[i];
        cin>>queries_r[i];

        queries_l[i]--;
        queries_r[i]--;
    }

    pair<int,pair<int,int> >pairt[q];

    for(int i=0;i<q;i++)
    {
        pairt[i].first=queries_l[i];

        pairt[i].second= make_pair(queries_r[i],i);
    }

    
    sort(pairt,pairt+q);

  



    int l=pairt[0].first;
    int r=pairt[0].second.first;

    map<int,int>mymap;
    int count=0;
    for(int i=l;i<=r;i++)
    {
        mymap[arr[i]]++;
        if(mymap[arr[i]]==k)
        {
            count++;
        }
    }



   
    ans[pairt[0].second.second]=count;
    for(int i=1;i<q;i++)
    {
       while(l<pairt[i].first)
       {
           if(mymap[arr[l]]==k)
           {
               count--;
           }
           mymap[arr[l]]--;
           l++;
       }

       if(pairt[i].second.first>r)
       {
           r++;
           while(r<=pairt[i].second.first)
           {

               mymap[arr[r]]++;
               if(mymap[arr[r]]==k)
               {
                   count++;
               }
               r++;
           }
           r--;
       }
       else
       {
       
           while(r>pairt[i].second.first)
           {
               
               if(mymap[arr[r]]==k)
               {
                
                   count--;
               }
               mymap[arr[r]]--;
               r--;
           }
       }
      


       ans[pairt[i].second.second]=count;
    }


    for(int i=0;i<q;i++){
        cout<<ans[i]<<" ";
    }



}
