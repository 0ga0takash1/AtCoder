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
#define rep_(i, r) for (int64_t i = r; i > 0; --i)
#define rep_2(i, r) for (int64_t i = r; i >= 0; --i)
#define rep_b(i, r, l) for (int64_t i = r; i > l; --i)
#define rep_b2(i, r, l) for (int64_t i = r; i >= l; --i)
#define rep_c(i, r, l, d) for (int64_t i = r; i > l; i-=d)
#define rep_c2(i, r, l, d) for (int64_t i = r; i >= l; i-=d)
#define repf(i, l, c, d) for (int64_t i = l; c; i+=d)
#define repi(a, b) for (auto&(a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define Sort_pair(x, p) sort(ALL(x), (p))
#define mp(a, b) make_pair((a), (b))
#define Push_back(a, b) push_back( mp( (a), (b) ) )
#define ctoi(c) ((c)-'0')

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 1e9+7;

pair<long double, long double> rotate ( long double x, long double y,
                                long double ox, long double oy,
                                long double theta) {
    x -= ox;
    y -= oy;
    return {x*cos(theta)-y*sin(theta)+ox, y*cos(theta)+x*sin(theta)+oy};
}

int main() {
    long double n;
    cin >> n;
    long double x, y;
    cin >> x >> y;
    long double x2, y2;
    cin >> x2 >> y2;

    // long double r = (x-x2)*(x-x2)+(y-y2)*(y-y2);
    // r = sqrt(r)/2;
    /*
    long double xx, yy, ox, oy, theta = 2*acos(-1)/n;
    ox = (x+x2)/2.0;
    oy = (y+y2)/2.0;
    x -= ox;
    y -= oy;
    xx = x*cos(theta)-y*sin(theta)+ox;
    yy = y*cos(theta)+x*sin(theta)+oy;
    cout << setprecision(15) << xx << " ";
    cout << setprecision(15) << yy << endl;
    */
    pair<long double, long double> ans
        = rotate(x, y, (x+x2)/2.0, (y+y2)/2.0, 2*acos(-1)/n);
    cout << setprecision(15) << ans.first << " " << ans.second << endl;
    return 0;
}
