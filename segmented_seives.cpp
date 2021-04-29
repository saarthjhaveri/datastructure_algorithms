/*The idea of a segmented sieve is to divide the range [0..n-1] in different segments and compute primes in all segments one by one. This algorithm first uses Simple Sieve to find primes smaller than or equal to √(n). Below are steps used in Segmented Sieve.

Use Simple Sieve to find all primes up to the square root of ‘n’ and store these primes in an array “prime[]”. Store the found primes in an array ‘prime[]’.
We need all primes in the range [0..n-1]. We divide this range into different segments such that the size of every segment is at-most √n
Do following for every segment [low..high] 
Create an array mark[high-low+1]. Here we need only O(x) space where x is a number of elements in a given range.
Iterate through all primes found in step 1. For every prime, mark its multiples in the given range [low..high].
In Simple Sieve, we needed O(n) space which may not be feasible for large n. Here we need O(√n) space and we process smaller ranges at a time (locality of reference)*/

#include <array>
#include <vector>
#include <ostream>
#include <iostream>
#include <math.h>
#define ll long long

using namespace std;

vector<ll> seives(void)
{

    vector<ll>primes;
    int max_limit = 50;

    bool isPrimes[max_limit];

    for (int i = 0; i < max_limit; i++)
    {
        isPrimes[i] = true;
    }
    isPrimes[0] = false;
    isPrimes[1] = false;
    int x = sqrt(max_limit);

    for (int i = 2; i <= x; i++)
    {
        if (isPrimes[i])
        {
            for (int j = 2; i * j <= max_limit; j++)
            {
                isPrimes[i*j] = false;
            }
        }
    }

    for (int i = 0; i <max_limit;i++)
    {
        if(isPrimes[i]){
            primes.push_back(i);
            cout<<i<<" ";
        }
    }
    return primes;
}

void printPrimes(ll l, ll r, vector<ll> &primes)
{

    ll n=primes.size();

    bool isPrimes[r-l+1];

    for(int i=0;i<=r-l;i++){
        isPrimes[i]=true;
    }
  
  //now the isPrimes boolean array will represent the primes from l to r , 0 indice corresponding to lth position and so on




    for(int i=0;i<n;i++)
    {
        if((ll)primes[i]*primes[i]>r)
        {
            break;
        }
        ll base_value= (l/primes[i])*primes[i];

        if(base_value<l){
            base_value+=primes[i];
        }

        for(int j=base_value;j<=r;j+=primes[i])
        {
            isPrimes[j-l]=false;

        }

        if(base_value==primes[i])// this condition helps to keep us the check that we arent making the already prime number as false 
        {
            isPrimes[base_value-l]=true;
        }

    }


    for(int i=0;i<=r-l;i++)
    {
        if(i+l<=1)
        {
            continue;
        }
        if(isPrimes[i])
        {
            cout<<i+l<<" ";
        }
    }
    return;
}

int main()
{
    vector<ll> primes = seives();
    int queries;
    cin >> queries;

    while (queries--)
    {
        ll left, right;
        cin >> left >> right;

        printPrimes(left, right, primes);
    }
}
