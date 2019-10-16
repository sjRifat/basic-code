ll big_mod(ll b,ll p,ll m){
    if(p==0) return 1;
    if(p%2==0){
        ll s=big_mod(b,p/2,m);
        return ((s%m)*(s%m))%m;
    }
    return ((b%m)*(big_mod(b,p-1,m)%m))%m;
}

ll mod_inv(ll b,ll m){
    return big_mod(b,m-2,m);
}
