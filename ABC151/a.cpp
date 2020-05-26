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
    char s;
    cin >> s;
    string ss = "abcdefghijklmnopqrstuvwxyzz";
    rep(i, ss.length()) {
        if ( s == ss[i] ) {
            cout << ss[i+1] << endl;
            break;
        }
    }
    return 0;
}
