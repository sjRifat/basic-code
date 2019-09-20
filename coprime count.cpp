#include<bits/stdc++.h>
using namespace std;
#define     pb              push_back
#define     PB              pop_back
#define     nn              "\n"
#define     all(p)          p.begin(),p.end()
#define     zz(v)           (ll)v.size()
#define     se              ' '
#define     S(a)            scanf("%lld",&a)
#define     SS(a,b)         scanf("%lld %lld",&a,&b)
#define     SSS(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c)
#define     gcd(a,b)        __gcd(a,b)
#define     lcm(a,b)        (a*b)/gcd(a,b)
#define     pi              acos(-1.0)
typedef     long long       ll;
typedef     vector<ll>      vll;

bool ar[2250];
vll vs,v;
void sieve(){
    ll n=2250;
    ll i,j;
    vs.pb(2LL);
    for(i=3LL;i<=n;i+=2LL){
        if(ar[i]==0){
            vs.pb(i);
            if(i>n/i) continue;
            for(j=i*i;j<=n;j+=(i+i)) ar[j]=1;
        }
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    ll a,b,c,i,j,t,k=0,lie,n,o,p=0,x,y,z;
    sieve();
    double s=0,m;
    v.pb(0LL);
    S(x);
    m=x;
    for(j=0;vs[j]<=sqrt(x);j++){
        z=x;
        while(x%vs[j]==0){
            x/=vs[j];
        }
        if(x!=z) m*=(1.0-1.0/(double)vs[j]);
    }
    if(x!=1) m*=(1.0-1.0/(double)x);
    cout<<(ll)m<<nn;

    return 0;
}
