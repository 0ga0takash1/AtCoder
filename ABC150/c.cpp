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
    int p[n], q[n];
    rep(i, n) {
        cin >> p[i];
    }
    rep(i, n) {
        cin >> q[i];
    }

    std::vector<ll> v;
    rep(i, n) {
        v.push_back(i+1);
    }

    int ii = 1;
    int a = 0;
    int b = 0;
    do {
        int k = 0;
        int l = 0;
        rep(i, n) {
            if ( v[i] == p[i] && a == 0 ) {
                k++;
                // cout << "k = " << k << endl;
            }
            if ( v[i] == q[i] && b == 0 ) {
                l++;
                //cout << "l = " << l << endl;
            }
        }
        if ( k == n ) {
            //cout << "k == " << k << endl;
            a = ii;
        }
        if ( l == n ) {
            //cout << "l == " << l << endl;
            b = ii;
        }
        ii++;
        //cout << "ii = " << ii << endl;
    } while(next_permutation(ALL(v)));
    cout << abs(a-b) << endl;
    return 0;
}
