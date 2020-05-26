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
const ll MOD = 1e9 + 7;

int main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;

    if ( n+1 == k ) {
        ans++;
    } else {
        for (ll i = k; i <= n+1; ++i) {
            ll min = i*(i-1)/2;
            ll max = i*(2*n-i+1)/2;
            ans += max-min+1;
        }
    }

    cout << ans%MOD << endl;
    return 0;
}
