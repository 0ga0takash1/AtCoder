/*---------------------------------------------*/
/*
    ABC160 D
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

// π M_PI
// deg = rad*180/M_PI

typedef std::vector< std::vector<ll> > Graph;

template<typename V,typename T>
T find_num(V v, T num) {
    if ( find(ALL(v), num) == v.end() ) {
        return false;
    } else {
        return true;
    }
}

ll bfs( Graph G, ll num, ll remain_num ) {
    std::vector<ll> see;
    see.push_back(num);
    std::vector<std::vector<ll> > search(remain_num);

    ll keep = see.size();
    rep(i, G[num].size()) {
        see.push_back(G[num].at(i));
        search[remain_num-1].push_back(G[num].at(i));
    }

    for (ll i = remain_num-1; i > 0; --i) {
        ll j = keep;
        keep = see.size();
        while (j < keep) {
            rep(k, G[see[j]].size()) {
                ll search_num = G[see[j]].at(k);
                if ( !find_num(see, G[see[j]].at(k)) ) {
                    see.push_back(search_num);
                    search[i-1].push_back(search_num);
                }
            }
            j++;
        }
    }

    ll ans = search[0].size();

    return ans;
}

int main() {
    ll n, x, y;
    cin >> n >> x >> y;
    --x;--y;
    Graph G(n);
    rep(i, n) {
        if ( i == 0 ) {
            G[i].push_back(i+1);
        } else if ( i == n-1 ) {
            G[i].push_back(i-1);
        } else {
            G[i].push_back(i-1);
            G[i].push_back(i+1);
        }
    }
    G[x].push_back(y);
    G[y].push_back(x);

    ll ans;
    rep2(i, n-1) {
        if ( i == 1 ) {
            cout << n << endl;
        } else if ( i == n-1 ) {
            cout << 0 << endl;
        } else {
            ans = 0;
            rep(j, n) {
                ans += bfs(G, j, i);
            }
            cout << ans/2 << endl;
        }
    }

    return 0;
}
