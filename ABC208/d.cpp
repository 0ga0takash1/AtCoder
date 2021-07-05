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
#define mp(a, b) make_pair((a), (b))
#define Push_back(a, b) push_back( mp( (a), (b) ) )
#define ctoi(c) ((c)-'0')
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }
const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 1e9+7;

class DIJKSTRA {
    public:
        int64_t V;

        struct dk_edge {
            int64_t to;
            int64_t cost;
        };

        typedef pair<int64_t, int64_t> PI;  // firstは最短距離、secondは頂点の番号
        vector<vector<dk_edge>> G;
        vector<int64_t> d;      //これ答え。d[i]:=V[i]までの最短距離
        vector<int64_t> prev;  //経路復元

        DIJKSTRA(int64_t size) {
            V = size;
            G = vector<vector<dk_edge>>(V);
            prev = vector<int64_t>(V, -1);
        }

        void add(int64_t from, int64_t to, int64_t cost) {
            dk_edge e = {to, cost};
            G[from].push_back(e);
        }

        void dijkstra(int64_t s) {
            // greater<P>を指定することでfirstが小さい順に取り出せるようにする
            priority_queue<PI, vector<PI>, greater<PI>> que;
            d = vector<int64_t>(V, INF);
            d[s] = 0;
            que.push(PI(0, s));

            while (!que.empty()) {
                PI p = que.top();
                que.pop();
                int64_t v = p.second;
                if (d[v] < p.first) continue;
                rep(i, G[v].size()) {
                    dk_edge e = G[v][i];
                    if (d[e.to] > d[v] + e.cost) {
                        d[e.to] = d[v] + e.cost;
                        prev[e.to] = v;
                        que.push(PI(d[e.to], e.to));
                    }
                }
            }
        }

        void dijkstra2(int64_t s, int64_t t, int64_t k) {
            // greater<P>を指定することでfirstが小さい順に取り出せるようにする
            priority_queue<PI, vector<PI>, greater<PI>> que;
            d = vector<int64_t>(V, INF);
            d[s] = 0;
            que.push(PI(0, s));

            while (!que.empty()) {
                PI p = que.top();
                que.pop();
                int64_t v = p.second;
                if (d[v] < p.first) continue;
                rep(i, G[v].size()) {
                    dk_edge e = G[v][i];
                    if ( e.to <= k || e.to == s || e.to == t ) {
                        if (d[e.to] > d[v] + e.cost ) {
                            d[e.to] = d[v] + e.cost;
                            prev[e.to] = v;
                            que.push(PI(d[e.to], e.to));
                        }
                    }
                }
            }
        }

        vector<int64_t> get_path(int64_t t) {
            vector<int64_t> path;
            for (; t != -1; t = prev[t]) {
                // tがsになるまでprev[t]をたどっていく
                path.push_back(t);
            }
            //このままだとt->sの順になっているので逆順にする
            reverse(path.begin(), path.end());
            return path;
        }

        void show(void) {
            for (int i = 0; i < d.size(); i++) cout << d[i] << " ";
            cout << endl;
        }
};

int main() {
    in2(n, m);
    DIJKSTRA dks(n);
    std::vector<int64_t> a(m), b(m), c(m);
    rep(i, a.size()) {
        cin >> a[i] >> b[i] >> c[i];
        --a[i];--b[i];
        dks.add(a[i], b[i], c[i]);
    }

    int64_t ans = 0;
    rep(i, n) {
        rep(j, n) {
            if ( i == j ) break;
            rep(k, n) {
                dks.dijkstra2(i, j, k);
                if ( dks.d[j] != INF ) {
                    cout << i << " " << j << " " << k << " " << dks.d[j] << endl;
                    ans += dks.d[j];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
