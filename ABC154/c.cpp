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
    ll a[n];
    std::vector<ll> v;
    int ans = 1;
    rep(i, n) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    Sort(v);
    rep(i, n-1) {
        if ( v.at(i) == v.at(i+1) ) {
            ans = 0;
        }
    }
    if ( ans ) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
