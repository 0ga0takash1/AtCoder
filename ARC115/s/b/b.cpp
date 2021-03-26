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
#define rep_(i, r) for (int64_t i = r; i > 0; --i)
#define rep_2(i, r) for (int64_t i = r; i >= 0; --i)
#define rep_b(i, r, l) for (int64_t i = r; i > l; --i)
#define rep_b2(i, r, l) for (int64_t i = r; i >= l; --i)
#define rep_c(i, r, l, d) for (int64_t i = r; i > l; i-=d)
#define rep_c2(i, r, l, d) for (int64_t i = r; i >= l; i-=d)
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
    int64_t n;
    cin >> n;
    std::vector<std::vector<int64_t>> c(n, std::vector<int64_t>(n));
    rep(i, n) rep(j, n) cin >> c[i][j];

    std::vector<int64_t> a(n), b(n);
    rep(i, n) {
        rep(j, n) {
            a[j] = -1;
            b[j] = -1;
        }
        int64_t flag = 1;
        a[i] = 0;
        rep(j, n) b[j] = c[i][j]-a[i];
        rep(j, n) {
            if ( i != j ) {
                rep(k, n) {
                    if ( a[j] == -1 ) {
                        if ( c[j][k]-b[k] >= 0 ) {
                            a[j] = c[j][k]-b[k];
                        } else {
                            flag = 0;
                            break;
                        }
                    } else {
                        if ( a[j] != c[j][k]-b[k] ) {
                            flag = 0;
                            break;
                        }
                    }
                }
                if (!flag) break;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
            rep(j, n) cout << a[j] << " ";
            cout << endl;
            rep(j, n) cout << b[j] << " ";
            cout << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
