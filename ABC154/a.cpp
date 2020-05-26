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
    string s, t, u;
    int a, b;
    cin >> s >> t;
    cin >> a >> b;
    cin >> u;
    if ( s == u ) {
        cout << a-1 << " " << b << endl;
    } else if ( t == u ) {
        cout << a << " " << b-1 << endl;
    }
    return 0;
}
