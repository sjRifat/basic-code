#include<bits/stdc++.h>
using namespace std;
#define   	pb 			    push_back
#define   	nn 			    "\n"
#define   	ss 			    ' '
typedef 	long long 		ll;
typedef 	vector<ll>		vll;

int main()
{
    ll a,b,c=0,i,j,k,m,n,s=0,o,x,y,z;
    cin>>n;
    for(i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            c=0;
            while(n%i==0)
            {
                n/=i;
                c++;
            }
            cout<<i<<'^'<<c<<ss;
        }
    }
    return 0;
}


/////////////////////////////and another formation/////////////////////////////


#include<bits/stdc++.h>
using namespace std;
#define   	pb 			    push_back
#define   	nn 			    "\n"
#define   	ss 			    ' '
typedef 	long long 		ll;
typedef 	vector<ll>		vll;

int main()
{
    ll a,b,c=0,i,j,k,m,n,s=0,o,x,y,z;
    vll v;
    cin>>n;
    for(i=2; i<=n; i++)
    {
        if(n%i==0)
        {
            c=0;
            while(n%i==0)
            {
                n/=i;
                c++;
            }
//            cout<<i<<'^'<<c<<ss;
            v.pb(i);
            v.pb(c);
        }
    }
    for(i=0;i<v.size()-2;i++)
    {
        if(i%2==0)
            cout<<v[i]<<'^';
        else cout<<v[i]<<'*';
    }
    cout<<v[v.size()-2]<<'^'<<v[v.size()-1];
    return 0;
}
