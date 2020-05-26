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
    ll n;
    cin >> n;
    ll p[n];
    rep(i, n) {
        cin >> p[i];
    }

    ll Min = p[0];
    ll ans = 1;
    rep(i, n) {
        if ( i > 0 ) {
            if ( Min > p[i] ) {
                ans++;
                // Min = p[i];
            }
            Min = min(Min, p[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
