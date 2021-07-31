#include<bits/stdc++.h>
using namespace std;


struct comp {
    bool operator()(pair<int, int>x, pair<int, int>y)
    {

        return  (x.first > y.first);
    }
};





vector<int> solve(int A, vector<vector<int> >& B, int C) {




    ///dijkstra 

    set<int>myset;
    map<pair<int, int>, int> wt;

    vector<int>g[100001];
    for (int i = 0;i < B.size();i++)
    {
        g[B[i][0]].push_back(B[i][1]);
        g[B[i][1]].push_back(B[i][0]);


        wt[make_pair(B[i][0], B[i][1])] = B[i][2];
        wt[make_pair(B[i][1], B[i][0])] = B[i][2];

    }


    priority_queue< pair<int, int>, vector< pair<int, int> >, comp > pq;


    pq.push(make_pair(0, C));




    int dist[A + 1];
    for (int i = 0;i < A;i++)
    {
        dist[i] = INT_MAX;
    }


    dist[C] = 0;
    bool visited[A + 1];
    for (int i = 0;i <= A;i++)
    {
        visited[i] = 0;
    }


    while (!pq.empty())
    {



        pair<int, int>x = pq.top();
        pq.pop();

        dist[x.second] = min(dist[x.second], x.first);
        visited[x.second] = true;



        for (int i = 0;i < g[x.second].size();i++)
        {
            if (visited[g[x.second][i]] == 0)
            {
                pair<int, int>temp;
                temp.first = wt[make_pair(x.second, g[x.second][i])] + x.first;

                temp.second = g[x.second][i];
                pq.push(temp);
            }
        }
    }


    vector<int>v;
    for (int i = 0;i < A;i++)
    {
        if (dist[i] >= INT_MAX)
        {
            v.push_back(-1);
        }
        else
        {
            v.push_back(dist[i]);
        }
    }

    return v;


    // return ans;
}


int main()
{
    vector < vector<int> >edges;

    int src;
    int A; //total nodes


  vector<int> all_distances=solve(A, edges, src);



}
