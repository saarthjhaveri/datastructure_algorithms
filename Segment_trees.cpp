#include<bits/stdc++.h>

using namespace std;

//given some queries and an array , find the sum of range given in query1->[L,R] and in query2->update the idx of array \


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


    //complete overlap
    if (qs <= s && qe >= e)
    {
        return segtree[idx];
    }
    //no overlap
    if (qe<s || qs>e)
    {

        return 0;
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


int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0;i < n;i++)
    {
        cin >> arr[i];
    }

    vector<int>segtree(4 * n);
    build_segtree(0, n - 1, 0, arr, segtree);


    for (int i = 0;i < segtree.size();i++)
    {
        cout << segtree[i] << " ";
    }

    cout << endl;

    // return 0;




    cout << range_query(0, 3, 0, n - 1, 0, segtree) << endl;

    update_query(2, 6, 0, n - 1, 0, segtree);

    for (int i = 0;i < segtree.size();i++)
    {
        cout << segtree[i] << " ";
    }

    cout << endl;
    cout << range_query(0, 3, 0, n - 1, 0, segtree) << endl;

}
