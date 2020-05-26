#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ALL(v) (v).begin(), (v).end()

// π M_PI
// deg = rad*180/M_PI

int main() {
    int n, r;
    cin >> n >> r;
    if ( n < 10 ) {
        cout << r+100*(10-n) << endl;
    } else {
        cout << r << endl;
    }
    return 0;
}
