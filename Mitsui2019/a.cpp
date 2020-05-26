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
    int m1, m2, d1, d2;
    cin >> m1 >> d1 >> m2 >> d2;

    if ( m1+1 == m2 ) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
