#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
#define base 26
#define MOD 1000000007
#define ll long long

ll pH[MAX+5], po[MAX+5];
void preprocess(string &s){
    pH[0]=s[0]-'a'+1;
    po[0]=1;
    for(int i=1;i<(int)s.size();i++){
        pH[i]=((pH[i-1]*base)+(s[i]-'a'+1))%MOD;
        po[i]=po[i-1]*base%MOD;
    }
}

ll getHash(int L,int R){
    if(!L) return pH[R];
    return ((pH[R]-(pH[L-1]*po[R-L+1])%MOD)+MOD)%MOD;
}


int main(){
    string s;
    ll n,q;
    cin >> s;
    preprocess(s);
//    for(int i=0;i<s.size();i++)
//        cout<<pH[i]<<" ";
    cin>>q;
    while(q--){
        ll a,b;
        cin>>a>>b;
        cout<<getHash(a,b)<<endl;
    }

    return 0;
}
