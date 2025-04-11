#include <bits/stdc++.h>
using namespace std;
#define ll long long

// ---------------------- MODINT ----------------------
template<int MOD>
struct ModInt {
    int val;

    ModInt(long long v = 0) {
        val = int(v % MOD);
        if (val < 0) val += MOD;
    }

    ModInt& operator+=(const ModInt& other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    ModInt& operator-=(const ModInt& other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    ModInt& operator*=(const ModInt& other) {
        val = int((1LL * val * other.val) % MOD);
        return *this;
    }

    ModInt& operator/=(const ModInt& other) {
        return *this *= other.inv();
    }

    ModInt operator-() const { return ModInt(-val); }

    ModInt inv() const {
        return power(*this, MOD - 2);
    }

    friend ModInt power(ModInt a, long long b) {
        ModInt res = 1;
        while (b > 0) {
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }

    friend ostream& operator<<(ostream& os, const ModInt& m) {
        return os << m.val;
    }

    friend istream& operator>>(istream& is, ModInt& m) {
        long long x;
        is >> x;
        m = ModInt(x);
        return is;
    }

    friend ModInt operator+(ModInt a, const ModInt& b) { return a += b; }
    friend ModInt operator-(ModInt a, const ModInt& b) { return a -= b; }
    friend ModInt operator*(ModInt a, const ModInt& b) { return a *= b; }
    friend ModInt operator/(ModInt a, const ModInt& b) { return a /= b; }
};

// Define the mod here
const int MOD = 1e9 + 7;
using mint = ModInt<MOD>;

// Optional: cleaner external power function
template<typename T>
mint pow(mint a, T b) {
    return power(a, b);
}

// ---------------------- nCr Support ----------------------
vector<mint> fact, ifact;

void init_factorials(int maxn) {
    fact.resize(maxn + 1);
    ifact.resize(maxn + 1);
    fact[0] = 1;
    for (int i = 1; i <= maxn; ++i)
        fact[i] = fact[i - 1] * i;
    ifact[maxn] = fact[maxn].inv();
    for (int i = maxn - 1; i >= 0; --i)
        ifact[i] = ifact[i + 1] * (i + 1);
}

mint nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * ifact[r] * ifact[n - r];
}

// ---------------------- SOLVE ----------------------
void solve() {
    mint a, b;
    cin >> a >> b;
    cout << "a^b = " << pow(a, b.val) << '\n';

    int n, r;
    cin >> n >> r;
    cout << "nCr = " << nCr(n, r) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // init_factorials(1e6); // adjust upper bound as needed

    int t;
    cin >> t;
    while (t--) {
        solve();    
    }
    return 0;
}
