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
    double l;
    cin >> l;
    double ans;
/*
    if ( ans%3 == 0 ) {
        ans = pow((l/3), 3);
    } else {

    }*/
    ans = pow(l, 3)/27;
    cout << setprecision(12) << ans << endl;
    return 0;
}
