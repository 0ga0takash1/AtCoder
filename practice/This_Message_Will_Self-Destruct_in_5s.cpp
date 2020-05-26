/*---------------------------------------------*/
/*
    ABC166 E
 */
/*---------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 1; i <= n; ++i)
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))

template<typename V,typename T>
T find_num(V v, T num) {
    if ( find(ALL(v), num) == v.end() ) {
        return false;
    } else {
        return true;
    }
}

// π M_PI
// deg = rad*180/M_PI

const ll inf = 1e9;

bool pair_Cs(const pair<ll, ll>& firstElof, const pair<ll, ll>& secondElof) {
    return firstElof.second < secondElof.second;
}

int main() {
    ll n;
    cin >> n;
    std::vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }






    //////////////////////////////////////////

    /*
    vector<pair<ll, ll> > p;

    rep(i, n) {
        cin >> a[i];
        p.push_back( make_pair(i, a[i]) );
    }

    sort(ALL(p), pair_Cs);

    std::vector<std::vector<ll> > G( *max_element(ALL(a)) );
    rep(i, n) {
        G[a[i]-1].push_back(i);
    }

    ll ans = 0;
    rep(i, G.size()) {
        rep(j, G[i].size() ) {
            rep(k, G.size()) {
                if (i == k) continue;

            }

        }
    }
    */
    //////////////////////////////////////////
    /*
    rep(i, G.size()-1) {
        for (ll j = i+1; j < G.size(); ++j) {
            rep(k, G[j].size()) {
                if ( abs( i-G[j].at(k) ) == i+j+2 ) {
                    ans++;
                }

                if ( abs( i-G[j].at(k) ) > i+j+2) {
                    break;
                }
            }
        }
    }*/
    //////////////////////////////////////////

    /*
    ll ans = 0;
    rep(i, n-1) {
        for (ll j = i+1; j < n; ++j) {
            if ( abs(i-j) == a[i]+a[j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    */
    return 0;
}
