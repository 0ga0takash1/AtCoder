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

vector<int64_t> enum_div(int64_t n) {
    vector<int64_t> ret;
    for(int64_t i = 1; i*i <= n; ++i){
        if(n%i == 0){
            ret.push_back(i);
            if(i*i != n){
                ret.push_back(n/i);
            }
        }
    }
    Sort(ret);
    return ret;
}

int main() {
    int64_t n;
    cin >> n;
    std::vector<int64_t> v = enum_div(n);
    int64_t ans = 0;
    rep(i, v.size()) {
        int64_t bc = n/v[i];
        for(int64_t j = 1; j*j <= bc; ++j){
            if(bc%j == 0){
                if ( j == v[i] ) { // a = b
                    if ( bc/j == v[i] ) { // a = b = c
                        ans += n;
                    } else { // a = b b != c
                        ans += 3*n;
                    }
                } else { // a != b
                    if ( bc/j == v[i] ) { // a = c a != b
                        ans += 3*n;
                    } else { // a != b != c
                        ans += 6*n;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
