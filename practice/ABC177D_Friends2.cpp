/*---------------------------------------------*/
/*
    ABC177 D
 */
/*---------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define Push_back(p, a, b) (p).push_back( make_pair( (a), (b) ) )

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }
const int64_t INF = 0x3fffffffffffffff;

std::vector<int64_t> do_look(200000, 0);

int64_t bfs ( Graph G , int64_t start_num ) {
    std::vector<int64_t> seen(G.size(), 0);
    queue<int64_t> q;
    q.push(start_num);
    int64_t ans = 1;
    while ( !q.empty() ) {
        int64_t num = q.front();
        seen[num] = 1;
        q.pop();
        rep(i, G[num].size()) {
            int64_t see = G[num].at(i);
            if ( seen[see] == 0 ) {
                q.push(see);
                seen[see] = 1;
                do_look[see] = 0;
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    ll n, m, a, b;
    cin >> n >> m;
    Graph g(n);
    std::vector<int> vis(n,0);
    rep(i, m) {
        cin >> a >> b;
        --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans=0, cnt;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        vis[i]=1, cnt=0;
        q.push(i);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cnt++;
            for (auto&(v) : (g[u])) {
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
        chmax(ans,cnt);
    }

    cout << ans << endl;
    return 0;
}
