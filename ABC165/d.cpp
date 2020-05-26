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

ll num( ll a, ll b, ll i ) {
    ll ans = (int)(a*i/b)-a*(int)(i/b);
    return ans;
}

int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    ll ans = 0;
    if ( n < b ) {
        ans = num(a, b, n);
    } else {
        ll nn = b;
        ll i = 2;
        priority_queue<ll> q;
        while (nn <= n) {
            ll k = num(a, b, nn-1);
            if ( !q.empty() && k < q.top() ) {
                break;
            }
            q.push(k);
            q.push( num(a, b, nn) );
            nn = b*i;
            i++;
        }
        ans = q.top();
    }

    cout << ans << endl;
    return 0;
}
