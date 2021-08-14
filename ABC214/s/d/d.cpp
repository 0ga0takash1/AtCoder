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

class DIJKSTRA {
    public:
        int64_t S;

        struct dk_edge {
            int64_t to;
            int64_t cost;
        };

        typedef pair<int64_t, int64_t> PI;  // firstは最短距離、secondは頂点の番号
        vector<vector<dk_edge>> G;
        vector<int64_t> d;      //これ答え。d[i]:=S[i]までの最短距離
        vector<int64_t> prev;  //経路復元

        DIJKSTRA(int64_t size) {
            S = size;
            G = vector<vector<dk_edge>>(S);
            prev = vector<int64_t>(S, -1);
        }

        void add(int64_t from, int64_t to, int64_t cost) {
            dk_edge e = {to, cost};
            G[from].push_back(e);
        }

        void dijkstra(int64_t s) {
            // greater<P>を指定することでfirstが小さい順に取り出せるようにする
            priority_queue<PI, vector<PI>, greater<PI>> que;
            d = vector<int64_t>(S, -1);
            d[s] = 0;
            que.push(PI(0, s));

            while (!que.empty()) {
                PI p = que.top();
                que.pop();
                int64_t now = p.second;
                if (d[now] < p.first) continue;
                rep(i, G[now].size()) {
                    dk_edge e = G[now][i];
                    /*
                    if (d[e.to] > d[now] + e.cost) {
                        d[e.to] = d[now] + e.cost;
                        prev[e.to] = now;
                        que.push(PI(d[e.to], e.to));
                    }
                    */
                    if ( d[e.to] == -1 ) {
                        d[e.to] = max(d[now], e.cost);
                        prev[e.to] = now;
                        que.push(PI(d[e.to], e.to));
                    }
                    /* else {
                        chmax(d[e.to], max(d[now], e.cost));
                    }*/
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
    in1(n);
    DIJKSTRA dks(n);
    std::vector<int64_t> u(n-1), v(n-1), w(n-1);
    rep(i, u.size()) {
        cin >> u[i] >> v[i] >> w[i];
        --u[i];--v[i];
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
    return 0;
}
