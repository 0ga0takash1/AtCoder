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
    ll n, k;
    cin >> n >> k;
    ll d[k];
    ll a[k][100];
    ll num[n] = {};
    rep(i, k) {
        cin >> d[i];
        rep(j, d[i]) {
            cin >> a[i][j];
            num[a[i][j]-1]++;
        }
    }

    ll ans = 0;
    rep(i, n) {
        if ( num[i] == 0 ) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
