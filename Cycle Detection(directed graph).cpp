#include<bits/stdc++.h>
using namespace std;

vector<int>v[10010];
int visited[10010];

bool ans=true;
void dfs(int node)
{
   if(ans==false) return;
   visited[node]=1;
   for(int i=0;i<v[node].size();i++){
       if(visited[v[node][i]]==0) dfs(v[node][i]);
       else ans=false;
   }
    visited[node]=false;
}

int main(){
    int i,j,m,n,a,b;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        v[b].push_back(a);
    }
    for(int i=0;i<n;i++){
//        memset(visited,0,sizeof(visited));
        if(visited[i]==0 && v[i].size()>0) dfs(i);
    }
    if(!ans) printf("cycle found\n");
    else printf("cycle not found\n");

    return 0;
}
