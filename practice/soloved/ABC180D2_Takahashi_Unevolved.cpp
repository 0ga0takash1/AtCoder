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
    int64_t x, y, a, b;
    cin >> x >> y >> a >> b;

    /*
    std::vector<int64_t> v(y, -1);
    v[x] = 0;
    repb(i, x, y) {
        if ( v[i] == -1 ) continue;
        if ( i*a < y ) chmax(v[i*a], v[i]+1);
        if ( i+b < y ) chmax(v[i+b], v[i]+1);
    }
    cout << *max_element(ALL(v)) << endl;
    */
    /*
    int64_t ans = 0;
    queue<pair<int64_t, int64_t> > q;
    q.push({x, 0});
    while ( !q.empty() ) {
        int64_t st = q.front().first, ex = q.front().second;
        q.pop();
        if ( st*a < y ) {
            chmax(ans, ex+1);
            q.push({st*a, ex+1});
        }
        if ( st+b < y ) {
            chmax(ans, ex+1);
            q.push({st+b, ex+1});
        }
    }
    cout << ans << endl;
    */
    
    int64_t ans = 0;
    // aを選ぶだけ選ぶ
    while ( (double)a*x<=2e18 && x*a <= x+b && x*a < y ) {
        x *= a;
        ++ans;
    }
    // 残りのbを選べるだけ選ぶ
    ans += (y-1-x)/b;
    cout << ans << endl;
    return 0;
}
