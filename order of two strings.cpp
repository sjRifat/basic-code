/*
if tow strings are given,, 
are the characters of the 1st string maintain their order in the 2nd string........
*/

#include<bits/stdc++.h>
using namespace std;
#define		pb              push_back
#define		PB              pop_back
#define		nn              "\n"
#define		all(p)          p.begin(),p.end()
#define		zz(v)           v.size()
#define		ss              ' '
#define 	S(a)            scanf("%lld",&a)
#define 	SS(a,b)         scanf("%lld %lld",&a,&b)
#define 	SSS(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c)
#define		gcd(a,b)        __gcd(a,b)
#define		lcm(a,b)        (a*b)/gcd(a,b)
#define		pi              acos(-1.0)
typedef		long long       ll;
typedef		vector<ll>      vll;

int main()
{
    ll a,b,c,i,j,t,k,lie,m,n,o,p,x,y,z;
    c=0;
    x=0;
    string s1,s2;
    cin>>s1>>s2;
    for(i=0;i<s1.length();i++){
        for(j=x;j<s2.length();j++){
            if(s1[i]==s2[j]){
                c++;
                x=j+1;
                break;
            }
        }
    }
    if(c==s1.length()) cout<<"Yes"<<nn;
    else cout<<"No"<<nn;

    return 0;
}
