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

std::vector<std::vector<char>> simple(std::vector<std::vector<char>> a) {
    int64_t i = 0;
    while ( i < a.size() ) {
        int64_t alldot = 1;
        rep(j, a[i].size()) {
            if ( a[i][j] == '#' ) {
                alldot = 0;
                break;
            }
        }

        if (!alldot) ++i;
        else a.erase(a.begin()+i);
    }

    i = 0;
    while ( i < a[0].size() ) {
        int64_t alldot = 1;
        rep(j, a.size()) {
            if ( a[j][i] == '#' ) {
                alldot = 0;
                break;
            }
        }

        if (!alldot) ++i;
        else rep(j, a.size()) a[j].erase(a[j].begin()+i);
    }

    return a;
}

std::vector<std::vector<char>> rotate90 (std::vector<std::vector<char>> a) {
    vector2(res, a[0].size(), a.size());
    rep(i, a.size()) {
        rep(j, a[i].size()) {
            res[a[i].size()-1-j][i] = a[i][j];
        }
    }
    return res;
}

int64_t equal_shape (std::vector<std::vector<char>> a, std::vector<std::vector<char>> b ) {
    if ( a.size() == b.size()
        && a[0].size() == b[0].size() ) {
        rep(i, a.size()) {
            rep(j, a[0].size()) {
                if ( a[i][j] != b[i][j] ) {
                    return 0;
                }
            }
        }
        return 1;
    }
    return 0;
}

void print_s ( std::vector<std::vector<char>> a ) {
    rep(i, a.size()) {
        rep(j, a[i].size()) {
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    in1(n);
    if ( n == 1 ) {
        char s, t;
        cin >> s >> t;
        cout << ( (s == t && s == '#')? "Yes" : "No" ) << endl;
        return 0;
    }
    int64_t ss = 0, ts = 0;
    vector2(s, n, n);
    rep(i, s.size()) rep(j, s[i].size()) {
        cin >> s[i][j];
        if ( s[i][j] == '#' ) ++ss;
    }
    vector2(t, n, n);
    rep(i, t.size()) rep(j, t[i].size()) {
        cin >> t[i][j];
        if ( t[i][j] == '#' ) ++ts;
    }
    if ( ss != ts ) {
        cout << "No" << endl;
        return 0;
    }
    s = simple(s);
    t = simple(t);

    if ( equal_shape(s, t) ) {
        cout << "Yes" << endl;
        return 0;
    }
    std::vector<std::vector<char> > r = s;
    rep(i, 3) {
        std::vector<std::vector<char> > temp = r;
        r.resize( r[0].size(), std::vector<char>(r.size()) );
        r = rotate90(temp);
        if ( equal_shape(r, t) ) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
