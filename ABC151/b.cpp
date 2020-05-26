#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ALL(v) (v).begin(), (v).end()

//π M_PI
//deg = rad*180/M_PI

int main() {
    ll n, k, m;
    cin >> n >> k >> m;
    ll a[n-1];
    // std::vector<int> aa;
    ll sum = 0;
    rep(i, n-1) {
        cin >> a[i];
        sum += a[i];
        // aa.push_back(a[i]);
    }

    ll ans = m*n - sum;
    if ( ans > k ) {
        cout << -1 << endl;
    } else {
        if ( ans <= 0 ) {
            cout << 0 << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
