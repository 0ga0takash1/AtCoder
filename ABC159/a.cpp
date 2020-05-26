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

ll nCr(ll n , ll r) {
    if ( n == r || n == 1 || r == 0 ) {
        return 1;
    }

    r = min(r, n-r);
    if ( r == 1 ) {
        return n;
    } else {
        std::vector<std::vector<ll> > v(n + 1,std::vector<ll>(n + 1, 0));
        for (int i = 0; i < v.size(); i++) {
            v[i][0] = 1;
            v[i][i] = 1;
        }
        for (int j = 1; j < v.size(); j++) {
            for (int k = 1; k < j; k++) {
                v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
            }
        }
        return v[n][r];
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    if ( n >= 2 && m >= 2 ) {
        ans = nCr(n, 2)+nCr(m, 2);
    } else {
        if ( m < 2 ) {
            if ( n >= 2 ) {
                ans = nCr(n, 2);
            } else {
                ans = 0;
            }
        } else {
            if ( m >= 2 ) {
                ans = nCr(m, 2);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
