#include<bits/stdc++.h>
using namespace std;




vector<int> solve(int A, vector<vector<int>>& B)
{

    int indeg[A + 1];
    memset(indeg, 0, sizeof(indeg));


    for (int i = 0;i < B.size();i++)
    {
        indeg[B[i][1]]++;
    }

    vector<int>g[A + 1];

    for (int i = 0;i < B.size();i++)
    {
        g[B[i][0]].push_back(B[i][1]);
    }




    vector<int>ans;
    bool visited[A + 1];
    for (int i = 0;i <= A;i++)
    {
        visited[i] = 0;
    }



    set<int>myset;

    for (int i = 1;i <= A;i++)
    {
        if (indeg[i] == 0)
        {
            myset.insert(i);

        }
    }






    while (myset.size() > 0)
    {


        set<int>::iterator itr = myset.begin();

        int y = *itr;

        visited[y] = 1;

        myset.erase(y);

        ans.push_back(y);
        int x = y;


        bool fg = 1;


        for (int i = 0;i < g[x].size();i++)
        {

            if (visited[g[x][i]] == 1)
            {
                continue;
            }


            indeg[g[x][i]]--;



            if (indeg[g[x][i]] == 0)
            {
                myset.insert(g[x][i]);

                fg = 0;
            }
        }



    }


    return ans;


}


int main()
{

    int A;
    vector<vector<int>>edges;
    vector<int> ans = solve(A, edges);


}
