#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define repc(i, l, n, d) for (int64_t i = l; i < n; i+=d)
#define repc2(i, l, n, d) for (int64_t i = l; i <= n; i+=d)
#define repe(a, b) for (auto&(a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
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
    long double a, b, c;
    cin >> a >> b >> c;
    long double a2, b2, c2;
    a2=100-a;b2=100-b;c2=100-c;

    long double ans = 0;
    // ans += a2*(a/(a+b+c));
    // cout << setprecision(10) << ans << endl;
    // ans += b2*(b/(a+b+c));
    // cout << setprecision(10) << ans << endl;
    // ans += c2*(c/(a+b+c));
    ans = (a*a2+b*b2+c*c2)/(a+b+c);

    // rep2(i, a2) ans += (a+i)/(a+i+b+c);
    // rep2(i, b2) ans += (b+i)/(a+i+b+c);
    // rep2(i, c2) ans += (c+i)/(a+i+b+c);

    cout << setprecision(10) << ans << endl;
    // cout << (a2+b2+c2)/3 << endl;
    return 0;
}
