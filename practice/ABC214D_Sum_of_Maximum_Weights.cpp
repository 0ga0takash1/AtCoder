#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<std::vector<int64_t> > Graph;

#define in1(n) int64_t n;cin >> n;
#define in2(n, m) int64_t n, m;cin >> n >> m;
#define in3(n, m, k) int64_t n, m, k;cin >> n >> m >> k;
#define in4(a, b, c, d) int64_t a, b, c, d;cin >> a >> b >> c >> d;
#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define repc(i, l, n, d) for (int64_t i = l; i < n; i+=d)
#define repc2(i, l, n, d) for (int64_t i = l; i <= n; i+=d)
#define rep_(i, r) for (int64_t i = r-1; i >= 0; --i)
#define rep_2(i, r) for (int64_t i = r; i > 0; --i)
#define rep_b(i, r, l) for (int64_t i = r; i >= l; --i)
#define rep_b2(i, r, l) for (int64_t i = r; i > l; --i)
#define rep_c(i, r, l, d) for (int64_t i = r; i >= l; i-=d)
#define rep_c2(i, r, l, d) for (int64_t i = r; i > l; i-=d)
#define repf(i, l, c, d) for (int64_t i = l; c; i+=d)
#define repi(a, b) for (auto&(a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define Sort_pair(x, p) sort(ALL(x), (p))
#define vector2(a, n, k) std::vector<std::vector<int64_t>> a(n, std::vector<int64_t>(k))
#define ctoi(c) ((c)-'0')

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0; }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }
template<typename map,typename T> bool find_map(map m, T num) { auto itr = m.find(num); if ( itr == m.end() ) { return false; } return true; }

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 1e9+7;

struct UnionFind {
    vector<int64_t> r;

    UnionFind(int64_t N) {
        r = vector<int64_t>(N, -1);
    }

    int64_t root(int64_t x) {
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }

    bool unite(int64_t x, int64_t y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x, y);
        r[x] += r[y];
        r[y] = x;
        return true;
    }

    int64_t size(int64_t x) {
        return -r[root(x)];
    }
};

bool tuple_Cf(const tuple<int64_t, int64_t, int64_t>& firstElof, const tuple<int64_t, int64_t, int64_t>& secondElof) {
    return get<0>(firstElof) < get<0>(secondElof);
}

int main() {
    in1(n);
    /*
    int64_t n = 10000;
    DIJKSTRA dks(n);
    std::vector<int64_t> u(n-1), v(n-1), w(n-1);
    rep(i, u.size()) {
        // cin >> u[i] >> v[i] >> w[i];
        // --u[i];--v[i];
        u[i] = i;v[i] = i+1;w[i] = i+1;
        dks.add(u[i], v[i], w[i]);
        dks.add(v[i], u[i], w[i]);
    }

    int64_t ans = 0;
    rep(i, n-1) {
        dks.dijkstra(i);
        repb(j, i+1, n) {
            ans += dks.d[j];
            // cout << i+1 << " " << j+1 << " " << dks.d[j] << endl;
        }
    }
    cout << ans << endl;
    */
    // std::vector<int64_t> u(n-1), v(n-1), w(n-1);
    std::vector< std::tuple<int64_t, int64_t, int64_t> > t(n-1);
    rep(i, t.size()) {
        int64_t u, v, w;
        cin >> u >> v >> w;
        --u;--v;
        t[i] = {w, u, v};
    }
    Sort(t);

    UnionFind uf(n);
    int64_t ans = 0;
    repi(e, t) {
        auto w = get<0>(e), u = get<1>(e), v = get<2>(e);
        ans += w*uf.size(u)*uf.size(v);
        uf.unite(u, v);
    }
    cout << ans << endl;
    return 0;
}
