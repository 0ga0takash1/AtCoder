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
    ll n, k;
    cin >> n >> k;
    ll h[n];
    std::vector<ll> v;
    rep(i, n) {
        cin >> h[i];
        v.push_back(h[i]);
    }
    Sort(v);
    ll ans = 0;
    rep(i, n-k) {
        ans += v.at(i);
    }
    cout << ans << endl;
    return 0;
}
