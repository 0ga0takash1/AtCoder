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
const int64_t MOD = 1e9+7;

int main() {
    int64_t n, m;
    cin >> n >> m;
    int64_t ans = 0;

/*
    rep2(i, n) {
        // int64_t jj = i-m;
        // if ( jj < 0 || n < jj ) continue;

        rep2(j, n) {
        // repb2(j, jj, n) {
            /*
            rep2(k, n) {
                rep2(l, n) {
                    if ( i+j-k-l == m ) {
                        ++ans;
                    }
                }
            }

            int64_t num = i+j-m;
            if ( num < 0 || n*2 < num ) continue;
            ans += num-1;
            /*
            int64_t num2 = 0;
            rep2(i, num-1) {
                if (num-i <= n) {
                    num2 = i-1;
                    break;
                }
            }

            if ( n+1 < num ) {
                ans -= (num-(n+1))*2;
            }
        }
    }
*/


    repb2(i, 2, 2*n) {
        int64_t num1 = i;
        if ( num1 < 0 || 2*n < num1 ) continue;
        if ( n+1 < num1 ) {
            num1 -= (num1-(n+1))*2;
        }
        --num1;

        int64_t num2 = i-m;
        if ( num2 < 0 || 2*n < num2 ) continue;
        if ( n+1 < num2 ) {
            num2 -= (num2-(n+1))*2;
        }
        --num2;

        // ans += (i-1)*(num-1);
        // cout << "num1:" << num1 << " num2:" << num2 << endl;
        ans += num1*num2;
    }

    cout << ans << endl;
    return 0;
}
