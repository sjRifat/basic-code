#include<bits/stdc++.h>
using namespace std;
int parent[1111],Rank[1111];

///path compression
//int find_par(a){
//    vector<int>v;
//    while(parent[a]>0){
//        v.push_back(a);
//        a=parent[a];
//    }
//    for(int i=0;i<(int)v.size();i++){
//        parent[v[i]]=a;
//    }
//    return a;
//}
int find_par(int a){
    if(parent[a]<0) return a;
//    int x=find_par(parent[a]);
//    parent[a]=x;
//    return x;
    return parent[a]=find_par(parent[a]);
}

///union by rank
void marge(int a,int b){
    a=find_par(a);
    b=find_par(b);
    if(a==b) return;
    if(Rank[a]>=Rank[b]){
        /// a will be parent;
        parent[b]=a;
        Rank[a]+=Rank[b];
        parent[a]-=Rank[b];
    }
    else{
        /// b will be parent
        parent[a]=b;
        Rank[b]+=Rank[a];
        parent[b]-=Rank[a];
    }
}

int main(){
    int a,b,i,j,m,n;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        parent[i]=-1;
        Rank[i]=1;
    }
    while(m--){
        scanf("%d %d",&a,&b);
        marge(a,b);
    }
    for(i=1;i<=n;i++){
        printf("for %d -> parent -> %d -- rank -> %d\n",i,parent[i],Rank[find_par(i)]);
    }

    return 0;
}

/*
6 3
1 2
2 3
4 5
for 1 -> parent -> -3 -- rank -> 3
for 2 -> parent -> 1 -- rank -> 3
for 3 -> parent -> 1 -- rank -> 3
for 4 -> parent -> -2 -- rank -> 2
for 5 -> parent -> 4 -- rank -> 2
for 6 -> parent -> -1 -- rank -> 1

number of negative parent = number of connected component
rank = size of connected component
the negative value of parent means it is parent of itself and it is the size of that connected component with absolute value.
*/
