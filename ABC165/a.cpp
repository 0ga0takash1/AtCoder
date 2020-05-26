#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 1; i <= n; ++i)
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))

template<typename V,typename T>
T find_num(V v, T num) {
    if ( find(ALL(v), num) == v.end() ) {
        return false;
    } else {
        return true;
    }
}

// π M_PI
// deg = rad*180/M_PI

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    /*
    ll num = 2;
    ll nn = n;
    while (nn <= k) {
        if ( nn >= m && nn <= k ) {
            ans = 1;
            break;
        }
        nn = n*num;
        // cout << "n" << nn << endl;
        num++;
    }*/
    for (ll i = m; i <= k; ++i) {
        if ( i%n == 0 ) {
            ans = 1;
        }
    }
    cout << ( ans ? "OK" : "NG" ) << endl;
    return 0;
}
