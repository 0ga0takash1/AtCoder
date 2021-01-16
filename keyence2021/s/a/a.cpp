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
    int64_t n;
    cin >> n;
    std::vector<int64_t> a(n);
    rep(i, n) {
        cin >> a[i];
        if ( i > 0 ) {
            chmax(a[i], a[i-1]);
        }
    }
    std::vector<int64_t> b(n);
    rep(i, n) {
        cin >> b[i];
    }

    int64_t MAX;
    rep(i, n) {
        if ( i == 0 ) {
            MAX = a[i]*b[i];
        } else {
            // if ( b[i] <= b[i-1] ) {
                chmax(MAX, a[i]*b[i]);
            // } else {
                /*
                rep(j, i+1) {
                    chmax(MAX, a[j]*b[i]);
                }*/
                // chmax(MAX, *max_element(a.begin(), a.begin()+i+1)*b[i]);
            // }
        }
        cout << MAX << endl;
    }
    return 0;
}