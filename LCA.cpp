#include<bits/stdc++.h>
using namespace std;
typedef	    long long       ll;
typedef	    vector<ll>      vll;
#define	    ss              ' '
#define	    nn              "\n"
#define	    PB              pop_back
#define     pb              push_back
#define	    pi              acos(-1.0)
#define	    gcd(a,b)        __gcd(a,b)
#define	    OO              1000000007
#define	    NN              printf("\n")
#define	    zz(v)           (ll)v.size()
#define	    lcm(a,b)        (a*b)/gcd(a,b)
#define     no              printf("NO\n")
#define     mo              printf("-1\n")
#define     yes             printf("YES\n")
#define     S(a)            scanf("%lld",&a)
#define	    all(p)          p.begin(),p.end()
#define     P(a)            printf("%lld\n",a)
#define     db              printf("be steady\n")
#define	    mms(ar,a)       memset(ar,a,sizeof(ar))
#define     SS(a,b)         scanf("%lld %lld",&a,&b)
#define     PP(a,b)         printf("%lld %lld\n",a,b)
#define     SSS(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c)

vll v[300010];
ll lca[300010][20];
ll level[300010];

void dfs(ll node,ll lvl,ll par){
    level[node]=lvl;
    lca[node][0]=par;
    for(ll child:v[node]){
        if(child!=par){
            dfs(child,lvl+1,node);
        }
    }
}

void init(ll n){
    dfs(1,0,-1);
    for(ll i=1;i<=19;i++){
        for(ll j=1;j<=n;j++){
            if(lca[j][i-1]!=-1){
                ll par=lca[j][i-1];
                lca[j][i]=lca[par][i-1];
            }
        }
    }
}
ll get_lca(ll a,ll b){
    if(level[b]<level[a]) swap(a,b);
    ll d=level[b]-level[a];
    while(d>0){
        ll i=log2(d);
        b=lca[b][i];
        d-=(1LL<<i);
    }
    if(a==b) return a;
    for(ll i=19;i>=0;i--){
        if(lca[a][i]!=-1 and (lca[a][i])!=lca[b][i]){
            a=lca[a][i];
            b=lca[b][i];
        }
    }
    return lca[a][0];
}

int main()
{
//    freopen("input.txt","r",stdin);
    ll a,b,c,s,d,i,j,t,k,n,q;
    scanf("%lld",&n);
    mms(lca,-1);
    for(i=1;i<n;i++){
        SS(a,b);
        v[a].pb(b);
        v[b].pb(a);
    }
    init(n);
    S(q);
    while(q--){
        SS(a,b);
        P(get_lca(a,b));
    }

    return 0;
}

/*
7
1 4
4 5
4 2
4 3
3 7
3 6
1
5 2
*/
