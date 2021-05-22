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

int64_t gcd(int64_t a, int64_t b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    in3(a, b, k);
    if ( k == 1 ) {
        rep(i, a) cout << 'a';
        rep(i, b) cout << 'b';
        cout << endl;
        return 0;
    }
    int64_t last_num = 1, to_not_mul = min(a, b), d = to_not_mul;
    rep_b2(i, a+b, max(a, b)) {
        if ( to_not_mul == 1 ) {
            // cout << "a" << endl;
            last_num *= i;
        } else {
            if ( i%to_not_mul == 0 ) {
                // cout << "b" << endl;
                last_num *= i/to_not_mul;
                --to_not_mul;
            } else {
                // cout << "c" << endl;
                last_num *= i;
            }
            while ( last_num%to_not_mul == 0 && to_not_mul != 1 ) {
                last_num /= to_not_mul;
                --to_not_mul;
            }
        }
        // cout << last_num << " " << i << " " << to_not_mul << endl;
/*
        if ( to_not_mul == 1 ) {
            last_num *= i;
        } else {
            if ( i%to_not_mul == 0 ) {
                last_num *= i/to_not_mul;
                --to_not_mul;
            } else {
                if ( gcd(i, to_not_mul) != 1 ) {
                    last_num *= i/gcd(i, to_not_mul);
                } else {

                }
                d *= to_not_mul/gcd(i, to_not_mul);
                --to_not_mul;
                last_num *= i;
            }
            while ( last_num%to_not_mul == 0 && to_not_mul != 1 ) {
                last_num /= to_not_mul;
                --to_not_mul;
            }
        }
        */
    }

    if ( k == last_num ) {
        rep(i, b) cout << 'b';
        rep(i, a) cout << 'a';
        cout << endl;
        return 0;
    }

    int64_t div_num = (a+b+1)/(k-1), div_rem_num = k%b;
    div_num++;
    div_rem_num++;
    string ans, ans2;
    rep2(i, a) {
        if ( div_num>>i & 1 ) {
            // cout << 'b';
            ans += 'b';
        } else {
            ans += 'a';
            // cout << 'a';
        }
    }
    // reverse(ALL(ans));

    rep2(i, b) {
        if ( div_num>>i & 1 ) {
            ans2 += 'b';
        } else {
            ans2 += 'a';
        }
    }
    reverse(ALL(ans2));
    // cout << endl;
    cout << ans << ans2 << endl;
    return 0;
}
