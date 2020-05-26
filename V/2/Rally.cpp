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
    ll n;
    cin >> n;
    std::vector<ll> x(n);
    rep(i, n) {
        cin >> x[i];
    }

    std::vector<ll> v;
    for (ll i = *min_element(ALL(x)); i <= *max_element(ALL(x)); ++i) {
        ll sum = 0;
        rep(j, n) {
            sum += pow((x[j]-i), 2);
        }
        v.push_back(sum);
    }

    cout << *min_element(ALL(v)) << endl;
    return 0;
}
