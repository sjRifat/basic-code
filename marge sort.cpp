#include<bits/stdc++.h>
using namespace std;

int Marge(int A[],int f,int m,int l)
{
    int b[l];
    int i=f;
    int j=m+1;
    int k=f;
    while(i<=m && j<=l){
        if(A[i]<A[j])
            b[k++]=A[i++];
        else
            b[k++]=A[j++];
//        k++;
    }
    if(i>m){
        for(int h=j; h<=l; h++)
            b[k++]=A[h];
    }
    else{
        for(int h=i; h<=m; h++)
            b[k++]=A[h];
    }
    for(int h=f;h<k;h++)
        A[h]=b[h];
//    return T[];
}

int marge_sort(int A[],int f,int l){
    if(f<l){
        int m=(f+l)/2;
        marge_sort(A, f, m);
        marge_sort( A, m+1, l);
        Marge( A, f, m, l);
    }
}

int main()
{
    int i,j,m,n,ar[10000];
    cin>>n;
    for(i=0; i<n; i++)
        cin>>ar[i];
    marge_sort(ar,0,n-1);
    for(i=0;i<n;i++)
        cout<<ar[i]<<' ';
}
