#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define Push_back(p, a, b) (p).push_back( make_pair( (a), (b) ) )

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

// π M_PI
// deg = rad*180/M_PI

int64_t func (int64_t x, int64_t y, int64_t z) {
    return x*x+y*y+z*z+x*y+y*z+z*x;
}

int main() {
    int64_t n;
    cin >> n;
    int64_t x = 1;
    std::vector<int64_t> v;
    while (1) {
        int64_t y = 1;
        while (1) {
            int64_t z = 1;
            while (1) {
                int64_t num = func(x, y, z);
                if (num > 10000) break;
                v.push_back(num);
                z++;
            }
            if (z == 1) break;
            y++;
        }
        if (y == 1) break;
        x++;
    }

    Sort(v);

    int64_t pin = 0;
    rep2(i, n) {
        if ( !find_num(v, i) ) {
            cout << 0 << endl;
        } else {
            int64_t ans = 0;
            int64_t boo = 0;
            for (int64_t j = pin; j <= v.size(); ++j) {
                if (boo == 1) {
                    if ( v[j] == i ) {
                        ans++;
                        pin = j;
                    } else {
                        break;
                    }
                }

                if (v[j] == i) boo = 1;
            }
            cout << ans+1 << endl;
        }
    }
    return 0;
}
