#include<bits/stdc++.h>
using namespace std;
//find all the primefactors of n in the fastses possible way
vector<int>spf;
//spf stands for smallest prime factor


void seives(int n)
{
    spf.resize(n + 1);

    for (int i = 0;i <= n;i++)
    {
        spf[i] = i;
    }


    bool primes[n + 1];

    memset(primes, true, sizeof(primes));

    primes[0] = false;
    primes[1] = false;

    for (int i = 2;i * i <= n;i++)
    {
        if (primes[i])
        {
            for (int j = 2;i * j <= n;j++)
            {
                spf[i * j] = min(i, spf[i * j]);
                primes[i * j] = false;
            }
        }
    }

}

int main()
{
    int n;
    cin >> n;

    seives(n);


    //print all primes factors


    while (n != 1)
    {
        cout << spf[n] << " ";
        n = n / spf[n];
    }





}
