#include<bits/stdc++.h>
using namespace std;
vector<int>G[100];
int w[100][100];
int dist[100];
int n,m;
void zero()
{
    int i,j;
    for(i=0;i<=n+2;i++)
    {
        dist[i] = 999999;
        G[i].clear();
        for(j=0;j<=n+2;j++)
        {
            w[i][j] = 0;
        }
    }
}



void dikjstra(int u,int des)
{
    //printf("u = %d \n",u);
    dist[u] = 0;
    int i;
    priority_queue< pair<int, int> >pq;
    pq.push({-0,-u});
    while(!pq.empty())
    {
        u = -pq.top().second;
        int wu = -pq.top().first;
        printf("u = %d  wu = %d\n",u,wu);
        pq.pop();
        for(int i = 0; i < (int)G[u].size(); ++i)
        {
            int v = G[u][i];
            int wv = w[u][v];
             printf("v = %d wv = %d\n",v,wv);
            if(wu+wv<dist[v])
            {
                dist[v] = wu+wv;
                pq.push({-dist[v],-v});
            }
        }
    }
}


int main()
{
    int a,b,i,j,c,x,y;

    scanf("%d %d",&n,&m);
    zero();

    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        G[a].push_back(b);
        w[a][b] = c;

    }
    printf("\n\n");
    dikjstra(1,3);

    printf("Cost %d\n",dist[3]);

    return 0;
}
/*
7 7
1 2 1
2 5 2
5 6 3
6 3 4
1 3 100
1 4 5
4 7 6
*/






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

vll g[100];
ll w[100][100],dist[100],node,edge;
void zero(){
    ll i,j;
    for(i=0;i<node+3;i++){
        dist[i]=9999999;
        g[i].clear();
        for(j=0;j<node+3;j++) w[i][j]=0;
    }
}

void dijkastra(ll u){
    dist[u]=0;
    ll i,j;
    priority_queue<pair<ll,ll>>pq;
    pq.push({-0,-u});
    while(!pq.empty()){
        u=-pq.top().second;
        ll wu=-pq.top().first;

        printf("u = %lld -- wu = %lld\n",u,wu);
        pq.pop();

        for(i=0;i<zz(g[u]);i++){
            ll v=g[u][i];
            ll wv=w[u][v];
            printf("v = %lld -- wv = %lld\n",v,wv);

            if(wu+wv<dist[v]){
                dist[v]=wu+wv;
                pq.push({-dist[v],-v});
            }
        }
    }
}


int main()
{
    freopen("input.txt","r",stdin);
    ll a,b,c,cc=0,d,sm=0,i,j,t,k,lie,m,n,o,x,y,z,zz;
//    S(t);
//    while(t--){
        zero();
        SS(node,edge);
        for(i=1;i<=edge;i++){
            SSS(a,b,c);
            g[a].pb(b);
//            v[b].pb(a);
            w[a][b]=c;
//            cost[a].pb(c);
//            cost[b].pb(c);
        }
        dijkastra(1);
        printf("cost is -> %lld\n",dist[3]);


//        if(plg==0) printf("Case #%lld: unreachable\n",++cc);
//        else printf("Case #%lld: %lld\n",++cc,level[finish]);
//    }

    return 0;
}

