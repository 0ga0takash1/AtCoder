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

int main() {
    in2(n, m);
    std::vector<int64_t> k(m);
    Graph a(m);
    rep(i, k.size()) {
        cin >> k[i];
        rep(j, k[i]) {
            in1(num);
            a[i].push_back(num);
        }
    }
    int64_t empty = 0;
    while ( empty != m ) {
        vector<pair<int64_t, int64_t> > top;
        rep(i, a.size()) {
            top.push_back({a[i][0], i});
        }
        Sort(top);
        int64_t i = 0, can = 0;
        std::vector<int64_t> rm;
        while ( i < top.size()-1 ) {
            if ( top[i].first == top[i+1].first ) {
                can = 1;
                a[top[i].second].erase(a[top[i].second].begin());
                if ( a[top[i].second].size() == 0 ) {
                    ++empty;
                    rm.push_back(top[i].second);
                }
                a[top[i+1].second].erase(a[top[i+1].second].begin());
                if ( a[top[i+1].second].size() == 0 ) {
                    ++empty;
                    rm.push_back(top[i].second);
                }
                ++i;
            }
            ++i;
        }
        if (!can) {
            cout << "No" << endl;
            return 0;
        }
        repi(j, rm) {
            a.erase(a.begin()+j);
        }
    }
    cout << "Yes" << endl;

    return 0;
}
