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

int main() {
    int64_t k;
    cin >> k;
    string s, t;
    cin >> s;
    cin >> t;
    int64_t s_point = 0, t_point = 0;
    std::vector<int64_t> ss(10, 0), tt(10, 0);
    rep(i, s.length()-1) {
        ++ss[ctoi(s[i])];
        ++tt[ctoi(t[i])];
    }
    repb2(i, 1, 9) {
        s_point += i*pow(10, ss[i]);
        t_point += i*pow(10, tt[i]);
    }

    if ( s_point > t_point ) {

    } else {

    }
    return 0;
}
