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

ll func(std::vector<ll> R, std::vector<ll> G, std::vector<ll> B ) {
    ll ans = 0;
    rep(i, R.size()) {
        rep(j, G.size()) {
            rep(k, B.size()) {
                ll I = min(R[i], min(G[j], B[k]));
                ll K = max(R[i], max(G[j], B[k]));
                ll J = R[i]+G[j]+B[k]-I-K;
                if ( 2*J != I+K ) {
                    ans++;
                }
            }
        }
    }
    return ans;
}

ll func2( std::vector<ll> R, std::vector<ll> G, std::vector<ll> B ) {
    ll ans = 0;

    if ( B.empty() ) return 0;

    rep(i, R.size()) {
        rep(j, G.size()) {
            ll num = abs(R[i]-G[j])+max(R[i], G[j]);
            // if ( num > n ) break;
            if ( num > B.at(B.size()-1) ) continue;

            if ( find_num(B, num) ) {
                // cout << "num " << num << endl;
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    std::vector<ll> R, G, B;
    rep(i, s.length()) {
        if ( s[i] == 'R' ) {
            R.push_back(i+1);
            // cout << "r " << i+1 << endl;
        } else if ( s[i] == 'G' ) {
            G.push_back(i+1);
            // cout << "g " << i+1 << endl;
        } else {
            B.push_back(i+1);
            // cout << "b " << i+1 << endl;
        }
    }
    ll ans = 0;
    // ans += func(R, G, B);

    ans += R.size()*G.size()*B.size();
    ans -= func2(R, G, B);
    ans -= func2(R, B, G);
    ans -= func2(G, B, R);

    cout << ans << endl;
    return 0;
}
