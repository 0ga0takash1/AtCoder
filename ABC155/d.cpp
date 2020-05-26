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
    // ll a[n];
    std::vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    Sort(a);
    
    if ( a[0] > 0 ) {

    } else if ( a[0] == 0 ) {

    } else {

    }
/*
    // std::vector<ll> v;
    priority_queue<ll> v;
    rep(i, n-1) {
        for (ll j = i+1; j < n; ++j) {
            ll aa = a[i]*a[j];
            if ( v.size() <= k ) {
                v.push(aa);
            } else {
                if ( v.top() >= aa ) {
                    v.pop();
                    v.push(aa);
                }
            }
        }
    }
    // Sort(v);

    cout << v.top() << endl;
*/

    return 0;
}
