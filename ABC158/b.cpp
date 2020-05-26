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
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = 0;
    if ( n <= a ) {
        cout << n << endl;
    } else {
        ll c = n/(a+b);
        ans = a*c;
        ll cc = n%(a+b);
        if ( cc != 0 ) {
            ans += min(n-((a+b)*c), a);
        }
        /*
        while (1) {
            if ( count+a > n ) {
                ans += n-count;
                count = n;
            } else {
                ans += a;
                count += a+b;
            }
            if ( count >= n ) {
                break;
            }
            // cout << "ans = " << ans << endl;
        }
        */

        cout << ans << endl;
    }
    return 0;
}
