#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define repe(a, b) for (auto&(a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define mp(a, b) make_pair((a), (b))
#define Push_back(a, b) push_back( mp( (a), (b) ) )

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 1e9+7;

int64_t Mod(int64_t a, int64_t mod) {
    return (a%mod + mod)%mod;
}

int64_t pow_mod(int64_t x, int64_t n, int64_t mod) {
    int64_t res = 1;
    while(n > 0) {
        if (n & 1) {
            res = res*x%mod;
        }
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}

int64_t extGCD(int64_t a, int64_t b, int64_t &x, int64_t &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int64_t d = extGCD(b, a%b, y, x);
    y -= a / b * x;
    return d;
}

int64_t modinv(int64_t a, int64_t mod) {
    int64_t x, y;
    extGCD(a, mod, x, y);
    return Mod(x, mod);
}

int64_t nCr_mod(int64_t n, int64_t r, int64_t mod) {
    if ( n == r || n == 1 || r == 0 ) {
        return 1;
    }

    r = min(r, n-r);
    if ( r == 1 ) {
        return n;
    } else {
        int64_t n_to_n_r = n;
        int64_t r_to_1 = r;
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

int64_t powmod(int64_t x, int64_t y) {
    int64_t res = 1;
    for(int64_t i = 0; i<y; i++) {
        res=res*x%MOD;
    }
    return res;
}

int main() {
    int64_t n;
    cin >> n;
/*
    std::vector<int64_t> v;
    v.push_back(n);
    repb2(i, 2, n-2) v.push_back( ( (v.at(v.size()-1)*(n-i) )/i )%MOD );

    int64_t ans = (n*(n-1))%MOD;
    if ( n >= 3 ) {
        ans *= (int64_t)pow(8, n-2)%MOD;
        ans += accumulate(ALL(v), 0LL);
    }*/
    /*
    rep(i, n-2) {
        /*
        if ( i == 0 ) {
            ans *= 10;
        } else {
            ans *= 9;
        }
        ans *= 8;
        ans %= MOD;
        // cout << i << ": " << ans << endl;
    }*/
/*
    if ( n >= 3 ) {
        // ans -= ( (n*(n-1)) )%MOD;
        rep2(i, n/2) {
            int64_t num = nCr_mod(n, i, MOD);
            if ( i == n/2 ) {
                ans += num;
            } else {
                ans += num*2;
            }
        }
    }
*/

    // int64_t ans = ( ( (int64_t)pow(10, n-2)*2 )+MOD );
    int64_t ans = (int64_t)( powmod(10, n)-(powmod(9, n)*2)+powmod(8, n) );
    ans %= MOD;
    if ( ans < 0 ) ans += MOD;
    cout << ans << endl;
    return 0;
}
