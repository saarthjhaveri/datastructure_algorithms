#include<cstring>
#include<vector>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    string pattern;
    cin>>pattern;


    int n= pattern.size();
    int lps[n];
    memset(lps,0,sizeof(lps));

    int i=0;
    int j=0;
    while(i<n && j<n)
    {
        if(i==j)
        {
            j++;
        }
       else 
       {
           if(pattern[i]!=pattern[j])
           {
               lps[j]=0;
               j++;
           }
           else
           {
           while(i<j &&  j<n && pattern[i]==pattern[j])
           {
               lps[j]=lps[j-1]+1;
               i++;
               j++;
           }
         

           i=0;
           }
       }

    }

    for(int i=0;i<n;i++)
    cout<<lps[i]<<" ";

    
 i=0;
 j=1;




    while(i<s.size())
    {
        if(j>=n)
        {
            cout<<"Found\n";
            return 0;
        }
        if(pattern[j]==s[i])
        {
            j++;
            i++;
        }
        else 
        {
            if(j==0)
            {
                i++;
            }
            else{
                j=lps[j-1];
            }
        }
    }

    if(j>=n)
    {
        cout<<"Found\n";
        return 0;
    }

    cout<<"NOtfound\n";
    return 0;


}
