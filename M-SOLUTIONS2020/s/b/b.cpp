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
    int64_t a, b, c;
    cin >> a >> b >> c;
    int64_t k;
    cin >> k;

    int64_t ans = 0;
    int64_t bb = b;
    int64_t cc = c;

    rep(i, k) {
        if ( bb <= a ) {
            bb *= 2;
        } else {
            cc *= 2;
        }
    }

    if ( a < bb && bb < cc ) {
        ans = 1;
    }
    cout << ( ans ? "Yes" : "No" ) << endl;
    return 0;
}
