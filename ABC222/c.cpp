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
#define vector2(a, n, k) std::vector<std::vector<char>> a(n, std::vector<char>(k))
#define ctoi(c) ((c)-'0')

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0; }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }
template<typename map,typename T> bool find_map(map m, T num) { auto itr = m.find(num); if ( itr == m.end() ) { return false; } return true; }

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 1e9+7;

bool pcs_r(const pair<int64_t, int64_t>& firstElof, const pair<int64_t, int64_t>& secondElof) {
    return firstElof.second > secondElof.second;
}

bool my_c(pair<int64_t, int64_t> a, pair<int64_t, int64_t> b) {
    // まずsecond
    if ( a.second != b.second ) return a.second > b.second;

    // secondが同じときはfirst
    if ( a.first != b.first ) return a.first < b.first;
    else return true;
}

// 1 == a win, 0 == a lose, -1 == drow
int64_t gcp(char a, char b) {
    if ( a == 'G' ) {
        if ( b == 'C' ) {
            return 1;
        } else if ( b == 'P' ) {
            return 0;
        }
    } else if ( a == 'C' ) {
        if ( b == 'P' ) {
            return 1;
        } else if ( b == 'G' ) {
            return 0;
        }
    } else if ( a == 'P' ) {
        if ( b == 'G' ) {
            return 1;
        } else if ( b == 'C' ) {
            return 0;
        }
    }
    return -1;
}

int main() {
    in2(n, m);
    vector<pair<int64_t, int64_t> > p(2*n);
    rep(i, p.size()) p[i] = {i, 0}; // num, win
    vector2(a, 2*n, m);
    rep(i, a.size()) rep(j, a[i].size()) {
        cin >> a[i][j];
    }

    rep(i, m) {
        repc(j, 0, p.size()-1, 2) {
            int64_t result = gcp(a[p[j].first][i], a[p[j+1].first][i]);
            if ( result == 1 ) {
                p[j].second++;
            } else if ( result == 0 ) {
                p[j+1].second++;
            }
        }
        // Sort(p);
        Sort_pair(p, my_c);
        // repi(i, p) {
        //     cout << i.first << " " << i.second << endl;
        // }
        // cout << endl;
    }

    rep(i, p.size()) {
        cout << p[i].first+1 << endl;
    }
    return 0;
}
