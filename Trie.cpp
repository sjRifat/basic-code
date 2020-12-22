#include<bits/stdc++.h>
using namespace std;

struct node{
    bool endmark;
    node *next[27];
    node(){
        endmark=false;
        for(int i=0;i<26;i++) next[i]=NULL;
    }
} *root;

void Insert(string s,int n){
    node *cur=root;
    for(int i=0;i<n;i++){
        int id=s[i]-'a';
        if(cur->next[id]==NULL) cur->next[id]=new node();
        cur=cur->next[id];
    }
    cur->endmark=true;
}

bool Search(string s,int n){
    node *cur=root;
    for(int i=0;i<n;i++){
        int id=s[i]-'a';
        if(cur->next[id]==NULL) return false;
        cur=cur->next[id];
    }
    return cur->endmark;
}

void Delete(node *cur){
    for(int i=0;i<26;i++){
        if(cur->next[i]) Delete(cur->next[i]);
    }
    delete(cur);
}

int main(){
    root=new node();
    int n,i,q;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        Insert(s,(int)s.size());
    }
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        if(Search(s,(int)s.size())) puts("found");
        else puts("not found");
    }
    Delete(root);

    return 0;
}
