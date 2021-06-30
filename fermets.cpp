#include<math.h>
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
  
    //basic application of fermets little theorem 
    // our task is to find (a/b)%m = ( (a%m) * (b^(-1))%m)%m;
    ll a,b,m;

    cin>>a>>b>>m;


    cout << ((a%m) * (b^(m-2)%m))%m

    
}
