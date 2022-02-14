#include<bits/stdc++.h>

using namespace std;



// range updates and find minimum of the given range 


void build(int s, int e, int idx, int arr[], int tree[])
{       
    if(s==e)
    {
        tree[idx]=arr[s];
        return;
    }

    int lc= 2*idx+1;
    int rc= 2*idx+2;

    int mid= (s+e)/2;


    build(s,mid,lc,arr,tree);
    build(mid+1,e,rc, arr, tree);

    tree[idx]= min(tree[lc], tree[rc]);
}

void range_update(int s, int e, int qs, int qe, int idx, int tree[], int lazy[], int val)
{
    if(lazy[idx]!=0)
    {
        tree[idx]+=lazy[idx];

        if(s!=e)
        {
            lazy[2*idx+1]+=lazy[idx];
            lazy[2*idx+2]+=lazy[idx];
        }

        lazy[idx]=0;
    }

    if(e<qs || s>qe ) // no overlap
    {
        return;
    }
    if(qs<=s && qe>=e)// complete overlap
    {
        tree[idx]+=val;
         if(s!=e)
        {
            lazy[2*idx+1]+=val;
            lazy[2*idx+2]+=val;
        }

        return;
    }

    int mid= (s+e)/2;

    range_update(s,mid,qs,qe,2*idx+1,tree,lazy,val);
    range_update(mid+1,e,qs,qe,2*idx+2,tree,lazy,val);
    
    tree[idx]= min(tree[2*idx+1], tree[2*idx+2]);

    return;
}

int range_query(int s, int e,int qs, int qe, int idx, int tree[], int lazy[])
{   

    if(lazy[idx]!=0)
    {
        tree[idx]+=lazy[idx];

        if(s!=e)
        {
            lazy[2*idx+1]+=lazy[idx];
            lazy[2*idx+2]+=lazy[idx];
        }

        lazy[idx]=0;
    }


    if(e<qs || s>qe ) // no overlap
    {
        return INT_MAX;
    }

    
    if(qs<=s && qe>=e)// complete overlap
    {
        return tree[idx];
    }


    //partial overlap

    int mid= (s+e)/2;


    int lc= range_query(s,mid,qs,qe,2*idx+1,tree,lazy);
    int rc= range_query(mid+1,e,qs,qe,2*idx+2,tree,lazy );

    return tree[idx]=min(lc,rc);







}

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int tree[4*n+2];
    int lazy[4*n+2];


    memset(lazy,0,sizeof(lazy));
    build(0,n-1,0,arr, tree);
    


}
