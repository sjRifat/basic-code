#include<bits/stdc++.h>
using namespace std;

int partitionn(int A[],int p,int r)
{
    int x=A[r];
    int i=p-1;
    for(int j=p; j<=r-1;j++)
    {
        if(A[j]<x)
        {
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

int quick_sort(int A[],int p,int r)
{
    if(p<r)
    {
        int q=partitionn(A,p,r);
        quick_sort(A,p,q-1);
        quick_sort(A,q+1,r);
    }
}

int main()
{
    int i,j,m,n,ar[10000];
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>ar[i];
    }
    quick_sort(ar,0,n-1);
    for(i=0;i<n;i++)
    {
        cout<<ar[i]<< ' ';
    }
}
