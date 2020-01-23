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

vll G[20020],cost[20020];
ll inf=1000000000,dt[20020];

struct data{
    ll city,dist;
    bool operator<(const data& p) const{
        return dist>p.dist;
    }
};
//bool operator<(data a,data b) {return a.dist>b.dist;}

ll dijkstra(ll source,ll destination){
    data u,v;
    priority_queue<data>pq;
    u.city=source;
    u.dist=0;
    pq.push(u);
    dt[source]=0;

    while(!pq.empty()){
    u=pq.top();
    pq.pop();
        for(ll i=0;i<zz(G[u.city]);i++){
            v.city=G[u.city][i];
            v.dist=cost[u.city][i]+dt[u.city];
            if(dt[v.city]>v.dist){
                dt[v.city]=v.dist;
                pq.push(v);
            }
        }
    }
    return dt[destination];
}

int main(){
//    freopen("input.txt","r",stdin);
    ll c,a,b,i,j,t,k,lie,m,n,o,x,y,z=0,ar[200010];
    S(t);
    while(t--){
        for(i=0;i<20020;i++){
        dt[i]=inf;
        G[i].clear();
        cost[i].clear();
    }
        ll nd,ed,st,dt;
        SS(nd,ed);
        SS(st,dt);
        for(i=0;i<ed;i++){
            SSS(a,b,c);
            G[a].pb(b);
            G[b].pb(a);

            cost[a].pb(c);
            cost[b].pb(c);
        }
        x=dijkstra(st,dt);
        if(x==inf) printf("Case #%lld: unreachable\n",++z);
        else printf("Case #%lld: %lld\n",++z,x);
    }

    return 0;
}
