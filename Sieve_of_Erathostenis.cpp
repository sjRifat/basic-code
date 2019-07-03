#include<bits/stdc++.h>
using namespace std;
#define		pb              push_back
#define		PB              pop_back
#define		nn              "\n"
#define		all(p)          p.begin(),p.end()
#define		zz(v)           v.size()
#define		ss              ' '
#define		gcd(a,b)        __gcd(a,b)
#define		lcm(a,b)        (a*b)/gcd(a,b)
#define		pi              acos(-1.0)
typedef		long long       ll;
typedef		vector<ll>      vll;


bool ar[1000010];
void sive(ll n){
    vll v;
    ll i,j;
    ll x=sqrt(n);
    ar[0]=ar[1]=1;
    for(i=4;i<=n;i+=2) ar[i]=1;
    for(i=3;i<=x;i+=2){
        if(ar[i]==0){
            for(j=i+i;j<=n;j+=i) ar[j]=1;
        }
    }
    for(i=0;i<=n;i++){
        if(ar[i]==0) v.pb(i);
    }
     for(i=0;i<zz(v);i++){
        cout<<v[i]<<ss;
    }
}

int main()
{
    ll a,b,c,i,j,t,k=1,m,n,o,p,x,y,z;
    cin>>n;
    sive(n);

    return 0;
}




************************************************************************


#include <stdio.h>
#include <string.h>
#include <math.h>


const int FLAG_SIZE = 1001000;
const int PRIME_SIZE = 80000;

bool flag[FLAG_SIZE];
int prime[PRIME_SIZE];

void sieve()
{
    int i,j,ind = 1,d;
    prime[ind++]=2;

    for(i=3;i<FLAG_SIZE;i+=2)
    {
        if(flag[i] == false)
        {
            prime[ind++]=i;

            if(i > FLAG_SIZE/i) ///cause i*i > FLAG_SIZE
                continue;

            for(j=i*i,d=i+i;j<=FLAG_SIZE;j+=d)
                flag[j]=true;
        }
    }
    for(i=1;i<=100;i++)
    {
        printf("%d\n",prime[i]);
    }
    printf("Number of Prime : %d\n",ind);
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    sieve();

    return 0;
}

