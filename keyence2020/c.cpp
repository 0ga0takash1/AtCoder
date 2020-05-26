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
    ll n, k, s;
    cin >> n >> k >> s;
    if ( s > 2 ) {
        rep(i, n) {
            if ( i < k ) {
                cout << s << " ";
            } else {
                cout << s-1 << " ";
            }
        }
    } else {
        if ( s == 1 ) {
            rep(i, n) {
                if ( i < k ) {
                    cout << 1 << " ";
                } else {
                    cout << 2 << " ";
                }
            }
        } else {
            rep(i, n) {
                if ( i < k ) {
                    cout << 2 << " ";
                } else {
                    cout << 3 << " ";
                }
            }
        }
    }

    cout << endl;
    return 0;
}
