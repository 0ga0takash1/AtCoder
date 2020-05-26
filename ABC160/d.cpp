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

/*
class Graph {
    std::vector<std::vector<ll> > graph;
    std::vector<int> seen;

    seen(n) {
        rep(i, n) {
            seen
        }
    }
}
*/
std::vector<int> seen;

ll dfs ( Graph G, ll num, ll remain_num) {
    seen[num] = 1;
    ll ans = 0;
/*
    rep(i, G[num].size()) {
        seen[G[num].at(i)] = 1;
    }
    rep(i, G.size()) {
        cout << "seen ";
        cout << i << " " << seen[i] << endl;
    }
    cout << endl;*/
    // cout << "remain " << remain_num << endl;
    if ( remain_num <= 1 ) {

        rep(i, G[num].size()) {
            if ( !seen[G[num].at(i)] ) {
                seen[G[num].at(i)] = 1;
                ans++;
            }
        }
        // cout << "one" << endl;
        // ans = G[num].size()-1;
        return ans;
    } else {

        int ever = 1;
        rep(i, G[num].size()) {
            if ( !seen[G[num].at(i)] ) {
                ever = 0;
            }
        }
        if ( ever ) {
            // cout << "ever" << endl;
            return 0;
        }

        if ( (num == 1 || num == G.size()-1) && G[num].size() == 1 ) {
            // cout << "stop" << endl;
            return 0;
        } else {
            remain_num--;
            rep(i, G[num].size()) {
                if ( /*!seen[G[num].at(i)]*/ i != num ) {
                    ans += dfs(G, G[num].at(i), remain_num);
                }
            }
            // cout << "remain " << remain_num << endl;
            // cout << "a " << ans << endl;
            return ans;
        }
    }
}

// std::vector<ll> see;
// queue<ll> q;
ll bfs( Graph G, ll num, ll remain_num, std::vector<ll> see, std::vector<std::vector<ll> > s) {
    if ( find(ALL(see), num) == see.end() ) {
        see.push_back(num);
        rep(i, G[num].size()) {
            if ( find(ALL(see), G[num].at(i)) == see.end() ) {
                s[remain_num-1].push_back(G[num].at(i));
                see.push_back(G[num].at(i));
            }
        }
        ll ans = s[0].size();
        return ans;
    }
    return 0;
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
    // seen.assign(n, 0);
    rep2(i, n-1) {
        if ( i == 1 ) {
            cout << n << endl;
        } else if ( i == n-1 ) {
            cout << 0 << endl;
        } else {
            ans = 0;
            std::vector<std::vector<ll> > search(i);
            rep(j, n) {
                for (ll k = i; k > 0; --k) {
                    std::vector<ll> see;
                    ans += bfs(G, j, k, see, search);
                }
            }
            cout << ans << endl;
/*
            rep(j, n) {
                rep(k, seen.size()) {
                    seen[k] = 0;
                }
                ll aa = dfs(G, j, i);
                // cout << "aa " << aa << endl;
                ans += aa;
            }
            // cout << "a " << ans << endl;
            cout << ans/2 << endl;
*/
        }
    }

    return 0;
}
