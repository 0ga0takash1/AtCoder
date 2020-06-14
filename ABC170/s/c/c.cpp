#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define Push_back(p, a, b) (p).push_back( make_pair( (a), (b) ) )

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

// π M_PI
// deg = rad*180/M_PI

int main() {
    int64_t x, n;
    cin >> x >> n;

    std::vector<int64_t> a(n);
    int64_t xx = 0;
    rep(i, n) {
        cin >> a[i];
        if ( a[i] == x ) {
            xx = 1;
        }
    }

    if ( n == 0 || !xx ) {
        cout << x << endl;
        return 0;
    }

    /*
    int64_t ans;
    int64_t num = 200;
    rep2(i, 200) {
        chmin(num, abs(x-i) );
        ans = i;
    }
    cout << ans << endl;*/
    int64_t ans = 0;
    rep2(i, max(x, 100-x)) {
        if ( !find_num(a, x-i) ) {
            ans = x-i;
            break;
        } else if ( !find_num(a, x+i) ) {
            ans = x+i;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
