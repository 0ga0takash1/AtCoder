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

int64_t enum_div(int64_t n) {
    vector<int64_t> ret;
    for(int i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            ret.push_back(i);
            if ( i*i != n ) {
                ret.push_back(n/i);
            }
        }
    }
    return ret.size();
}

int64_t enum_div2 (int64_t n) {
    vector<int64_t> ret;
    rep2(i, n-1) {
        for(int j = 1; j*j <= i; ++j){
            if(i%j == 0){
                ret.push_back(j);
                if ( j*j != i ) {
                    ret.push_back(i/j);
                }
            }
        }
        // ans += ret.size();
    }
    return ret.size();
}

int main() {
    int64_t n;
    cin >> n;
    // std::vector<int64_t> v;
    /*
    int64_t ans = 0;
    rep2(i, n-1) {
        ans += enum_div(i);
    }
    cout << ans << endl;
    */

    // cout << enum_div2(n) << endl;
    int64_t ans = 0;
    rep2(i, n-1) {
        ans += (n-1)/i;
    }
    cout << ans << endl;
    return 0;
}
