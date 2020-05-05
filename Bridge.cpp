#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>vp;
vector<int>v[707];
int in[707],low[707],vis[707],timer;

void dfs(int node,int par){
    vis[node]=1;
    in[node]=low[node]=timer;
    timer++;

    for(int child:v[node]){
        if(child==par) continue;
        if(vis[child]==1){
            low[node]=min(low[node],in[child]);
        }
        else{
            dfs(child,node);
            if(low[child]>in[node]){
                vp.push_back(make_pair((min(node,child)),(max(node,child))));
            }
            low[node]=min(low[node],low[child]);
        }
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    int a,b,c=0,i,j,t,k,lie,m,n,o,x=0,y,z;
    scanf("%d",&t);
    while(t--){
        for(i=0;i<707;i++){
            v[i].clear();
            in[i]=0;
            low[i]=0;
            vis[i]=0;
        }
        vp.clear();
        timer=0;
        scanf("%d %d",&n,&m);
        while(m--){
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1,-1);
        sort(vp.begin(),vp.end());
        if(vp.size()==0) printf("Caso #%d\nNo Bridge\n",++c);
        else{
            printf("Caso #%d\n%d\n",++c,(int)vp.size());
            for(i=0;i<(int)vp.size();i++) printf("%d %d\n",vp[i].first,vp[i].second);
        }
    }

    return 0;
}
