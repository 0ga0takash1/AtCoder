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

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

bool judge( ll n, ll x[], ll l[], vector<pair<ll, ll> > b ) {
    rep(i, n) {
        rep(j, n) {
            if ( i != j ) {
                if ( x[b[i].first]-l[b[i].first] < x[b[j].first]
                    || x[b[j].first] < x[b[i].first]+l[b[i].first] ) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ll n;
    cin >> n;
    ll x[n], l[n];
    vector<pair<ll, ll> > pairs(n);
    rep(i, n) {
        cin >> x[i] >> l[i];
        pairs[i].first = i;
        pairs[i].second = 0;
    }

    vector< vector<ll> > v(n, vector<ll>(n, 0));
    rep(i, n) {
        rep(j, n) {
            if ( i != j ) {
                if ( x[i]-l[i] < x[j] || x[j] < x[i]+l[i] ) {
                    v.at(i).at(j) = 1;
                    pairs[i].second++;
                    cout << "aaaaa" << endl; 
                }
            }
        }
    }

    sort(ALL(pairs), compare_by_b);
    if ( pairs[n-1].second == 0 ) {
        cout << n << endl;
    } else if ( pairs[n-1].second == 1 ) {
        ll count = 0;
        rep(i, n) {
            if ( pairs[i].second == 1 ) {
                count++;
            }
        }
        cout << n-(count/2) << endl;
    } else {
        ll num = n-1;
        ll ans = n;
        while ( pairs[num].second != 0 ) {
            if (judge(num, x, l, pairs)) {
                cout << ans << endl;
                break;
            } else {
                num--;
                ans--;
            }
        }
    }

    return 0;
}
