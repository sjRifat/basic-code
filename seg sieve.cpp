#include<bits/stdc++.h>
using namespace std;
#define		pb              push_back
#define		PB              pop_back
#define		nn              "\n"
#define		all(p)          p.begin(),p.end()
#define		zz(v)           (ll)v.size()
#define		sp              ' '
#define 	S(a)            scanf("%lld",&a)
#define 	SS(a,b)         scanf("%lld %lld",&a,&b)
#define 	SSS(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c)
#define		gcd(a,b)        __gcd(a,b)
#define		lcm(a,b)        (a*b)/gcd(a,b)
#define		pi              acos(-1.0)
typedef		long long       ll;
typedef		vector<ll>      vll;

vll v;
bool ar[1000010];

void sieve(){
    ll i,j,n=1000010;
    v.pb(2LL);
    for(i=3;i<=n;i+=2){
        if(ar[i]==0){
            v.pb(i);
            if(i>n/i) continue;
            for(j=i*i;j<=n;j+=(i+i)) ar[j]=1;
        }
    }
}

void segmented_sieve(ll L,ll R)
{
    ll c=0;
    bool isPrime[R-L+1];
    for(ll i=0;i<=R-L+1;i++)
        isPrime[i]=true;
    if(L==1)
        isPrime[0]=false;
    for(ll i=0;v[i]*v[i]<=R;i++){
        ll curPrime=v[i];
        ll base=curPrime*curPrime;
        if(base<L)
            base=((L+curPrime-1)/curPrime)*curPrime;
        for(ll j=base;j<=R;j+=curPrime)
            isPrime[j-L]=false;
    }
    for(ll i=0;i<=R-L;i++){
        if(isPrime[i]==true)
            c++;;
    }
    printf("%lld\n",c);
}

int main()
{
    sieve();
    ll l,r,t,c=0;
    S(t);
    while(t--){
        SS(l,r);
        printf("Case %lld: ",++c);
        segmented_sieve(l,r);
    }

    return 0;
}
