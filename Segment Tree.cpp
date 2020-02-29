#include<bits/stdc++.h>
using namespace std;
typedef		long long       ll;
typedef		vector<ll>      vll;
#define		pb              push_back
#define		PB              pop_back
#define		nn              "\n"
#define		all(p)          p.begin(),p.end()
#define		zz(v)           (ll)v.size()
#define		mms(ar,a)       memset(ar,a,sizeof(ar))
#define		ss              ' '
#define 	S(a)            scanf("%lld",&a)
#define 	SS(a,b)         scanf("%lld %lld",&a,&b)
#define 	SSS(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c)
#define		gcd(a,b)        __gcd(a,b)
#define		lcm(a,b)        (a*b)/gcd(a,b)
#define		pi              acos(-1.0)
#define		OO              10000000000

ll ar[10000],tree[40000];

ll combine(ll l,ll r){
	return l<r?l:r;
}

void build(ll nd,ll st,ll ed){
    if(st==ed) tree[nd]=ar[st];
    else{
        ll mid=(st+ed)/2;
        build(2*nd,st,mid);
        build(2*nd+1,mid+1,ed);
        tree[nd]=combine(tree[2*nd],tree[2*nd+1]);
    }
}

void update(ll nd,ll st,ll ed,ll id,ll val){
    if(st==ed){
        ar[id]+=val;
        tree[nd]+=val;
    }
    else{
        ll mid=(st+ed)/2;
        if(st<=id and id<=mid) update(2*nd,st,ed,id,val);
        else update(2*nd+1,mid+1,ed,id,val);
    }
    tree[nd]=combine(tree[2*nd],tree[2*nd+1]);
}

ll query(ll nd,ll st,ll ed,ll l,ll r){
    if(r<st or ed<l) return OO;
    if(l<=st and ed<=r) return tree[nd];
    ll mid=(st+ed)/2;
    ll p1=query(2*nd,st,mid,l,r);
    ll p2=query(2*nd+1,mid+1,ed,l,r);
    return combine(p1,p2);
}

int main(){
//    freopen("input.txt","r",stdin);
    ll a,b,c=0,i,j,t,k,lie,m,n,o,x,y,z;
    S(n);
    for(i=1;i<=n;i++){
        S(ar[i]);
    }
    build(1,1,n);
    cout<<query(1,1,n,3,5);

    return 0;
}
