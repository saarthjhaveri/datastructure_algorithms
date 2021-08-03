#include<bits/stdc++.h>
using namespace std;


//note- bellman ford algorithm only works when theres no negative dge weight cycle else it will fail 
// bellman ford vs djisktra 
// bellmanford works for negative edges but djisktra dont but TC of Bf is o(E*V) , where as TC of Djisktra is o(VlogE)

vector<int> BellmanFord( int n, vector<vector<int>>edges)
{
       int dist[n];
	   for(int i=0;i<n;i++)
	   {
	       dist[i]=INT_MAX;
	   }
	   
	   dist[0]=0;
	   
	   vector<int>temp(n);
	   
	   
	   
	   for(int i=0;i<n-1;i++)
	   {
	       
	       for(int j=0;j<edges.size();j++)
	       {
	           
	           if(dist[edges[j][0]]==INT_MAX)continue;
	           
	           int x= dist[edges[j][0]]+edges[j][2];
	           
	           int y= edges[j][1];
	           
	           dist[y]= min( dist[y], x);
	       }
	       
	       for(int j=0;j<n;j++)
	       {
	           temp[j]=dist[j];
	       }
	   }
}





int main()
{

    int A;
    vector<vector<int>>edges;
    vector<int> ans= BellmanFord(A, edges);


}
