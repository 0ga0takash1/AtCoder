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
    int64_t n;
    cin >> n;
    int64_t ans = 0, sum = 0, f = 0, *num;
    std::vector<int64_t> a(n), v;
    rep(i, n) {
        cin >> a[i];
        --a[i];
        sum += a[i]-i;
        if (a[i] == i) f = 1;

        // if ( i == 0 ) {
            // num = &a[i];
        // } else {
        if ( i != 0 && *num > a[i] ) {
            v.push_back(i);
            swap(*num, a[i]);
        }
        num = &a[i];
        // }
    }

    if ( sum != 0 || f ) {
        cout << -1 << endl;
    } else {
        rep(i, v.size()) cout << v[i] << endl;
        while (1) {
            rep(i, n-1) {
                if ( a[i] > a[i+1] ) {
                    swap(a[i], a[i+1]);
                    cout << i+1 << endl;
                }
            }

            int64_t f = 1;
            rep(i, n) {
                if ( a[i] != i ) {
                    f = 0;
                    break;
                }
            }
            if (f) return 0;
        }
    }
    return 0;
}
