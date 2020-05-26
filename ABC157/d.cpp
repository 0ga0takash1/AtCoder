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

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll a[m], b[m];
    rep(i, m) {
        cin >> a[i] >> b[i];
    }
    ll c[k], d[k];
    rep(i, k) {
        cin >> c[i] >> d[i];
    }
    return 0;
}
