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
    int n;
    cin >> n;
    int a[n];
    int ans = 0;
    int ans2 = 0;
    std::vector<int> v;
    rep(i, n) {
        cin >> a[i];

        if ( a[i]%2 == 0 ) {
            ans++;
            if ( a[i]%3 == 0 || a[i]%5 == 0 ) {
                ans2++;
            }
        }
    }

    cout << (ans == ans2 ? "APPROVED" : "DENIED" ) << endl;
    return 0;
}
