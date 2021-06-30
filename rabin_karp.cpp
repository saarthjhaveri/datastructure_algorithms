#include<stdio.h>
#include<math.h>
#include<string>
#include<iostream>
#include<algorithm>

int mod =1e9+7;


using namespace std;

int main()
{
    string s;
    cin>>s;

    string t;
    cin>>t; 

    //task is to check if t is present in s or not 


    //algorithm is sliding algorithm -> for all window we ahve to assign some unique number and 
    // if it matches the given stirng t number then we can say that the strng T is present in S


    //choose a prime number and for a window (t[i]*prime + t[i+1]*prime^2 + t[i+2]*prime^3....)

    int p=29; //choose p=29 as it is the next prime just after 26(no. of alphabets)

    int counter=0;



    for(int i=0;i<t.size();i++)
    {

        counter+= ( (t[i]-'a')  * (pow(p,i)) );

    }


    int checker=0;

    for(int i=0;i<t.size();i++)
    {
        checker+=((s[i]-'a') * pow(p,i)) ;
    }


    for(int i=t.size();i<s.size();i++)
    {
        if(checker== counter)
        {
            cout<<"Found\n";
            return 0;
        }

                 checker += (( (s[i]-'a') *pow(p,t.size())));
                 checker-=  (s[i-t.size()]-'a')  ;
                 checker= checker/p;

    }

       if(checker== counter)
        {
            cout<<"Found\n";
            return 0;
        }


        else
        cout<<"NOt FOund\n";

        return 0;




}
