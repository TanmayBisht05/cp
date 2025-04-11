#include <bits/stdc++.h>
using namespace std;
#define ll long long


// ----------------------------------------------------------------------------


struct segtree{

    ll size=1;
    vector<ll> sums;    

    void init(ll n){
        while(size<n) size*=2;
        sums.assign(2*size,0);
    }
 
    void set(ll ind, ll val, ll tind, ll lx, ll rx){
        if((rx-lx)==1) {sums[tind]=val;return;}
        ll mid=(lx+rx)/2;
        if(ind<mid) set(ind,val,2*tind+1,lx,mid);
        else set(ind,val,2*tind+2,mid,rx);
        sums[tind]=sums[2*tind+1]+sums[2*tind+2];
    }
 
    void set(ll ind, ll val){
        set(ind,val,0,0,size);
    }
 
    ll findsum(ll tind, ll l, ll r, ll lx, ll rx){
        if(rx<=l || lx>=r) return 0;
        if(l<=lx && rx<=r) return sums[tind];
        ll mid=(lx+rx)/2;
        return findsum(2*tind+1,l,r,lx,mid)+findsum(2*tind+2,l,r,mid,rx);
    }
 
    ll findsum(ll l, ll r){
        return findsum(0,l,r,0,size);
    }
 
 
 
    void build(vector<ll> &v){
        for(int i=size-1,j=0;j<v.size();i++,j++){
            sums[i]=v[j];
        }
        for(int i=size-2;i>=0;i--){
            sums[i]=sums[2*i+1]+sums[2*i+2];
        }
    }
 
    void display(){
        for(auto x: sums){
            cout<<x<<" ";
        }
        cout<<endl;
    }
};


// -----------------------------------------------------------------------------------------


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