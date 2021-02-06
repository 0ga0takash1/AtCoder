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
    int64_t h, w;
    cin >> h >> w;
    std::vector<std::vector<char>> s(h, std::vector<char>(w));
    rep(i, h) {
        rep(j, w) {
            cin >> s[i][j];
        }
    }
    int64_t ans = 0;
    rep(i, h) {
        rep(j, w) {
            if ( s[i][j] == '#' ) {
                int num4 = 0;
                if ( i-1 >= 0 && s[i-1][j] == '#' ) num4++;
                if ( i+1 <= w-1 && s[i+1][j] == '#' ) num4++;
                if ( j-1 >= 0 && s[i][j-1] == '#' ) num4++;
                if ( j+1 <= h-1 && s[i][j+1] == '#' ) num4++;

                if ( num4 <= 2 ) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
