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

ll nCr(ll n , ll r) {
    if ( n == r || n == 1 || r == 0 ) {
        return 1;
    }

    r = min(r, n-r);
    if ( r == 1 ) {
        return n;
    } else {
        std::vector<std::vector<ll> > v(n + 1,std::vector<ll>(n + 1, 0));
        for (int i = 0; i < v.size(); i++) {
            v[i][0] = 1;
            v[i][i] = 1;
        }
        for (int j = 1; j < v.size(); j++) {
            for (int k = 1; k < j; k++) {
                v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
            }
        }
        return v[n][r];
    }
}

bool pairCompareRev(const pair<ll, ll>& firstElof, const pair<ll, ll>& secondElof) {
    return firstElof.second > secondElof.second;
}

bool pairCompare(const pair<ll, ll>& firstElof, const pair<ll, ll>& secondElof) {
    return firstElof.first < secondElof.first;
}

int main() {
    ll n;
    cin >> n;
    ll a[n];
    std::vector<ll> v;
    vector<pair<ll, ll> > p;
    rep(i, n) {
        p.push_back( make_pair(i, 0) );
    }

    rep(i, n) {
        cin >> a[i];
        v.push_back(a[i]);
        p.at(a[i]-1).second++;
    }

    Sort(v);
    reverse(ALL(v));
    sort(ALL(p), pairCompareRev);

    if ( p.at(0).second <= 1 ) {
        rep(i, n) {
            cout << 0 << endl;
        }
    } else if (p.at(0).second == n) {
         rep(i, n) {
             cout << nCr(n-1, 2) << endl;
         }
    } else {
        rep(i, n) {
            ll num;
            rep(k, n) {
                if ( k == a[i]-1 ) {
                    num = k;
                }
            }
            ll keep;
            if ( p.at(num).second > 1 ) {
                keep = p.at(num).second;
                p.at(num).second--;
                sort(ALL(p), pairCompare);

                ll ans = 0;
                rep(j, n) {
                    if ( j >= v.at(0) ) {
                        break;
                    }
                    if ( p.at(j).second < 2 ) {
                        continue;
                    }
                    // cout << "a" << p.at(a[i]-1).first << " b" << p.at(a[i]-1).second << endl;
                    ans += nCr(p.at(j).second, 2);
                }
                p.at(a[i]-1).second = keep;
                cout << ans << endl;
            }
        }
    }
    return 0;
}
