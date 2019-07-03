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

int main()
{
    ll a,b,c=0,i,j,t,k,m,n,o,x,y,z;
    vector<pair<int,pair<int,int>>>v;
    for(i=99;i>=1;i-=3){
        v.pb(make_pair(i,make_pair(i+1,i+2)));
    }
    for(i=0;i<zz(v);i++){
        cout<<v[i].first<<'\t'<<v[i].second.first<<'\t'<<v[i].second.second<<nn;
    }

    return 0;
}
