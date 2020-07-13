#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ar[100010];
vector<ll> v;
void sieve(){
    ll i,j,n=100010;
    v.push_back(2LL);
    for(i=3;i<=n;i+=2){
        if(ar[i]==0){
            v.push_back(i);
            if(i>n/i) continue;
            for(j=i*i;j<=n;j+=(i+i)) ar[j]=1;
        }
    }
}

int main(){
    ll i,j,m=1,n;
    sieve();
    scanf("%lld",&n);
    for(i=0;v[i]*v[i]<=n;i++){
        if(n%v[i]==0){
            ll c=0;
            while(n%v[i]==0){
                n/=v[i];
                c++;
            }
            m*=(c+1);
            printf("%lld^%lld ",v[i],c);
        }
    }
    if(n!=1) printf("%lld^1\n",n),m*=2;
    else printf("\n");
    printf("number of divisor -> %lld\n",m);


    return 0;
}
