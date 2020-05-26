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
    ll n;
    cin >> n;
    string s[n];
    std::vector<string> v;
    // ll ans = n;
    rep(i, n) {
        cin >> s[i];
        v.push_back(s[i]);
        /*
        rep(j, i) {
            if ( s[i] == s[j] ) {
                ans--;
                break;
            }
        }*/
    }

    ll ans = 0;
    Sort(v);
    rep(i, n) {
        if ( i == 0 ) {
            ans++;
        } else {
            if ( v[i] != v[i-1] ) {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
