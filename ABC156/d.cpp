#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 1; i <= n; ++i)
#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ALL(v) (v).begin(), (v).end()

// π M_PI
// deg = rad*180/M_PI

const ll MOD = 1e9 + 7;

ll Mod(ll a, ll mod) {
    return (a%mod + mod)%mod;
}

ll pow_mod(ll x, ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if (n & 1) {
            res = res*x%mod;
        }
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}

ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x);
    y -= a / b * x;
    return d;
}

ll modinv(ll a, ll mod) {
    ll x, y;
    extGCD(a, mod, x, y);
    return Mod(x, mod);
}

ll nCr_mod(ll n, ll r, ll mod) {
    if ( n == r || n == 1 ) {
        return 1;
    }

    r = min(r, n-r);
    if ( r == 1 ) {
        return n;
    } else {
        ll n_to_n_r = n;
        ll r_to_1 = r;
        rep2(i, r-1) {
            n_to_n_r *= n-i;
            n_to_n_r %= mod;
            r_to_1 *= r-i;
            r_to_1 %= mod;
        }
        // r_to_1 = pow_mod(r_to_1, mod-2, mod);
        r_to_1 = modinv(r_to_1, MOD);
        return n_to_n_r*r_to_1%mod;
    }
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    
    ll ans = pow_mod(2, n, MOD)-1;
    ans = Mod(ans-nCr_mod(n, a, MOD), MOD);
    ans = Mod(ans-nCr_mod(n, b, MOD), MOD);
    cout << ans << endl;
    return 0;
}
