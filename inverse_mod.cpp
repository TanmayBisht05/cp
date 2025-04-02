#include <bits/stdc++.h>
using namespace std;
#define ll long long


// -------------------------------------------------------------------------


ll binexp(ll a, ll b, ll mod){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}


ll inv_mod(ll a, ll mod ){
    return binexp(a,mod-2,mod);
}



// ----------------------------------------------------------------------------







void solve() {
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
return 0;
}