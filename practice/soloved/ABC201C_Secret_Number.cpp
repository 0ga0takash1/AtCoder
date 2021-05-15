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

int main() {
    string s;
    cin >> s;
    int64_t ans = 0;
    rep(i, 10000) {
        int64_t n = i;
        std::vector<int64_t> v(10, 0);
        rep2(j, 4) {
            ++v[n%10];
            n /= 10;
        }

        int64_t flag = 1;
        rep(j, 10) {
            if ( s[j] == 'o' && !v[j] ) {
                flag = 0;
                break;
            }

            if ( s[j] == 'x' && v[j] ) {
                flag = 0;
                break;
            }
        }
        ans += flag;
    }
    cout << ans << endl;
/*
    std::vector<int64_t> include, exclude, unknown;
    rep(i, s.size()) {
        if ( s[i] == 'o' ) {
            include.push_back(i);
        } else if ( s[i] == 'x' ) {
            exclude.push_back(i);
        } else if ( s[i] == '?' ) {
            unknown.push_back(i);
        }

        if ( include.size() > 4 || exclude.size() == 10 ) {
            cout << 0 << endl;
            return 0;
        }
    }

    int64_t ans;
    if ( include.size() == 4 ) {
        ans = 24;
    } else if ( include.size() == 3 ) {
        ans = 36;
        ans += unknown.size()*24;
    } else if ( include.size() == 2 ) {
        ans = 20;
        ans += unknown.size()*48;
        ans += 24*unknown.size()*(unknown.size()-1);
    } else if ( include.size() == 1 ) {
        ans = pow(include.size()+unknown.size(), 4);
        ans -= pow(unknown.size(), 4);
    }
    cout << ans << endl;
*/
    return 0;
}
