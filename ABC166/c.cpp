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
    std::vector<std::vector<ll> > G(n);
    ll h[n];
    rep(i, n) {
        cin >> h[i];
    }
    ll a[m], b[m];
    rep(i, m) {
        cin >> a[i] >> b[i];
        G[a[i]-1].push_back(b[i]-1);
        G[b[i]-1].push_back(a[i]-1);
    }

    ll ans = 0;
    rep(i, n) {
        ll high = 1;
        rep(j, G[i].size()) {
            if ( h[i] <= h[G[i].at(j)] ) {
                high = 0;
            }
        }

        if ( high ) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
