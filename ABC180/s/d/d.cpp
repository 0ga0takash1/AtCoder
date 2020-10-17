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

void neccesary_number(int64_t x, int64_t y,
                    int64_t a, int64_t b,
                    std::vector<int64_t> v, int64_t ans) {
    if ( x*a <= y || x+b <= y ) {
        // v.push_back(x*a);
        ans++;
        v.push_back(ans);
    }
    /*
    if ( x+b <= y ) {
        // v.push_back(x+b);
    }*/

    if ( x*a <= y ) neccesary_number(x*a, y, a, b, v, ans);
    if ( x+b <= y ) neccesary_number(x+b, y, a, b, v, ans);
}
/*
std::vector<int64_t> neccesary_num(int64_t x, int64_t y, int64_t a, int64_t b) {
    std::vector<int64_t> v;
    neccesary_number(x, y, a, b, v);
    Sort(v);
    return v;
}
*/
int main() {
    int64_t x, y, a, b;
    cin >> x >> y >> a >> b;
    /*
    std::vector<int64_t> v;
    int64_t ans = 0;
    neccesary_number(x, y, a, b, v, ans);
    cout << v[v.size()-1] << endl;
    */

    int64_t num = -1, ans = 0;
    int64_t can_a = 1, can_b = 1;
    std::vector<int64_t> v(y, 0);
    // std::vector<int64_t> num = neccesary_num(x, y, a, b);
    // v[x] = 1;
    repb2(i, x, y) {
        if ( i < y/2 ) {
            if ( v[i] == 0 && i != x ) continue;
            // cout << i << ":" << v[i] << endl;
            if ( !can_a && !can_b ) break;
            if ( can_a ) {
                if ( i*a <= y ) {
                    // v[i*a] = v[i]+1;
                    if ( i*a < y/2 ) {
                        chmax(v[i*a], v[i]+1);
                    } else {

                    }
                } else {
                    can_a = 0;
                }
            }

            if ( can_b ) {
                if ( i+b <= y ) {
                    chmax(v[i+b], v[i]+1);
                } else {
                    can_b = 0;
                }
            }
        } else {

        }

    }
    cout << *max_element(ALL(v)) << endl;
    return 0;
}
