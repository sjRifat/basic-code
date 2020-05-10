#include<bits/stdc++.h>
using namespace std;

vector<int>v[1111];
vector<int>ans;
int in[1111];

void Kahn(int n){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(in[i]==0) q.push(i);
    }
    while(!q.empty()){
        int cur=q.front();
        ans.push_back(cur);
        q.pop();
        for(int node : v[cur]){
            in[node]--;
            if(!in[node]) q.push(node);
        }
    }
}

int main()
{
    int n,t,i,j,m,a,b;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        in[b]++;
    }
    Kahn(n);
    for(i : ans) printf("%d ",i);

    return 0;
}
