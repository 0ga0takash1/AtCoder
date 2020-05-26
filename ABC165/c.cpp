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


bool pair_Cs_R(const pair<ll, ll>& firstElof, const pair<ll, ll>& secondElof) {
    return firstElof.second > secondElof.second;
}

int main() {
    ll n, m, q;
    cin >> n >> m >> q;
    ll a[q], b[q], c[q], d[q];
    rep(i, q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    std::vector<ll> v(n, -1);
    std::vector<ll> dd(n, -1);
    v[0] = 1;
    rep(i, q) {
        if ( v[b[i]-1] == -1 ) {
            if ( v[a[i]-1] == -1 ) {
                v[b[i]-1] = 1+c[i];
            } else {
                v[b[i]-1] = v[a[i]-1]+c[i];
            }
            dd[b[i]-1] = d[i];
        } else {
            if ( dd[b[i]-1] < d[i] ) {
                if ( v[a[i]-1] == -1 ) {
                    v[b[i]-1] = 1+c[i];
                } else {
                    v[b[i]-1] = v[a[i]-1]+c[i];
                }
                dd[b[i]-1] = d[i];
            }
        }
    }

    ll ans = 0;
    rep(i, q) {
        if ( v[b[i]-1]-v[a[i]-1] == c[i] ) {
            ans += d[i];
        }
    }
    cout << ans << endl;

    /*
    vector<pair<ll, ll> > p;
    rep(i, q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        p.push_back( make_pair(i, d[i]));
    }

    sort(ALL(p), pair_Cs_R);

    ll ans = 0;
    std::vector< vector<pair<ll, ll> > > v(n);
    rep(i, q) {
        v[a[i]-1].push_back( make_pair(b[i]-1, c[i]) );
    }*/
    return 0;
}
