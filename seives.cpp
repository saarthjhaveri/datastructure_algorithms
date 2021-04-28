#include<array>
#include<vector>
#include<ostream>
#include<iostream>
#include<math.h>

using namespace std;



int main()
{

    //find no. of primes or print all the primes till n 

    int n;
    cin >> n;
    bool arr[n+1];

    for(int i=0;i<=n;i++)
    {
        arr[i]=1;
    }

    arr[0]=0;
    arr[1]=0;

    
    for(int i=2;i<=n;i++) // instead of x you can rune till sqrt(n), it will make the code more efficient 
    {
        if(arr[i])
        {
            for(int j=2;i*j<=n;j++) 
            {
                arr[i*j]=0;
            }
        }
    }

    for(int i=0;i<=n;i++)
    {
        if(arr[i])
        cout<<i<<" ";
    }


 

}

