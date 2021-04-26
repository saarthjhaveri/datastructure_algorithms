#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include<stack>
#include<queue>
#include <bitset>

#define ll long long 
using namespace std;





struct trienode{
     
     struct trienode *children[26];
     bool isEnd;
    //  int count=0;
     
 };
 
 struct trienode* getNode(void)
 {
     trienode*np=new trienode();
     np->isEnd =false;
     for(int i=0;i<26;i++){
         np->children[i]=NULL;
     }
     
    //  np->count=0;
     return np;
     
 }
 
 void insert(trienode* root, string s)
 {
     trienode*p= root;
     
     for(int i=0;i<s.size();i++)
     {
           if(p->children[s[i]-'a']==NULL)
           {
               trienode*temp=getNode();
               p->children[s[i]-'a']=temp;
               
           }
           p=p->children[s[i]-'a'];
     }
     
     p->isEnd=true; 
 }

bool search(trienode* root, string s)
{
    trienode*p=root;
    
    for(int i=0;i<s.size();i++)
    {
        if(p->children[s[i]-'a']==NULL)
        {
            return 0;
        }
        
        p=p->children[s[i]-'a'];
    }
    
    if(p->isEnd)
    {
        return 1;
    }
    return 0;
}
vector<int> solve(vector<string> &A, vector<string> &B) {
    
    trienode*root= new trienode();
    for(int i=0;i<A.size();i++)
    {
        insert(root,A[i]);
    }
    
    vector<int>ans;
    for(int i=0;i<B.size();i++)
    {
        if(search(root,B[i]))
        {
            ans.push_back(1);
        }
        else
        {
            ans.push_back(0);
        }
    }
    
    return ans;
}



int main()
{
  //A is the given dictionary and B is the set of words , find if B[i] is present[1] in the dictionary or not[0] using tries;
    int n,m;
    cin>>n>>m;
    vector<string>A(n),B(m);

    for(int i=0;i<n;i++)cin>>A[i];

    for(int i=0;i<m;i++)cin>>B[i];



    vector<int>ans = solve(A,B);

    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    
}
