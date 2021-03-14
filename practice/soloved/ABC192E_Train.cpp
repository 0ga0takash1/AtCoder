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

class DIJKSTRA {
    public:
        int64_t V;

        struct dk_edge {
            int64_t to;
            int64_t cost;
            int64_t start_time;
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

        void add(int64_t from, int64_t to, int64_t cost, int64_t start_time) {
            dk_edge e = {to, cost, start_time};
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
                    int64_t start = d[v]%e.start_time;
                    if (start) start = e.start_time-start;
                    if (d[e.to] > d[v]+e.cost+start) {
                        d[e.to] = d[v]+e.cost+start;
                        prev[e.to] = v;
                        que.push(PI(d[e.to], e.to));
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
    int64_t n, m, x, y;
    cin >> n >> m >> x >> y;
    if (!m) {
        cout << -1 << endl;
        return 0;
    }
    --x;--y;
    std::vector<int64_t> a(m), b(m), t(m), k(m);
    DIJKSTRA dks(n);
    rep(i, m) {
        cin >> a[i] >> b[i] >> t[i] >> k[i];
        dks.add(a[i]-1, b[i]-1, t[i], k[i]);
        dks.add(b[i]-1, a[i]-1, t[i], k[i]);
    }
    dks.dijkstra(x);
    int64_t ans = dks.d[y];
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
