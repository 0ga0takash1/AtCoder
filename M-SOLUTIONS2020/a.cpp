#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define Push_back(p, a, b) (p).push_back( make_pair( (a), (b) ) )

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

int main() {
    int64_t n;
    cin >> n;
    int64_t ans = 0;
    if ( 400 <= n && n <= 599 ) {
        ans = 8;
    } else if ( 600 <= n && n <= 799 ) {
        ans = 7;
    } else if ( 800 <= n && n <= 999 ) {
        ans = 6;
    } else if ( 1000 <= n && n <= 1199 ) {
        ans = 5;
    } else if ( 1200 <= n && n <= 1399 ) {
        ans = 4;
    } else if ( 1400 <= n && n <= 1599 ) {
        ans = 3;
    } else if ( 1600 <= n && n <= 1799 ) {
        ans = 2;
    } else if ( 1800 <= n && n <= 1999 ) {
        ans = 1;
    }
    cout << ans << endl;
    return 0;
}
