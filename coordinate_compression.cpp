#include<bits/stdc++.h>

using namespace std;

// The coordinate compression trick is widely used in problems where due to the out of range constraints, we cannot use a particular Data structure or Algorithm. In those cases, the Coordinate Compression comes to our rescue. 


vector<int> compress(int n, int arr[])
{

    int b[n];
    for (int i = 0;i < n;i++)
    {
        b[i] = arr[i];
    }


    sort(arr, arr + n);

    map<int, int>mymap;

    int j = 1;


    for (int i = 0;i < n;i++)
    {
        if (mymap.find(arr[i]) != mymap.end())continue;
        mymap[arr[i]] = j++;
    }

    vector<int>ans;

    for (int i = 0;i < n;i++)
    {
        ans.push_back(mymap[b[i]]);
    }


    return ans;




}
int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0;i < n;i++)
    {
        cin >> arr[i];
    }

    vector<int>updated_array = compress(n, arr);

    for (auto i : updated_array)
    {
        cout << i << " ";
    }

}
