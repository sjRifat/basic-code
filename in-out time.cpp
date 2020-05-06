#include<bits/stdc++.h>
using namespace std;

vector<int>v[10010];
int vis[10010],in[10010],out[10010],timer=1;

void dfs(int node){
    vis[node]=1;
    in[node]=timer++;
    for(int child:v[node]){
        if(!vis[child]) dfs(child);
    }
    out[node]=timer++;
}

int main(){
    int i,j,m,n,a,b;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    for(i=1;i<=n;i++) 
        printf("for %d -- in -> %d ,, out -> %d\n",i,in[i],out[i]);

    return 0;
}
