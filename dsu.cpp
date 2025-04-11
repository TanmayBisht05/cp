#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod =998244353;

struct DSU {
    vector<ll> parent,siz;

    DSU(){}

    DSU(ll n){
        init(n);
    }


    void init(ll n){
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        siz.assign(n,1);
    }


    ll findp(ll x){
        while(x!=parent[x]){
            x=parent[x]=parent[parent[x]];
        }
        return x;
    }


    bool same(ll x, ll y){
        return findp(x)==findp(y);
    }


    bool merge(ll x, ll y){
        x=findp(x);
        y=findp(y);

        if(x==y) return false;
        if(siz[x]<siz[y]) swap(x,y);
        siz[x]+=siz[y];
        parent[y]=x;
        return true;
    }

    ll size(ll x){
        return siz[findp(x)];
    }
};

void solve() {
    ll n;
    cin>>n;
    
    DSU dsu(n);
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