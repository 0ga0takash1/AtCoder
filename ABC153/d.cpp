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

ll func( ll a , ll ans ) {
    // cout << "a " << ans << endl;
    if ( a <= 1 ) {
        ans++;
        // cout << "b " << ans << endl;
    } else {
        // ans++;
        // cout << "c " << ans << endl;
        ans = 2*func(a/2, ans)+1;
        // ans = func(a/2, ans);
        // cout << "d " << ans << endl;
        // func(a/2, ans);
    }

    return ans;
}

int main() {
    ll h;
    cin >> h;
    ll ans = 0;
    ans = func(h, ans);
    cout << ans << endl;
    return 0;
}
