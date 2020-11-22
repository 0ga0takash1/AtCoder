#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define repc(i, l, n, d) for (int64_t i = l; i < n; i+=d)
#define repc2(i, l, n, d) for (int64_t i = l; i <= n; i+=d)
#define repe(a, b) for (auto&(a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define mp(a, b) make_pair((a), (b))
#define Push_back(a, b) push_back( mp( (a), (b) ) )
#define ctoi(c) (c)-'0'

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 1e9+7;

int main() {
    int64_t r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if ( r1==r2 && c1==c2 ) {
        cout << 0 << endl;
    } else {
        if ( c2-c1 == r2-r1 || c2-c1 == r1-r2) {
            cout << 1 << endl;
        } else {
            if ( abs(r1-r2)+abs(c1-c2) <= 3 ) {
                cout << 1 << endl;
            } else {
                if ( abs(r1-r2)+abs(c1-c2) <= 6 ) {
                    cout << 2 << endl;
                } else {
                    if ( (r1-c1+r2+c2)%2 == 0 ) {
                        cout << 2 << endl;
                    } else {
                        int64_t x = (r1-c1+r2+c2)/2;
                        int64_t y = x-r1+c1;
                        if ( (x==r2 && y ==c2)
                            || (x+1==r2 && y ==c2)
                            || (x==r2 && y+1 ==c2)
                            || (x+1==r2 && y+1 ==c2)) {
                            cout << 2 << endl;
                        } else {
                            cout << 3 << endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
