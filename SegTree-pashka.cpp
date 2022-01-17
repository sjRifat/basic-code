#include<bits/stdc++.h>
using namespace std;
#define int long long

struct segtree{
    int sz=1;
    vector<int>tree;
    void init(int n){
        while(sz<n) sz+=sz;
        tree.assign(sz*2,INT_MAX);
    }

    int combine(int l,int r){
        return l+r;
    }

    void build(vector<int>&v,int x,int l,int r){
        if(r-l==1){
            if(l<(int)v.size()) tree[x]=v[l];
            return;
        }
        int m=(l+r)/2;
        build(v,x*2+1,l,m);
        build(v,x*2+2,m,r);
        tree[x]=combine(tree[x*2+1],tree[x*2+2]);
    }
    void build(vector<int>&v){
        build(v,0,0,sz);
    }

    void update(int i,int v,int x,int l,int r){
        if(r-l==1){
            tree[x]=v;
            return;
        }
        int m=(l+r)/2;
        if(i<m) update(i,v,2*x+1,l,m);
        else update(i,v,2*x+2,m,r);
        tree[x]=combine(tree[x*2+1],tree[x*2+2]);
    }
    void update(int i,int v){
        update(i,v,0,0,sz);
    }

    int query(int l,int r,int x,int lt,int rt){
        if(r<=lt or l>=rt) return 0;
        if(l<=lt and r>=rt) return tree[x];
        int m=(lt+rt)/2;
        return combine(query(l,r,2*x+1,lt,m),query(l,r,2*x+2,m,rt));
    }
    int query(int l,int r){
        return query(l,r,0,0,sz);
    }
}sg;

int32_t main(){
    int i,j,n,m;
    cin>>n>>m;
    vector<int>v;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    sg.init(n);
    sg.build(v);
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int val;
            cin>>i>>val;
            sg.update(i,val);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<sg.query(l,r)<<endl;
        }
    }

    return 0;
}
