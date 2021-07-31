#include<bits/stdc++.h>
using namespace std;


vector<vector<int> >solve(vector<vector<int> >& A) {



    int n = A.size();

    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++) {

            if (A[i][j] == -1)
            {
                A[i][j] = INT_MAX;
            }

        }
    }


    for (int k = 0;k < n;k++)
    {
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {

                if (A[i][k] == INT_MAX || A[k][j] == INT_MAX)
                {
                    continue;
                }


                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
            }
        }
    }


    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (A[i][j] == INT_MAX)
            {
                A[i][j] = -1;
            }
        }
    }

    return A;

}

int main()
{
    vector < vector<int> >adjacency_matrix;



    vector<vector<int>>all_distances = solve(adjacency_matrix);



}
