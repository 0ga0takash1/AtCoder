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

int main() {
    ll n, m;
    cin >> n >> m;

    std::vector<std::vector<ll> > G(n);
    ll a[n];
    rep(i, n) {
        cin >> a[i];
        G[i].push_back(a[i]-1);
    }

    ll ans = 0;
    std::vector<ll> v(n, 0);
    v[0]++;
    ll loop = 0;
    std::vector<ll> l;
    rep(i, m) {
        ans = G[ans][0];
        v[ans]++;
        if ( v[ans] > 2 || loop ) {
            loop = 1;
            if ( v[ans] > 3 ) {
                m -= i+1;
                break;
            }
            l.push_back(ans);
        }
    }

    if ( loop ) {
        /*
        cout << "Yes";
        rep(i, l.size()) {
            cout << l[i] << " ";
        }
        cout << endl;*/
        cout << l[m%l.size()]+1 << endl;
    } else {
        cout << ans+1 << endl;
    }
    return 0;
}
