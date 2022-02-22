#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
// #define BLOCK 555
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
struct query {
    int l;
    int r;
    int i;
};
query Q[200006];
int ar[200007], ans[200006];
int fre[200007];
int cnt = 0;

int BLOCK;

bool comp(query a, query b)
{
    if (a.l / BLOCK != b.l / BLOCK)
        return a.l / BLOCK < b.l / BLOCK;

    return a.r < b.r;
}

void add(int pos)
{
    fre[ar[pos]]++;
    if (fre[ar[pos]] == 1)
        cnt++;
}

void remove(int pos)
{
    fre[ar[pos]]--;
    if (fre[ar[pos]] == 0)
        cnt--;
}



void compress(int n) {


#define arr ar
    map<int, int>mymap;

    int j = 1;

    int b[n];

    for (int i = 0;i < n;i++)
    {
        b[i] = arr[i];
    }


    sort(arr, arr + n);

    for (int i = 0;i < n;i++)
    {
        if (mymap.find(arr[i]) != mymap.end())continue;

        mymap[arr[i]] = j++;
    }


    for (int i = 0;i < n;i++)
    {
        arr[i] = mymap[b[i]];
    }






}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n, q;
    cin >> n;
    cin >> q;
    for (int i = 0;i < n;i++)
        cin >> ar[i];


    compress(n);



    int rootn = 1;
    int i = 1;


    while (i * i <= n)
    {
        rootn = i;
        i++;
    }
    BLOCK = rootn;



    for (int i = 0;i < q;i++) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i, Q[i].l--, Q[i].r--;
    }

    sort(Q, Q + q, comp);

    //why ML = 0 , and MR = -1?
    int ML = 0, MR = -1;
    for (int i = 0;i < q;i++)
    {
        int L = Q[i].l;
        int R = Q[i].r;

        while (ML > L)
            ML--, add(ML);

        while (MR < R)
            MR++, add(MR);

        while (ML < L)
            remove(ML), ML++;

        while (MR > R)
            remove(MR), MR--;

        ans[Q[i].i] = cnt;
    }

    for (int i = 0;i < q;i++)
        cout << ans[i] << '\n';
}
