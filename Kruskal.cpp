#include<bits/stdc++.h>
using namespace std;

struct edge{
    int a,b,w;
};
edge ar[100010];
int par[10010];

int Find(int a){
    if(par[a]==-1) return a;
    return par[a]=Find(par[a]);
}

void Union(int a,int b){
    par[a]=b;
}

bool cmp(edge a,edge b){
    return a.w<b.w;
}

int main(){
    int i,j,a,b,n,m,sm=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) par[i]=-1;
    for(i=0;i<m;i++){
        scanf("%d %d %d",&ar[i].a,&ar[i].b,&ar[i].w);
    }
    sort(ar,ar+m,cmp);
    for(i=0;i<m;i++){
        a=Find(ar[i].a);
        b=Find(ar[i].b);
        if(a!=b){
            sm+=ar[i].w;
            Union(a,b);
        }
    }
    printf("%d\n",sm);

    return 0;
}
