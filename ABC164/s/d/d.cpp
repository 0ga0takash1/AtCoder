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
    string s;
    cin >> s;
    ll ans = 0;
    for (ll i = 4; i < s.length(); ++i) {
        rep(j, s.length()-i+1) {
            string ss = s.substr(j, i);
            int num = atoi(ss.c_str());
            if ( num%2019 == 0 ) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
