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
    int64_t n;
    cin >> n;
    string s;
    cin >> s;

    std::vector< std::vector<int64_t> > v(n, std::vector<int64_t>(4, 0) );
    if ( s.at(0) == 'A' ) {
        v.at(0).at(0)++;
    } else if ( s.at(0) == 'T' ) {
        v.at(0).at(1)++;
    } else if ( s.at(0) == 'C' ) {
        v.at(0).at(2)++;
    } else if ( s.at(0) == 'G' ) {
        v.at(0).at(3)++;
    }
    repb(i, 1, n) {
        if ( s.at(i) == 'A' ) {
            v.at(i).at(0) = v.at(i-1).at(0)+1;
            v.at(i).at(1) = v.at(i-1).at(1);
            v.at(i).at(2) = v.at(i-1).at(2);
            v.at(i).at(3) = v.at(i-1).at(3);
        } else if ( s.at(i) == 'T' ) {
            v.at(i).at(0) = v.at(i-1).at(0);
            v.at(i).at(1) = v.at(i-1).at(1)+1;
            v.at(i).at(2) = v.at(i-1).at(2);
            v.at(i).at(3) = v.at(i-1).at(3);
        } else if ( s.at(i) == 'C' ) {
            v.at(i).at(0) = v.at(i-1).at(0);
            v.at(i).at(1) = v.at(i-1).at(1);
            v.at(i).at(2) = v.at(i-1).at(2)+1;
            v.at(i).at(3) = v.at(i-1).at(3);
        } else if ( s.at(i) == 'G' ) {
            v.at(i).at(0) = v.at(i-1).at(0);
            v.at(i).at(1) = v.at(i-1).at(1);
            v.at(i).at(2) = v.at(i-1).at(2);
            v.at(i).at(3) = v.at(i-1).at(3)+1;
        }
    }
/*
    rep(i, n) {
        cout << "v[" << i << "] ";
        rep(j, 4) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
// */
    int64_t ans = 0;
    rep(l, n-1) {
        repb(r, l+1, n) {
            int64_t a, t, c, g;
            if ( l == 0 ) {
                a = v.at(r).at(0);
                t = v.at(r).at(1);
                c = v.at(r).at(2);
                g = v.at(r).at(3);
            } else {
                a = v.at(r).at(0)-v.at(l-1).at(0);
                t = v.at(r).at(1)-v.at(l-1).at(1);
                c = v.at(r).at(2)-v.at(l-1).at(2);
                g = v.at(r).at(3)-v.at(l-1).at(3);
            }

            if ( a == t && c == g ) {
                ans++;
                // cout << "l:" << l << " r:" << r << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
