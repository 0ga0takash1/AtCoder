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

bool pair_Cf(const pair<int64_t, int64_t>& firstElof, const pair<int64_t, int64_t>& secondElof) {
    return firstElof.first < secondElof.first;
}

bool pair_Cf_R(const pair<int64_t, int64_t>& firstElof, const pair<int64_t, int64_t>& secondElof) {
    return firstElof.first > secondElof.first;
}

int main() {
    in3(h, w, n);
    std::vector<int64_t> a(n), b(n);
/*
    vector2(grid, h, w);
    rep(i, a.size()) {
        cin >> a[i] >> b[i];
        --a[i];--b[i];
        grid[a[i]][b[i]] = i+1;
    }
    rep(i, grid.size()) {
        int64_t judge = 0;
        rep(j, grid[i].size()) {
            if ( grid[i][j] != '*' ) {
                judge = 1;
                break;
            }
        }
        if (judge) grid.erase(grid.begin()+i);
    }

    rep(i, grid[0].size()) {
        int64_t judge = 0;
        rep(j, grid.size()) {
            if ( grid[j][i] != '*' ) {
                judge = 1;
                break;
            }
        }
        if (judge) {
            rep(j, grid.size()) {
                grid[j].erase(grid[j].begin()+i);
            }
        }
    }

    rep(i, grid.size()) {
        rep(j, grid[i].size()) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    */
    vector<pair<int64_t, int64_t> > x, y, ans(n);
    unordered_set<int64_t> xx, yy;
    rep(i, a.size()) {
        cin >> a[i] >> b[i];
        x.push_back({a[i], i});
        xx.insert(a[i]);
        y.push_back({b[i], i});
        yy.insert(b[i]);
    }
    std::vector<int64_t> x2, y2;
    repi(i, xx) x2.push_back(i);
    repi(i, yy) y2.push_back(i);
    Sort_pair(x, pair_Cf);
    Sort_pair(y, pair_Cf);
    Sort(x2);
    Sort(y2);

    int64_t xi = 0, yi = 0;
    /*
    auto& xitr = xx.begin()+1, yitr = xx.begin()+1;
    rep(i, x.size()) {
        while ( xitr != x[i].second ) {
            xitr++;
            xi++;
        }
        ans[x[i].second].first = xi;
    }
    rep(i, y.size()) {
        while ( yitr != y[i].second ) {
            yitr++;
            yi++;
        }
        ans[y[i].second].second = yi;
    }
    */
    repi(a, x2) {
        repb(i, xi, n) {
            if ( a == x[i].first ) {
                ans[x[i].second].first = xi+1;
            } else {
                xi++;
                break;
            }
        }
    }

    repi(a, y2) {
        repb(i, yi, n) {
            if ( a == y[i].first ) {
                ans[y[i].second].second = yi+1;
            } else {
                yi++;
                break;
            }
        }
    }

    repi(i, ans) cout << i.first << " " << i.second << endl;
    return 0;
}
