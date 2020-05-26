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
    ll a, b, k;
    cin >> a >> b >> k;
    if ( a+b <= k ) {
        cout << 0 << " " << 0 << endl;
    } else {
        if ( a <= k ) {
            k -= a;
            a = 0;
            if ( k != 0 ) {
                if ( b <= k ) {
                    b = 0;
                } else {
                    b -= k;
                }
            }
        } else {
            a -= k;
        }
        cout << a << " " << b << endl;
    }
    return 0;
}
