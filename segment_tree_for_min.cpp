#include <bits/stdc++.h>
using namespace std;
#define ll long long


// ------------------------------------------------------------------------------------------------------------


struct segtree{

    ll size=1;
    vector<ll> mins;

    segtree() {}

    segtree(ll n) {
        init(n);
    }

    void init(ll n){
        while(size<n) size*=2;
        mins.assign(2*size,INT_MAX);
    }
 
    void set(ll ind, ll val, ll tind, ll lx, ll rx){
        if((rx-lx)==1) {mins[tind]=val;return;}
        ll mid=(lx+rx)/2;
        if(ind<mid) set(ind,val,2*tind+1,lx,mid);
        else set(ind,val,2*tind+2,mid,rx);
        mins[tind]=min(mins[2*tind+1],mins[2*tind+2]);
    }
 
    void set(ll ind, ll val){
        set(ind,val,0,0,size);
    }
 
    ll findmin(ll tind, ll l, ll r, ll lx, ll rx){
        if(rx<=l || lx>=r) return INT_MAX;
        if(l<=lx && rx<=r) return mins[tind];
        ll mid=(lx+rx)/2;
        return min(findmin(2*tind+1,l,r,lx,mid),findmin(2*tind+2,l,r,mid,rx));
    }
 
    ll findmin(ll l, ll r){
        return findmin(0,l,r,0,size);
    }
 
 
 
    void build(vector<ll> &v){
        for(int i=size-1,j=0;j<v.size();i++,j++){
            mins[i]=v[j];
        }
        for(int i=size-2;i>=0;i--){
            mins[i]=min(mins[2*i+1],mins[2*i+2]);
        }
    }
 
    void display(){
        for(auto x: mins){
            cout<<x<<" ";
        }
        cout<<endl;
    }
};



// ------------------------------------------------------------------------------------------


void solve() {
    int n;
    cin>>n;

    segtree tree;
    tree.init(n);


    // this can be done this way too 

    // segtree tree(n);
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
