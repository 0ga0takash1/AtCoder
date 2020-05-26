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
    for (ll i = 0; i < s.length(); i = i+2) {
        if ( s[i] != 'h' || s[i+1] != 'i' ) {
            ans = 0;
        }
    }

    cout << (ans ? "Yes" : "No" ) << endl;
    return 0;
}
