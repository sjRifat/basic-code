#include<bits/stdc++.h>
using namespace std;
int dis[100];
vector<int>G[100];
int cost[100][100];
int flag = 0;
int n,m;
void zero()
{
    for(int i=0; i<n+2; i++)
    {
        dis[i] = 999999;
    }
}
void Bellman_Ford(int s)
{
    int i,j,k,u,uc,v,uvc;
    dis[s] = 0;
    for(i = 0 ; i< n-1; i++)
    {
        for(j=0; j<n; j++)
        {
            for(k=0; k<G[j].size(); k++)
            {
                u = j;
                uc = dis[u];
                v = G[u][k];

                uvc = cost[u][v];

                if(uc+uvc<dis[v])
                {
                    dis[v] = uc+uvc;
                }
            }
        }
    }
    flag = 0;
    for(j=0; j<n; j++)
    {
        for(k=0; k<G[j].size(); k++)
        {
            u = j;
            uc = dis[u];
            v = G[u][k];

            uvc = cost[u][v];

            if(uc+uvc<dis[v])
            {
                flag = 1;
                break;
            }
        }
        if(flag==1)
            break;
    }
}

int main()
{

    int a,b,i,j,c,x,y;

    scanf("%d %d",&n,&m);
    zero();

    for(i=1; i<=m; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        G[a].push_back(b);
        cost[a][b] = c;

    }
    flag = 0;
    Bellman_Ford(1);
    if(flag == 1)
    {
        printf("negative cycle ditected\n");
    }
    else
        printf("\n\nCost %d\n",dis[3]);

    return 0;
}
