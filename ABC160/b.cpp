#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 1; i <= n; ++i)
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))

// π M_PI
// deg = rad*180/M_PI

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    ans += (n/500)*1000;
    n = n%500;
    ans += (n/5)*5;
    cout << ans << endl;
    return 0;
}
