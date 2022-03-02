#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define int long long

int up[200005][21];
int parent[200005];


// https://cses.fi/problemset/task/1687/



void build(int n)
{

    for (int i = 1;i <= n;i++)
    {
        up[i][0] = parent[i];

        for (int j = 1;j <= 20;j++)
        {
            if (up[i][j - 1] == -1)
            {
                up[i][j] = -1;
            }
            else
            {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }

}



void solve()
{

    ll n;
    cin >> n;

    ll queries;
    cin >> queries;

    memset(up, -1, sizeof(up));

    parent[1] = -1;

    for (int i = 2;i <= n;i++)
    {
        cin >> parent[i];
    }


    build(n);

    while (queries--)
    {
        int num, k;
        cin >> num >> k;

        for (int i = 0;i <= 20;i++)
        {
            if (((1ll << i) & k))
            {
                num = up[num][i];

                if (num == -1)
                {
                    break;
                }
            }
        }

        cout << num << endl;

    }




}


int32_t main()
{

    ll t;
    // cin >> t;
    t = 1;


    while (t--)
    {
        solve();
    }

    return 0;



}
