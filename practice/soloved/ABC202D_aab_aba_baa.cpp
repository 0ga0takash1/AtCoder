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

int64_t nCr(int64_t n , int64_t r) {
    if ( n == r || n == 1 || r == 0 ) {
        return 1;
    }

    r = min(r, n-r);
    if ( r == 1 ) {
        return n;
    } else {
        std::vector<std::vector<int64_t> > v(n + 1,std::vector<int64_t>(n + 1, 0));
        for (int64_t i = 0; i < v.size(); i++) {
            v[i][0] = 1;
            v[i][i] = 1;
        }
        for (int j = 1; j < v.size(); j++) {
            for (int64_t k = 1; k < j; k++) {
                v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
            }
        }
        return v[n][r];
    }
}

int main() {
    in3(a, b, k);
/*
    if ( k == 1 ) {
        rep(i, a) cout << 'a';
        rep(i, b) cout << 'b';
        cout << endl;
        return 0;
    }
    int64_t last_num = 1, to_not_mul = min(a, b), d = to_not_mul;
    rep_b2(i, a+b, max(a, b)) {
        if ( to_not_mul == 1 ) {
            last_num *= i;
        } else {
            if ( i%to_not_mul == 0 ) {
                last_num *= i/to_not_mul;
                --to_not_mul;
            } else {
                last_num *= i;
            }
            while ( last_num%to_not_mul == 0 && to_not_mul != 1 ) {
                last_num /= to_not_mul;
                --to_not_mul;
            }
        }
    }

    if ( k == last_num ) {
        rep(i, b) cout << 'b';
        rep(i, a) cout << 'a';
        cout << endl;
        return 0;
    }

    int64_t div_num = (k+b-1)/b, div_rem_num = (k+b-1)%b;
    // div_num++;
    div_rem_num++;
    string ans, ans2;
    rep2(i, a) {
        if ( div_num>>i & 1 ) {
            ans += 'b';
        } else {
            ans += 'a';
        }
    }
    // reverse(ALL(ans));

    rep2(i, b) {
        if ( div_rem_num>>i & 1 ) {
            ans2 += 'b';
        } else {
            ans2 += 'a';
        }
    }
    reverse(ALL(ans2));
    cout << ans << ans2 << endl;
*/
    int64_t n = a+b;
    string ans = "";
    rep(i, n) {
        if ( 0 < a ) {
            if ( k <= nCr(a+b-1, b) ) {
                ans += 'a';
                --a;
            } else {
                ans += 'b';
                k -= nCr(a+b-1, b);
                --b;
            }
        } else {
            ans += 'b';
            --b;
        }
    }
    cout << ans << endl;
    return 0;
}
