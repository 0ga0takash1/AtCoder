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
    string s;
    cin >> s;
    int ans;
    if ( s == "SUN") {
        ans = 7;
    } else if ( s == "MON") {
        ans = 6;
    } else if ( s == "TUE") {
        ans = 5;
    } else if ( s == "WED") {
        ans = 4;
    } else if ( s == "THU") {
        ans = 3;
    } else if ( s == "FRI") {
        ans = 2;
    } else if ( s == "SAT") {
        ans = 1;
    }
    cout << ans << endl;
    return 0;
}
