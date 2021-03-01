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
#define ctoi(c) (c)-'0'

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 1e9+7;

int64_t compare_st (string s, string t) {
    int64_t s_point = 0, t_point = 0;
    std::vector<int64_t> ss(10, 0), tt(10, 0);
    rep(i, s.length()) {
        ++ss[ctoi(s[i])];
        ++tt[ctoi(t[i])];
    }
    repb2(k, 1, 9) {
        s_point += k*pow(10, ss[k]);
        t_point += k*pow(10, tt[k]);
    }
    if ( s_point > t_point ) return 1;
    return 0;
}

int main() {
    int64_t k;
    cin >> k;

    string s, t;
    cin >> s;
    cin >> t;
    std::vector<int64_t> v(11, 0);
    rep(i, 4) {
        v[ctoi(s[i])]++;
        v[ctoi(t[i])]++;
    }

    vector<int64_t> remain;
    rep2(i, 9) {
        rep(j, k-v[i]) remain.push_back(i);
    }
    int64_t ans = 0;
    std::vector<std::vector<int64_t>> what_win(10, std::vector<int64_t>(10, 0));
    rep2(i, 9) {
        rep2(j, 9) {
            string s2 = s, t2 = t;
            s2[4] = '0'+i;
            t2[4] = '0'+j;
            what_win[i][j] = compare_st(s2, t2);
        }
    }

    rep(i, 9*k-9) {
        repb(j, i+1, 9*k-8) {
            if ( what_win[remain[i]][remain[j]] ) ++ans;
        }
    }

    ans /= (9*k-8)*(9*k-9);
    cout << ans << endl;
    return 0;
}
