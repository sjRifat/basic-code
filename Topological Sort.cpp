#include<bits/stdc++.h>
using namespace std;
#define		pb              push_back
#define		PB              pop_back
#define		nn              "\n"
#define		all(p)          p.begin(),p.end()
#define		zz(v)           (ll)v.size()
#define		se              ' '
#define 	S(a)            scanf("%lld",&a)
#define 	SS(a,b)         scanf("%lld %lld",&a,&b)
#define 	SSS(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c)
#define		gcd(a,b)        __gcd(a,b)
#define		lcm(a,b)        (a*b)/gcd(a,b)
#define		pi              acos(-1.0)
typedef		long long       ll;
typedef		vector<ll>      vll;

vll v[111];
bool visited[111];
stack<ll>ts;

void dfs(ll u){
    visited[u]=true;
    for(ll i=0;i<zz(v[u]);i++){
        if(!visited[v[u][i]]) dfs(v[u][i]);
    }
    ts.push(u);
}

int main(){
//    freopen("input.txt","r",stdin);
    ll a,b,c,i,j,t,vrtx,edg,k,lie,m,n,o,x,y,z,ar[200010];
    while(SS(edg,vrtx) && vrtx||edg){
        while(vrtx--){
            SS(a,b);
            v[a].pb(b);
        }
        memset(visited,0,sizeof(visited));
        for(i=1;i<=edg;i++){
            if(!visited[i]) dfs(i);
        }
        while(!ts.empty()){
            if(zz(ts)==1) printf("%lld\n",ts.top());
            else printf("%lld ",ts.top());
            ts.pop();
        }
        for(i=0;i<111;i++) v[i].clear();
    }

    return 0;
}
