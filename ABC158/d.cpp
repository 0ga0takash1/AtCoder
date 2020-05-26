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
    /*
    std::vector<char> v;
    rep(i, s.size()) {
        v.push_back(s[i]);
    }*/
    ll q;
    cin >> q;
    ll num[q];
    ll f[q];
    char c[q];

    rep(i, q) {
        cin >> num[i];
        if ( num[i] == 2 ) {
            cin >> f[i] >> c[i];
        }
    }
/*
    int keep = 0;
    rep(i, q) {
        if ( num[i] == 1 ) {
            if ( num[i+1] != 1 || num[i-1] != 1 ) {
                reverse(ALL(v));
            }
        } else {
            if ( f[i] == 1 ) {
                v.insert(v.begin(), c[i]);
            } else {
                v.insert(v.end(), c[i]);
            }
        }
    }
*/
    ll top = 0;
    rep(i, q) {
        if ( num[i] == 1 ) {
            top = !top;
        } else {
            if (top) {
                if ( f[i] == 1 ) {
                    // v.push_back(c[i]);
                    s.insert(s.end(), c[i]);
                } else {
                    // v.insert(v.begin(), c[i]);
                    s.insert(s.begin(), c[i]);
                }
            } else {
                if ( f[i] == 1 ) {
                    s.insert(s.begin(), c[i]);
                } else {
                    // v.push_back(c[i]);
                    s.insert(s.end(), c[i]);
                }
            }
        }
    }

    if (top) {
        reverse(ALL(s));
    }
/*
    rep(i, v.size()) {
        cout << v[i];
    }*/
    cout << s << endl;
    return 0;
}
