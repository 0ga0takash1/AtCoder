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
    ll k;
    cin >> k;

    if ( k <= 10 ) {
        cout << k << endl;
    } else {
        if ( k <= 36 ) {
            k -= 9;
            long double num = k/3.0;
            ll a = k%3;
            if ( num <= 1.0 ) {
                num = 1;
            } else if ( num <= 2.0 ) {
                num = 2;
            } else if ( num <= 3.0 ) {
                num = 3;
            } else if ( num <= 4.0 ) {
                num = 4;
            } else if ( num <= 5.0 ) {
                num = 5;
            } else if ( num <= 6.0 ) {
                num = 6;
            } else if ( num <= 7.0 ) {
                num = 7;
            } else if ( num <= 8.0 ) {
                num = 8;
            } else if ( num <= 9.0 ) {
                num = 9;
            }

            ll ans;
            if ( a == 1 ) {
                ans = num*10+num-1;
            } else if ( a == 2 ) {
                ans = num*10+num;
            } else {
                ans = num*10+num+1;
            }
            cout << ans << endl;
        } else {
            ll dig;
            ll i = 2;
            while (1) {
                /* code */
            }
        }
    }

    std::vector<std::vector<ll> > v(10);
    rep(i, 10) {
        if ( i == 0 ) {
            v[i].push_back(0);
            v[i].push_back(1);
        } else if ( i == 9 ) {
            v[i].push_back(8);
            v[i].push_back(9);
        } else {
            rep(j, 3) {
                v[i].push_back(j+i-1);
            }
        }
    }
    return 0;
}
