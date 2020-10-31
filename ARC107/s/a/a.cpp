#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define repe(a, b) for (auto&(a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define mp(a, b) make_pair((a), (b))
#define Push_back(a, b) push_back( mp( (a), (b) ) )

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 998244353;

int main() {
    int64_t n, m, k;
    cin >> n >> m >> k;
    n%=MOD;m%=MOD;k%=MOD;
    /*
    int64_t ans = 0;
    rep2(i, n) {
        // rep2(j, m) {
        int64_t num = i%MOD;
        num *= m*
        num *= k*(k+1)/2;
        num %= MOD;
        ans += num;
        // }
    }
    ans %= MOD;*/
    // int64_t ans = ((n*(n+1))%MOD)*((m*(m+1))%MOD)*((k*(k+1))%MOD)/8;
    int64_t a = n*(n+1)/2;
    int64_t b = m*(m+1)/2;
    int64_t c = k*(k+1)/2;
    a%=MOD;b%=MOD;c%=MOD;
    int64_t ans = ((a*b)%MOD)*c;
    // ans += MOD;
    ans %= MOD;
    cout << ans << endl;

    return 0;
}
