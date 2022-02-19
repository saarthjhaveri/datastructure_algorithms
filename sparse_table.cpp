#include<bits/stdc++.h>

using namespace std;

//raneg minimum query in just o(1)

//only applicable for static and no updates and only for max,min,gcd because even if the interval  overlaps it wont affect 
//not for sum,mul. etc -> use segtrees for this 


#define int long long 
const int MAX_N = 200007;
const int LOG = 20;

int arr[MAX_N];
int m[MAX_N][LOG];




int query(int l, int r)
{

    // int x = log(r - l + 1) / log(2);

    int k = 0;
    int len = r - l + 1;

    while ((1 << (k + 1)) <= (len))k++;




    return min(m[l][k], m[r - (1 << k) + 1][k]);
}


void build(int n, int arr[])
{
    for (int i = 0;i < n;i++)
    {
        m[i][0] = arr[i];
    }

    for (int k = 1;k < LOG;k++)
    {
        for (int i = 0;i + (1 << k) - 1 < n;i++)
        {
            m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);

        }
    }
}



int32_t main()
{
    int n;
    cin >> n;

    int q;
    cin >> q;



    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //build sparse table

    build(n, arr);




    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;


        cout << query(l, r) << endl;

    }








}
