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
const ll mod = 1e9 + 7;

int jump ( int a , std::vector<ll> b ) {
    if ( b[a] == 0 ) {
        a++;
        jump(a, b);
    }
    return a;
}

int main() {
    ll n;
    cin >> n;
    ll x[n];
    std::vector<ll> xx;
    rep(i, n) {
        cin >> x[i];
        xx.push_back(x[i]);
    }

    ll ans = 0;
    std::vector<ll> v;
    rep(i, n-1) {
        v.push_back(i+1);
    }
    // cout << "a" << endl;
    std::vector<ll> nn;
    do {
        ll num = 0;
        rep(i, n) {
            nn.push_back(xx[i]);
        }
        // cout << "b" << endl;
        rep(i, n-1) {
            //cout << "v[i] = " << v[i] << endl;

            num += nn[v[i]+jump(v[i], nn)] - nn[v[i]-1];
            // cout << "c" << endl;
            // nn.erase(nn.begin()+(v[i]-1));
            nn[v[i-1]] = 0;
        }
        // cout << "d" << endl;
        // cout << num << endl;
        ans += num;
        cout << ans << endl;
        std::vector<ll>().swap(nn);
    } while(next_permutation(ALL(v)));


    for (int i = n-2; i >= 1; --i) {
        ans *= i;
    }

    cout << ans%mod << endl;
    return 0;
}
