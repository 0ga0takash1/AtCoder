#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 1; i < n; ++i)
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))

// π M_PI
// deg = rad*180/M_PI

bool pair_Cs_R(const pair<ll, ll>& firstElof, const pair<ll, ll>& secondElof) {
    return firstElof.second > secondElof.second;
}

int main() {
    ll k, n;
    cin >> k >> n;
    ll a[n];
    std::vector<ll> v;
    ll ans = 0;
    rep(i, n) {
        cin >> a[i];
        if ( i > 0 ) {
            v.push_back(a[i]-a[i-1]);
        }
    }
    v.push_back(k-a[n-1]+a[0]);
    Sort(v);
    ans = k - *max_element(ALL(v));
/*
    rep(i, n-1) {
        ans += v[i];
    }*/
    cout << ans << endl;
    return 0;
}
