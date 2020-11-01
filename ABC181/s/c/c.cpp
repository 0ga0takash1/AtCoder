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


bool pair_Cf(const pair<int64_t, int64_t>& firstElof, const pair<int64_t, int64_t>& secondElof) {
    return firstElof.first < secondElof.first;
}

bool pair_Cs(const pair<int64_t, int64_t>& firstElof, const pair<int64_t, int64_t>& secondElof) {
    return firstElof.second < secondElof.second;
}

int main() {
    int64_t n;
    cin >> n;
    std::vector<int64_t> x(n), y(n);
    vector<pair<int64_t, int64_t> > p;
    std::vector<int64_t> vx(1001, 0), vx2(1001, 0), vy(1001, 0), vy2(1001, 0);
    rep(i, n) {
        cin >> x[i] >> y[i];
        p.Push_back(x[i], y[i]);
        if ( x[i] >= 0 ) ++vx[x[i]];
        if ( x[i] < 0 ) ++vx2[abs(x[i])];
        if ( y[i] >= 0 ) ++vy[y[i]];
        if ( y[i] < 0 ) ++vy2[abs(y[i])];
    }
    if ( *max_element(ALL(vx)) >= 3 || *max_element(ALL(vx2)) >= 3 ||
         *max_element(ALL(vy)) >= 3 || *max_element(ALL(vy2)) >= 3 ) {
        cout << "Yes" << endl;
        return 0;
    }

    sort(ALL(p), pair_Cs);
    sort(ALL(p), pair_Cf);
    rep(i, n-2) {
        repb(i2, i+1, n-1) {
            // if ( p[i].first == p[i2].first ) continue;
            repb(i3, i2+1, n) {
                // if ( p[i2].first == p[i3].first ) continue;

                if ( (p[i3].second-p[i].second)*(p[i2].first-p[i].first) == (p[i2].second-p[i].second)*(p[i3].first-p[i].first) ) {
                    // cout << "1:" << p[i].first << " " << p[i].second << endl;
                    // cout << "2:" << p[i2].first << " " << p[i2].second << endl;
                    // cout << "3:" << p[i3].first << " " << p[i3].second << endl;

                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
