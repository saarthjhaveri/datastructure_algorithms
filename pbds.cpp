/*
PBDS(policy based data structure) can perform all the functions which an ordered_set can do , additionally 
we can access in between elements of set , using find_by_order and find_by_key function. 
*/



#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

#define pbds tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{

    pbds p;
    p.insert(5);
    p.insert(3);
    p.insert(2);
    p.insert(7);


    //p -> {2,3,5,7}
    
    cout<<"The value at index 3 is "<<*p.find_by_order(3)<<"\n"; //this is 0 based indexing and will print 7

    cout<<"The index of number 3 is "<<p.order_of_key(3)<<"\n";   // this will print 1

    cout<<"The index of number 4 is "<<p.order_of_key(4)<<"\n";  // this will print 2 (as its the desired location
    
     cout<<"The index of number 8 is "<<p.order_of_key(8)<<"\n"; // this will print 4 

}
