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
    ll h, w, n;
    cin >> h >> w >> n;
    if ( h < w ) {
        if ( n%w == 0 ) {
            // cout << "a" << endl;
            cout << n/w << endl;
        } else {
            // cout << "b" << endl;
            cout << (n/w)+ 1 << endl;
        }
    } else {
        if ( n%h == 0 ) {
            // cout << "c" << endl;
            cout << n/h << endl;
        } else {
            // cout << "d" << endl;
            cout << (n/h)+ 1 << endl;
        }
    }
    return 0;
}
