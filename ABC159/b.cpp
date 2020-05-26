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
    string s;
    cin >> s;
    int ans = 1;
    rep(i, s.length()/2) {
        if ( s[i] != s[s.length()-i-1] ) {
            ans = 0;
        }
    }
    rep(i, s.length()/4) {
        if ( s[i] != s[ ((s.length()-1)/2)-i-1] ) {
            ans = 0;
            // cout << "a" << endl;
        }
        if ( s[((s.length()+3)/2)+i-1] != s[s.length()-i-1]) {
            ans = 0;
            // cout << "b" << endl;
        }
    }

    cout << (ans ? "Yes" : "No" ) << endl;
    return 0;
}
