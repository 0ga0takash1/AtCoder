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

int main() {
    ll n, m;
    cin >> n >> m;
    ll a[n];
    std::vector<ll> v;
    rep(i, n) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    Sort_rev(v);
    ll all = accumulate(ALL(v), 0LL);
    ll ans = 0;
    rep(i, n) {
        if ( v[i]*4*m >= all ) {
            ans++;
        } else {
            break;
        }
    }

    cout << ( (ans >= m) ? "Yes" : "No" ) << endl;
    return 0;
}
