#include<bits/stdc++.h>
using namespace std;
#define		pb              push_back
#define		PB              pop_back
#define		nn              "\n"
#define		all(p)          p.begin(),p.end()
#define		zz(v)           (ll)v.size()
#define		ss              ' '
#define 	S(a)            scanf("%lld",&a)
#define 	SS(a,b)         scanf("%lld %lld",&a,&b)
#define 	SSS(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c)
#define		gcd(a,b)        __gcd(a,b)
#define		lcm(a,b)        (a*b)/gcd(a,b)
#define		pi              acos(-1.0)
typedef		long long       ll;
typedef		vector<ll>      vll;

ll fx[]={ 1, -1,  0,  0};   // 4 direction
ll fy[]={ 0,  0,  1, -1};  // 4 direction
//ll fx[]={ 0,  0,  1, -1, -1,  1, -1,  1};  // King's Move / 8 direction
//ll fy[]={-1,  1,  0,  0,  1,  1, -1, -1}; // King's Move / 8 direction
//ll fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knight's Move
//ll fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knight's Move
ll row,column,cnt;
char ch[22][22];

void flood_fill(ll i,ll j){
    if(i<0 || j<0 || i>row-1 || j>column-1) return;
    if(ch[i][j]=='.'){
        ch[i][j]='*';
        cnt++;
        for(ll k=0;k<4;k++){
            ll x=i+fx[k];
            ll y=j+fy[k];
            flood_fill(x,y);
        }
    }
}

int main()
{
    ll i,j,b,c=0,t,a,p;
    S(t);
    while(t--){
        cnt=0;
        p=0;
        SS(a,b);
        row=b;
        column=a;
        getchar();
        for(i=0;i<row;i++){
            for(j=0;j<column;j++) scanf(" %c",&ch[i][j]);
        }
        for(i=0;i<row;i++){
            for(j=0;j<column;j++){
                if(ch[i][j]=='@'){ // start from "@" sign, find all "." sign;
                    ch[i][j]='.';
                    flood_fill(i,j);
                    p=1;
                    break;
                }
            }
            if(p==1) break;
        }
        printf("Case %lld: %lld\n",++c,cnt);
    }

    return 0;
}
