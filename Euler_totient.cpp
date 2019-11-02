//for n

ll totient(ll n){
    ll s=n;
    for(ll i=2;i<=n/i;i++){
        if(n%i==0){
            while(n%i==0) n/=i;
            s-=s/i;
        }
    }
    if(n>1) s-=s/n;
    return s;
}
////////////////////
//for 1-n

ll ar[200010];
void totient(){
    ll n=200000;
    for(ll i=1;i<=n;i++) ar[i]=i;
    for(ll i=2;i<=n;i++){
        if(ar[i]==i){
            ar[i]=i-1;
            for(ll j=i*2;j<=n;j+=i) ar[j]=(ar[j]/i)*(i-1);
        }
    }
}
