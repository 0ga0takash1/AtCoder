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

bool pairCompare(const pair<ll, ll>& firstElof, const pair<ll, ll>& secondElof) {
    return firstElof.first < secondElof.first;
}

int main() {
    ll n, m;
    cin >> n >> m;
    int ans = 0;
    if ( m == 0 ) {
        if ( n != 1 ) {
            ans = pow(10, n-1);
        }
        cout << ans << endl;
        return 0;
    }
    ll s[m], c[m];
    ll Ans[n] = {};
    vector<pair<ll, ll> > pairs;

    int j = 1;
    rep(i, m) {
        cin >> s[i] >> c[i];
        if ( n != 1 && s[i] == 1 && c[i] == 0 ) {
            j = 0;
        }
        pairs.push_back( make_pair(s[i], c[i]) );
    }
    if (!j) {
        cout << -1 << endl;
        return 0;
    }

    sort(ALL(pairs), pairCompare);

    rep(i, m) {
        if ( i == 0 ) {
            Ans[pairs.at(i).first-1] = pairs.at(i).second;
        } else {
            if ( Ans[pairs.at(i).first-1] != 0 ) {
                if ( Ans[pairs.at(i).first-1] != pairs.at(i).second ) {
                    j = 0;
                    break;
                }
            } else {
                Ans[pairs.at(i).first-1] = pairs.at(i).second;
            }
        }
    }

    if (!j) {
        cout << -1 << endl;
        return 0;
    }
    if ( n > 1 && Ans[0] == 0 ) {
        Ans[0] = 1;
    }

    if ( Ans[0] != 0 || Ans[1] != 0 || Ans[2] != 0 ) {
        rep(i, n) {
/*
            if ( Ans[i] != 0 && i != n-1 ) {
                ans += Ans[i]*pow(10, n-i-2);
            } else if ( i == n-1 ) {
                ans *= 10;
                ans += Ans[i];
*/
            cout << Ans[i];
        }
    } else {
        ans += pow(10, n-1);
    }

    // cout << ans << endl;
    return 0;
}
