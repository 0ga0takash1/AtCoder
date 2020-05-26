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
    ll n, k;
    cin >> n >> k;
    ll r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;
    ll ans = 0;
    std::vector<string> v;
    rep(i, t.length()) {
        if ( i <= k ) {
            if ( t[i] == 'r' ) {
                ans += p;
                v.push_back("p");
            } else if ( t[i] == 's' ) {
                ans += r;
                v.push_back("r");
            } else if ( t[i] == 'p' ) {
                ans += s;
                v.push_back("s");
            }
        } else {
            if ( t[i] == 'r' ) {
                if ( v[i-k] != "p" ) {
                    ans += p;
                    v.push_back("p");
                } else {
                    if ( t[i+k] == 'r' ) {
                        /* code */
                    } else if ( t[i+k] == 's' ) {
                        /* code */
                    } else if ( t[i+k] == 'p' ) {
                        /* code */
                    }
                }
            } else if ( t[i] == 's' ) {
                if ( v[i-k] != "r" ) {
                    ans += r;
                    v.push_back("r");
                } else {
                    if ( t[i+k] == 'r' ) {
                        /* code */
                    } else if ( t[i+k] == 's' ) {
                        /* code */
                    } else if ( t[i+k] == 'p' ) {
                        /* code */
                    }
                }
            } else if ( t[i] == 'p' ) {
                if ( v[i-k] != "s" ) {
                    ans += s;
                    v.push_back("s");
                } else {
                    if ( t[i+k] == 'r' ) {
                        /* code */
                    } else if ( t[i+k] == 's' ) {
                        /* code */
                    } else if ( t[i+k] == 'p' ) {
                        /* code */
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
