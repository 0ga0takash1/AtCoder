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
    int64_t n, m;
    cin >> n >> m;
    Graph G(n);
    std::vector<int64_t> a(m), b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        do_look[a[i]] = 1;
        do_look[b[i]] = 1;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    std::vector<int64_t> v;
    int64_t sum = 0;
    rep(i, n) {
        if ( do_look[i] == 1 ) {
            int64_t num = bfs(G, i);
            sum += num;
            v.push_back( num );
            if (num >= n/2 || sum >= n/2) break;
        }
    }

    if (v.empty()) v.push_back(n);
    cout << *max_element(ALL(v)) << endl;
    return 0;
}
