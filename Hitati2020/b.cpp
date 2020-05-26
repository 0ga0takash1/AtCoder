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
    ll A, B, M;
    cin >> A >> B >> M;
    std::vector<ll> a(A);
    std::vector<ll> b(B);
    rep(i, A) {
        cin >> a[i];
    }
    rep(i, B) {
        cin >> b[i];
    }
    ll ans = (*min_element(ALL(a)))+(*min_element(ALL(b)) );
    ll x[M], y[M], c[M];
    rep(i, M) {
        cin >> x[i] >> y[i] >> c[i];
    }

    std::vector<ll> v;
    rep(i, M) {
        v.push_back(a[x[i]-1]+b[y[i]-1]-c[i]);
    }
    Sort(v);
    cout << min(ans, v.at(0) ) << endl;
    return 0;
}
