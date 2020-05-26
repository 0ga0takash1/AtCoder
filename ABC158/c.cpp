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
    int a, b;
    cin >> a >> b;
/*
    ll aa, bb;
    aa = a/0.08;
    bb = b/0.1;
    ll a1 = max(aa, bb)*0.08;
    ll b1 = max(aa, bb)*0.1;
    // cout << "aa = " << aa << " bb = " << bb << endl;
    // cout << "a1 = " << a1 << " b1 = " << b1 << endl;
    if ( a1 == a && b1 == b ) {
        cout << max(aa, bb) << endl;
    } else {
        cout << -1 << endl;
    }*/
    rep2(i, (int)100/0.08) {
        if ( (int)(i*0.08) == a && (int)(i*0.1) == b ) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
