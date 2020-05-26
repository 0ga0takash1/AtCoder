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
    ll n, m;
    cin >> n >> m;
    ll p[m];
    string s[m];
    int qq[n] = {};
    int qqq[n] = {};
    rep(i, m) {
        cin >> p[i] >> s[i];
        if ( s[i] == "AC" ) {
            qqq[p[i]-1] = 1;
        }
    }

    ll AC = 0;
    ll WA = 0;

    rep(i, m) {
        if ( s[i] == "AC" && qq[p[i]-1] == 0 ) {
            AC++;
            qq[p[i]-1] = 1;
        } else if ( s[i] == "WA" && qq[p[i]-1] == 0 && qqq[p[i]-1] == 1) {
            WA++;
        }
    }
    cout << AC << " " << WA << endl;
    return 0;
}
