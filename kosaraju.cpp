#include<bits/stdc++.h>
using namespace std;







void dfs(int src, vector<vector<int>>& g, stack<int>& stk, vector<int>& visited)
{



    visited[src] = 1;

    for (int i = 0;i < g[src].size();i++)
    {

        if (visited[g[src][i]] == 0)
        {
            dfs(g[src][i], g, stk, visited);
        }
    }


    stk.push(src);
    return;

}


void DFS(int src, vector<int>& tempo, vector<vector<int>>& t, vector<int>& visited)
{
    visited[src] = 1;
    tempo.push_back(src);


    for (int i = 0;i < t[src].size();i++)
    {
        if (visited[t[src][i]] == 0)
        {
            DFS(t[src][i], tempo, t, visited);
        }
    }



}



vector<vector<int> > kosaraju(int A, vector<vector<int> >& B) {


    vector<vector<int>>g(A + 1);
    vector<vector<int>>t(A + 1);

    vector<int>visited(A + 1, 0);

    stack<int>stk;



    ///kosa raju , apply dfs then transpose and agan dfs


    ///g is the given graph and t is the transposed 



    for (int i = 0;i < B.size();i++)
    {
        g[B[i][0]].push_back(B[i][1]);
        t[B[i][1]].push_back(B[i][0]);
    }








    //apply dfs first on g
    for (int i = 1;i <= A;i++)
    {
        if (visited[i] == 0)
        {


            dfs(i, g, stk, visited);

        }

    }




    //again making all visited false;


    for (int i = 1;i <= A;i++)
    {
        visited[i] = 0;
    }

    vector<vector<int>>ans;




    while (!stk.empty())
    {


        int tp = stk.top();

        stk.pop();

        if (!visited[tp])
        {
            vector<int>temp;
            DFS(tp, temp, t, visited);
            ans.push_back(temp);

        }




    }


    for (int i = 0;i < ans.size();i++)
    {
        sort(ans[i].begin(), ans[i].end());
    }


    return ans;
}

int main()
{

    int A;
    vector<vector<int>>edges;
    vector<vector<int>> ans = kosaraju(A, edges);


}
