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
    ll a[3][3], aa[3][3];
    rep(i, 3) {
        rep(j, 3) {
            cin >> a[i][j];
            aa[i][j] = 0;
        }
    }
    ll n;
    cin >> n;
    ll b[n];
    rep(i, n) {
        cin >> b[i];
        rep(j, 3) {
            rep(k, 3) {
                if ( b[i] == a[j][k] ) {
                    aa[j][k] = 1;
                }
            }
        }
    }
    int ans = 0;
    int num = 0;
    int num2 = 0;
    if ( (aa[0][0] == 1 && aa[1][1] == 1 && aa[2][2] == 1)
        || (aa[0][2] == 1&& aa[1][1] == 1 && aa[2][0] == 1) ) {
        ans = 1;
    } else {
        rep(i, 3) {
            rep(j, 3) {
                if ( aa[i][j] == 1 ) {
                    num++;
                }
                if ( aa[j][i] == 1 ) {
                    num2++;
                }
            }
            if ( num == 3 || num2 == 3 ) {
                ans = 1;
                break;
            }
            num = 0;
            num2 = 0;
        }
    }

    if ( ans ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
