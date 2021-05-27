#include <array>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>

#define pb push_back
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pi 3.141592653589793238

const int mod = 1e9 + 7;

ll add(ll x, ll y)
{
    return (x + y) % mod;
}

ll mul(ll x, ll y)
{
    return (x * y) % mod;
}

ll modulo(ll x, ll m)
{
    return (x % m + m) % m;
}

using namespace std;

int solver(string A, string B)
{
     int n =A.size();
    int m=B.size();
    
    int lcs[n+1][m+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            lcs[i][j]=0;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        lcs[i][0]=0;
    
    }
    
    for(int j=0;j<m;j++)
    {
        lcs[0][j]=0;
    }
    
    lcs[0][0]=0;
    
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(A[i-1]==B[j-1])
            {
                lcs[i][j]=lcs[i-1][j-1]+1;
            }
            else
            {
                lcs[i][j]= max(lcs[i-1][j],lcs[i][j-1]);
            }
            cout<<lcs[i][j]<<" ";
        }

        cout<<endl;
    }
    
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<lcs[i][j]<<' ';
        }
        cout<<endl;
    }
    return lcs[n][m];
}

void solve(void)
{
    string x,y;
    cin>>x>>y;

    cout<<solver(x,y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {

        solve();
    }
    return 0;
}
