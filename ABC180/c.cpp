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

/*
// 約数列挙
set<int64_t> enum_div(int64_t n) {
    set<int64_t> ret;
    for(int i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            // ret.push_back(i);
            ret.insert(i);
            if( i*i != n ){
                // ret.push_back(n/i);
                ret.insert(n/i);
            }
        }
    }
    // Sort(ret);
    return ret;
}

// 素数判定
bool isPrime(int64_t x) {
    int i;
    if(x < 2)return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
    return 1;
}
*/

int main() {
    int64_t n;
    cin >> n;

    // set<int64_t> v = enum_div(n);
    set<int64_t> set;
    for(int64_t i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            set.insert(i);
            if( i*i != n ){
                set.insert(n/i);
            }
        }
    }
    repe(a, set) cout << a << endl;
    /*
    std::vector<int64_t> v = enum_div(n);
    rep(i, v.size()) {
        cout << v[i] << endl;
    }
    /*
    int64_t num = 0;

    rep(i, n+1) {
        repb(j, num, v.size()) {
            if ( i == v[j] ) {
                cout << i << endl;
                num = j;
                break;
            }
        }
    }*/
    return 0;
}
