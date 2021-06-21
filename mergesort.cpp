#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void merge(vector<int> &A, int l, int r, int mid);

void mergesort(vector<int> &A, int l, int r);

int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    //mergesort

    mergesort(A, 0, n-1);

    for(int i=0;i<n;i++)
    {
        cout<<A[i];
    }
}

void mergesort(vector<int> &A, int l, int r)
{
    if (l < r)
    {
        int mid = l+ (r-l)/2;

        mergesort(A, l, mid);
        mergesort(A, mid + 1, r);

        merge(A, l, r, mid);
    }
    return;
}

void merge(vector<int> &A, int l, int r, int mid)
{
    vector<int> a(mid - l + 1);
    vector<int> b(r - mid);

    for (int i = 0; i < a.size(); i++)
    {
        a[i] = A[l + i];
    }
    for (int i = 0; i < b.size(); i++)
    {
        b[i] = A[mid + i + 1];
    }

    int i = 0, j = 0, k = l;


    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
           A[k]=a[i];
           k++;
            i++;
        }
        else
        {
           A[k]=b[j];
           k++;
            j++;
        }
    }

    while (i < a.size())
    {
         A[k]=a[i];
           k++;
        i++;
    }
    while (j < b.size())
    {
         A[k]=b[j];
           k++;
        j++;
    }

    return;
}
