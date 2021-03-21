/*---------------------------------------------*/
/*
    ABC174 C
 */
/*---------------------------------------------*/

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
    if ( n%2 != 0 ) {
        int64_t L;
        if ( n%7 == 0 ) {
            L = 9*n/7;
        } else {
            L = 9*n;
        }

        int64_t num = 10;
        rep2(i, L) {
            if ( num%L == 1 ) {
                cout << i << endl;
                return 0;
            }
            num = (num%L)*10;
        }
    }
    cout << -1 << endl;
    return 0;
}
