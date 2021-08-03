//Prims algorithm is used to construct the minimum spanning tree ie the cost of the edges should be minimum and the tree should be such that we can reach any node from any vertex 

#include<bits/stdc++.h>

using namespace std;


#define ll long long 
const ll mod=1e9+7;

ll add(ll x , ll y)
{
    return (x+y)%mod;
}


struct comp{
    
    bool operator()(pair<int,int>x , pair<int,int> y){
        
        
        return x.first >y.first;
    }
    
};


int solve(int A, vector<vector<int> > &B) {
    
    
    
    priority_queue<pair<int,int>, vector<pair<int,int>> , comp>pq;
    
    vector<int>g[100001];
    map<pair<int,int>,int>wt;
    
    for(int i=0;i<B.size();i++)
    {
        g[B[i][0]].push_back(B[i][1]);
        g[B[i][1]].push_back(B[i][0]);
        
        
        pair<int,int>x= make_pair(B[i][0],B[i][1]);
        wt[x]=B[i][2];
        x= make_pair(B[i][1],B[i][0]);
        wt[x]=B[i][2];
     }
    
    
    
    bool visited[100001];
    for(int i=0;i<=A;i++){
        visited[i]=0;
    }
    
    ll sum=0;
    
    
    pq.push(make_pair(0,1));
    
    
    
    while(!pq.empty())
    {
        
        auto x= pq.top();
        pq.pop();
        
        
        
        if(!visited[x.second])
        {
             sum= add(sum, x.first); 
        }
        visited[x.second]=1;
        

        
        
        for(auto it: g[x.second])
        {
      
            if(!visited[it])
            {
                pair<int,int> pp= make_pair( wt[ {x.second,it} ] , it );
                
                pq.push(pp);
            }
            
        }
        
    }
    
    return sum;
    
}





int main()
{
    vector<vector<int>>edges;
    int A;

    cout<<solve(A, edges)<<endl;

}
