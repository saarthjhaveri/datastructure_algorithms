#include<cstring>
#include<vector>
#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>


using namespace std;

vector<int> z_function(string s);
int main()
{

//we need to make an array of the maxlength which occurs as a prefix for the input string.  
    int i;
    string s;
    cin>>s;

    vector<int>temp;
    temp=z_function(s);

    for(i=0;i<temp.size();i++)
    {
        cout<<temp[i]<<endl;
    }



}

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    int l=0,r=0;
    for (int i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l  = i, r = i + z[i] - 1;
    }
    return z;
}
