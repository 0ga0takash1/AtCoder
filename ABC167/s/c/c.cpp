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

bool pair_Cf(const pair<ll, ll>& firstElof, const pair<ll, ll>& secondElof) {
    return firstElof.first < secondElof.first;
}

int main() {
    ll n, m, x;
    cin >> n >> m >> x;

    ll c[n];
    vector<pair<ll, ll> > p;
    ll a[n][m];
    rep(i, n) {
        cin >> c[i];
        p.push_back( make_pair(c[i], i) );

        rep(j, m) {
            cin >> a[i][j];
        }
    }

    sort(ALL(p), pair_Cf);
    ll able = 0;
    ll ans = 0;
    std::vector<ll> v(m, 0);
    rep(i, n) {
        ans += p[i].first;
        rep(j, m) {
            v[j] += a[p[i].second][j];
        }

        ll able2 = 1;
        rep(j, m) {
            if ( v[j] < x ) {
                able2 = 0;
                break;
            }
        }

        able = able2;
        if ( able ) {
            break;
        }
    }

    if ( !able ) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
