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

int main() {
    in2(n, k);
    // int64_t n = 800, k = 400;
    int64_t ans = INF, mid = (k*k/2);
    std::vector<std::vector<int64_t>> a(n, std::vector<int64_t>(n));
    priority_queue<int64_t> q;
    rep(i, n) {
        rep(j, n) {
            cin >> a[i][j];
            // if ( (j%2) ) a[i][j] = 1e9;
            // else a[i][j] = 0;

            if ( q.size() <= mid ) {
                q.push(a[i][j]);
            } else {
                if ( q.top() > a[i][j] ) {
                    q.pop();
                    q.push(a[i][j]);
                }
            }
        }
    }

    rep(i, n-k+1) {
        rep(j, n-k+1) {
            std::vector<int64_t> v;
            rep(x, k) {
                rep(y, k) {
                    int64_t num = a[i+x][j+y];
                    v.push_back(num);
                }
            }
            Sort_rev(v);
            chmin(ans, v[mid]);
            if ( ans == q.top() ) {
                cout << ans << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
