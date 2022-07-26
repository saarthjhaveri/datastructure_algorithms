#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;



#define pb push_back
#define ll long long
#define ld long double
#define endl "\n"
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rep_r(i,a,n) for(ll i=b-1;i>=a;i--)
#define ff first
#define ss second
#define mp make_pair
#define pi 3.141592653589793238
#define cyes cout<<"YES\n"
#define cno cout<<"NO\n"
#define ps(x,y) fixed<<setprecision(y)<<x  //set precision 



//ordered_set and multi_ordered_set as pbds  
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multi_set tree<int, null_type, less_equal<int> ,rb_tree_tag, tree_order_statistics_node_update>
//member functions :
//1.  <var_name>.order_of_key(k) : number of elements *strictly* less than k
//2.  <var_name>.find_by_order(k) : k-th element in the set



const ll mod = 1e9 + 7;

ll add(ll x, ll y)
{
    return (x % mod + y % mod + mod) % mod;
}

ll mul(ll x, ll y)
{
    return (x % mod * y % mod + mod) % mod;
}

ll sub(ll x, ll y)
{
    return (x % mod - y % mod + mod) % mod;
}


ll modulo(ll x, ll m)
{
    return (x % m + m) % m;
}



ll lcm(ll a, ll b)
{
    return (a * b) / (__gcd(a, b));
}

ll fact(ll x)
{
    if (x <= 1)
    {
        return 1;
    }

    return  mul(x, fact(x - 1));
}

ll power(ll x, ll  y, ll p)
{
    ll res = 1;

    x = x % p;

    if (x == 0) return 0;

    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}



struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;

    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;

}


struct TrieNode {

    TrieNode* children[26];
    bool isEnd;

    TrieNode()
    {
        for (int i = 0;i < 26;i++)
        {
            children[i] = NULL;
        }
        isEnd = false;
    }
};


struct comp {

    bool operator()(pair<ll, ll>x, pair<ll, ll>y) {
        return x.first < y.first;
    }

};

ll dx[8] = { -1,-1,-1,0,1,1,1,0 };
ll dy[8] = { -1,0,1,1,1,0,-1,-1 };


#define int long long

void build_segtree(int s, int e, int idx, vector<int>& A, vector<int>& segtree) {

    if (s == e)
    {
        segtree[idx] = A[s];
        return;
    }

    int mid = (s + e) / 2;

    int lchild = 2 * idx + 1;
    int rchild = 2 * idx + 2;

    build_segtree(s, mid, lchild, A, segtree);
    build_segtree(mid + 1, e, rchild, A, segtree);


    segtree[idx] = (segtree[lchild] + segtree[rchild]);
    return;

}


int range_query(int qs, int qe, int s, int e, int idx, vector<int>& segtree)
{

  //no overlap
    if (qe<s || qs>e)
    {

        return 0;
    }

    //complete overlap
    if (qs <= s && qe >= e)
    {
        return segtree[idx];
    }
  
    //partial overlap

    int mid = (s + e) / 2;

    return (range_query(qs, qe, s, mid, 2 * idx + 1, segtree) + range_query(qs, qe, mid + 1, e, 2 * idx + 2, segtree));
}

void update_query(int idx, int val, int s, int e, int stree_index, vector<int>& segtree)
{
    if (idx <s || idx>e)
    {
        return;
    }

    if (s == e)
    {
        segtree[stree_index] = val;
        return;
    }

    int mid = (s + e) / 2;


    //move left
    if (idx <= mid)
    {
        update_query(idx, val, s, mid, 2 * stree_index + 1, segtree);
    }
    else // move right
    {
        update_query(idx, val, mid + 1, e, 2 * stree_index + 2, segtree);
    }

    segtree[stree_index] = segtree[2 * stree_index + 1] + segtree[2 * stree_index + 2];
}





void solve()
{

        //stree is segment tree and taking input of array aS A
        
    


}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    /*  cerr << "\nTime elapsed : " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n"; */

    return 0;
}  
