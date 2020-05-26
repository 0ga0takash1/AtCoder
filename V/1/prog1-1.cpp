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
    ll a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
/*
    std::vector<int> v;
    if ( a == 1 ) {
        ans = 1;
    } else {
        if ( a%2 != 0 || b%2 != 0 ) {
            int num = 100/a;
            int keep = a;
            ll i = 2;
            while (1) {
                if ( a%b == c ) {
                    ans = 1;
                    break;
                }

                int jouyo = 0;
                if ( v.size() != 1 ) {
                    rep(j, v.size()) {
                        if ( a%b == v.at(j) ) {
                            jouyo = 1;
                            break;
                        }
                    }
                    if (jouyo) {
                        break;
                    }
                }

                v.push_back(a%b);
                a = keep*i;
                ++i;
            }
        }
    }
*/
    int keep = a;
    for (size_t i = 2; i < b; i++) {
        if ( a%b == c ) {
            ans = 1;
            break;
        }

        a = keep*i;
    }
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}
