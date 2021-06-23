
#include<bits/stdc++.h>
using namespace std;

#define ll long long 


class Solution
{
	public:
	
	
	
	
	
	
	ll solver(ll x, ll n, ll p)
	{
	    if(n==0)
	    {
	        return 1;
	    }
	    
	    if(n%2==0)
	    {
	        ll y= solver(x,n/2,p);
	        return (y*y)%p;
	    }
	    else
	    {
	        return (x*solver(x,n-1,p))%p;
	    }
	}
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    
		    ll p= M;
		    
		    return solver(x,n,p);
		    // Code here
		}
};


int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}
