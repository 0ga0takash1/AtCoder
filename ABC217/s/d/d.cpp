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

int64_t Bs (int64_t x, vector<int64_t> v) {
    int64_t ok = 0, ng = v.size();
    while ( ok+1 < ng ) {
        int64_t num = (ok+ng)/2;
        if ( v[num] < x ) ok = num;
        else ng = num;
    }
    return ok;
}

int main() {
    in2(l, q);
    std::vector<int64_t> wood;
    wood.push_back(0);
    wood.push_back(l);
    std::vector<int64_t> c(q), x(q);
    rep(i, c.size()) {
        cin >> c[i] >> x[i];
        if ( c[i] == 1 ) {
            wood.push_back(x[i]);
        } else {
            if ( c[i-1] != c[i] ) Sort(wood);
            // int64_t num = Bs(x[i], wood);
            // int64_t num = (ALL(wood), x[i]);
            auto position = lower_bound(ALL(wood), x[i]);  // 3 を二分探索
            int64_t num = distance(wood.begin(), position);
            cout << wood[num+1]-wood[num] << endl;
            // repb(j, 1, wood.size()) {
            //     if ( x[i] < wood[j] ) {
            //         cout << wood[j]-wood[j-1] << endl;
            //         break;
            //     }
            // }
        }
    }
    return 0;
}
