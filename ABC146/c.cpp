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

const ll pow10_9 = 1000000000;

int main() {
    ll a, b, x;
    cin >> a >> b >> x;
    ll ans = 0;

    if ( x > a*pow10_9+b*10 ) {
        cout << pow10_9 << endl;
        return 0;
    }
    if ( x <= a*(pow10_9/2)+b*(log10(pow10_9/2)+1) ) {
        if ( x<= a*(pow10_9/4)+b*(log10(pow10_9/4)+1) ) {
            rep(i, pow10_9/4) {
                ll num = log10(i)+1;
                if ( a*i+b*num > x) {
                    break;
                }
                ans = i;
            }
        } else {
            rep(i, pow10_9/4) {
                i += pow10_9/4;
                ll num = log10(i)+1;
                if ( a*i+b*num > x) {
                    break;
                }
                ans = i;
            }
        }
    } else {
        if ( x<= a*(pow10_9*0.75)+b*(log10(pow10_9*0.75)+1)) {
            rep(i, pow10_9/4) {
                i += pow10_9/2;
                ll num = log10(i)+1;
                if ( a*i+b*num > x) {
                    break;
                }
                ans = i;
            }
        } else {
            rep(i, pow10_9/4) {
                i += pow10_9*0.75;
                ll num = log10(i)+1;
                if ( a*i+b*num > x) {
                    break;
                }
                ans = i;
            }
        }

    }

    cout << ans << endl;
    return 0;
}
