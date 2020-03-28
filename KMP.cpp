#include<bits/stdc++.h>
using namespace std;
typedef		long long       ll;
typedef		vector<ll>      vll;
#define		pb              push_back
#define		PB              pop_back
#define		nn              "\n"
#define		all(p)          p.begin(),p.end()
#define		zz(v)           (ll)v.size()
#define		mms(ar,a)       memset(ar,a,sizeof(ar))
#define		ss              ' '
#define 	S(a)            scanf("%lld",&a)
#define 	SS(a,b)         scanf("%lld %lld",&a,&b)
#define 	SSS(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c)
#define		gcd(a,b)        __gcd(a,b)
#define		lcm(a,b)        (a*b)/gcd(a,b)
#define		pi              acos(-1.0)
#define		OO              10000000000

vll prefix_function(string s){
    ll n=zz(s);
    vll pf(n);
    for(ll i=1;i<n;i++){
        ll j=pf[i-1];
        while(j>0 && s[i]!=s[j]) j=pf[j-1];
        if(s[i]==s[j]) j++;
        pf[i]=j;
    }
    return pf;
}

int main(){
//    freopen("input.txt","r",stdin);
    ll a,b,c=0,i,j,t,k,lie,m,n,o,x=0,y=0,mx=0,z,ar[200010];
    string tx,pt;
    cin>>tx>>pt;
    vll lps;
    lps=prefix_function(pt);
//    for(i=0;i<zz(lps);i++) cout<<lps[i]<<ss;
    i=0;
    j=0;
    while(i<zz(tx)){
        if(pt[j]==tx[i]){
            i++;
            j++;
        }
        if(j==zz(pt)){
            printf("Found pattern at index %lld\n",i-j);
            j=lps[j-1];
        }
        else if(i<zz(tx) && pt[j]!=tx[i]){
            if(j!=0) j=lps[j-1];
            else i++;
        }
    }

    return 0;
}
