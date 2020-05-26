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
    ll n;
    cin >> n;
    string s[n];
    int t[n];
    // std::vector<int> v;
    rep(i, n) {
        cin >> s[i] >> t[i];
        // v.push_back(t[i]);
    }
    string x;
    cin >> x;

    int num;
    rep(i, n) {
        if ( s[i] == x ) {
            num = i;
            break;
        }
    }

    ll ans = 0;
    for (int i = num+1; i < n; ++i) {
        ans += t[i];
    }
    cout << ans << endl;
    // cout << accumulate(v.at[num+1], v.end()) << endl;
    return 0;
}
