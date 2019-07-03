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
