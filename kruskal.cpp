#include<bits/stdc++.h>
using namespace std;



bool comp( vector<int>x, vector<int> y)
{
    return x[2]<y[2];
}
bool parent[100001];


int find(int x)
{
    if(parent[x]==x)return x;

    return parent[x]=find(parent[x]);


}

bool uni(int x, int y)
{
    int u= find(x);
    int v= find(y);

    if(u==v)return false;

    parent[u]=v;
    return true;

}


int Kruskal(int A, vector<vector<int>>edges)
{
    for(int i=0;i<=A;i++)
    {
        parent[i]=i;
    }
    

    sort(edges.begin(), edges.end());
    int min_cost=0;


    for(int i=0;i<edges.size();i++)
    {
        if(uni(edges[i][0], edges[i][1]))
        {
            min_cost+=edges[i][2];
        }
    }

}



int main()
{

    int A;
    vector<vector<int>>edges; //weighted edges 
      int total_cost= Kruskal(A, edges);


}
