#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define repc(i, l, n, d) for (int64_t i = l; i < n; i+=d)
#define repc2(i, l, n, d) for (int64_t i = l; i <= n; i+=d)
#define repi(a, b) for (auto&(a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define Sort_pair(x, p) sort(ALL(x), (p))
#define mp(a, b) make_pair((a), (b))
#define Push_back(a, b) push_back( mp( (a), (b) ) )
#define ctoi(c) (c)-'0'

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 1e9+7;

bool pair_Cs(const pair<string, int64_t>& firstElof, const pair<string, int64_t>& secondElof) {
    return firstElof.second < secondElof.second;
}

int64_t bfs ( Graph G, int64_t start_num ) {
    // std::vector<int64_t> seen(G.size(), 0);
    std::vector<int64_t> ans;
    queue<int64_t> q;
    // int64_t start_num = 0;
    q.push(start_num);
    while ( !q.empty() ) {
        int64_t num = q.front();
        // seen[num] = 1;
        q.pop();
        rep(i, G[num].size()) {
            if ( G[num].at(i) ) {
                int64_t see = i;
                if ( see == start_num ) {
                    G[num].at(i).second
                    break;
                }
                if ( seen[see] == 0 ) {
                    q.push(see);
                    seen[see] = 1;
                }
            }

        }
    }
    return *min_element(ALL(ans));
}

vector<int64_t> seen(INF, 0);
std::vector<int64_t> time_stack;
void dfs(Graph G, int v) {
    seen[v] = true;

    repe(i, G[v]) {
        if (seen[i]) continue;
        dfs(G, i);
    }
}

int main() {
    int64_t n, m;
    cin >> n >> m;
    std::vector<int64_t> a(m), b(m), c(m);
    std::vector< vector<pair<int64_t, int64_t>> > G(n);
    std::vector<std::vector<int64_t>> G(n, std::vector<int64_t>(n, 0));
    rep(i, m) {
        cin >> a[i] >> b[i] >> c[i];
        G[a[i]-1].at(b[i]-1) = c[i];
    }
    return 0;
}
