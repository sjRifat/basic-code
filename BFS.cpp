#include<bits/stdc++.h>
using namespace std;
#define		pb              push_back
#define		PB              pop_back
#define		nn              "\n"
#define		all(p)          p.begin(),p.end()
#define		zz(v)           v.size()
#define		ss              ' '
#define 	S(a)            scanf("%lld",&a)
#define 	SS(a,b)         scanf("%lld %lld",&a,&b)
#define 	SSS(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c)
#define		gcd(a,b)        __gcd(a,b)
#define		lcm(a,b)        (a*b)/gcd(a,b)
#define		pi              acos(-1.0)
typedef		long long       ll;
typedef		vector<ll>      vll;

vll v[10];
ll visited[10];
ll level[10];

void bfs(ll u){
    visited[u]=1;
    level[u]=0;
    queue<ll>q;
    q.push(u);

    while(!q.empty()){
        u=q.front();
        visited[u]=1;
        printf("pop -> %lld\n",u);
        q.pop();
        visited[u]=1;

        for(ll i=0;i<zz(v[u]);i++){
            ll p=v[u][i];
            if(!visited[p]){
                printf("pushing -> %lld\n",p);
                visited[p]=1;
                level[p]=level[u]+1;
                q.push(p);
            }
        }
    }

}

int main()
{
    ll a,b,c,i,j,t,k,node,edge;
    SS(node,edge);
    for(i=1;i<=edge;i++){
        SS(a,b);
        v[a].pb(b);
        v[b].pb(a);
    }
    printf("\n");
    for(i=1;i<=edge;i++){
        printf("node %lld connected with ->",i);
        for(j=0;j<zz(v[i]);j++)
            printf(" %lld",v[i][j]);
        printf("\n");
    }
    printf("\n");
    bfs(1);

    printf("\n");
    for(i=1;i<node;i++)
        printf("the level of %lld nide is %lld\n",i,level[i]);

    return 0;
}


/*
9 10
1 2
1 3
1 4
1 5
1 6
1 9
2 6
3 7
4 8
5 9


7 7
1 2
1 3
1 4
2 5
3 6
5 6
4 7
*/
