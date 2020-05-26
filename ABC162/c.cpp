#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 1; i <= n; ++i)
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))

template<typename V,typename T>
T find_num(V v, T num) {
    if ( find(ALL(v), num) == v.end() ) {
        return false;
    } else {
        return true;
    }
}

// π M_PI
// deg = rad*180/M_PI

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    rep2(i, n) {
        rep2(j, n) {
            rep2(k, n) {
                ans += gcd(i, gcd(j, k));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
