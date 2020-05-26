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
    ll a[m], b[m];
    std::vector<std::vector<ll> > G(n);
    ll flag = 0;
    rep(i, m) {
        cin >> a[i] >> b[i];
        if ( (a[i] == 1 || b[i] == 1) && !flag ) {
            flag = 1;
        }
        G[a[i]-1].push_back(b[i]-1);
        G[b[i]-1].push_back(a[i]-1);
    }

    if ( !flag ) {
        cout << "No" << endl;
        return 0;
    }

    std::vector<ll> v(n);
    std::vector<ll> seen(n, 0);
    queue<ll> q;
    q.push(0);
    while ( !q.empty() ) {
        ll num = q.front();
        seen[num] = 1;
        q.pop();
        rep(i, G[num].size()) {
            ll see = G[num].at(i);
            if ( seen[see] == 0 ) {
                q.push(see);
                seen[see] = 1;
                v[see] = num+1;
            }
        }
    }

    cout << "Yes" << endl;
    rep2(i, n-1) {
        cout << v[i] << endl;
    }
    return 0;
}
