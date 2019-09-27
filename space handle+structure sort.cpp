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

struct stdnt{
    int r;
    string s;
    int m;
};

bool cmp1(struct stdnt a,struct stdnt b){
    if(a.m!=b.m) return a.m>b.m;
    if(a.m==b.m && a.r!=b.r) return a.r<b.r;
}

int main()
{
//    freopen("input.txt","r",stdin);
    int a,b,c=0,i,j,n,r,t,k,m,o,x,y,z;
    struct stdnt st[101];
    S(n);
    for(i=0; i<n; i++)
        cin>>st[i].r>>st[i].s>>st[i].m;
    printf("Roll | Name       | Marks\n-------------------------\n");
    sort(st,st+n,cmp1);
    for(i=0; i<n; i++){
        printf("%4d",st[i].r);
        cout<<sp<<'|'<<sp<<std::left<<setfill(' ')<<setw(11)<<st[i].s<<'|'<<sp<<st[i].m<<nn;
    }

    return 0;
}

/*
4
1
a
90
5
bbsredf
80
120
cc
90
3
dddfnjhygf
800
*/
