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

int main() {
    int64_t n, m;
    cin >> n >> m;
    std::vector<string> a(n);
    int64_t even1 = 0, odd1 = 0;
    rep(i, n) {
        cin >> a[i];
        Sort_rev(a[i]);
        // cout << "a:" << a[i] << endl;
        int64_t num1 = 0;
        if ( a[i][m-1] == '1' ) {
            num1 = m;
        } else {
            rep(j, m) {
                if (a[i][j] == '0') {
                    num1 = j;
                    break;
                }
            }
        }
        if ( num1%2 == 0 ) ++even1;
        else ++odd1;
        // cout << even1 << " " << odd1 << endl;
    }
    cout << even1*odd1 << endl;
    return 0;
}

/*
int main() {
    int64_t n, m;
    cin >> n >> m;
    std::vector<string> a(n);
    // vector<pair<int64_t, int64_t> > p(n, {0, 0});
    int64_t even1 = 0, odd1 = 0;
    rep(i, n) {
        cin >> a[i];
        int64_t num1 = 0;
        rep(j, m) {
            if (a[i][j] == '1') ++p[i].first;
            else ++p[i].second;
        }
    }

    int64_t ans = 0;
    int64_t k2 = 1 << m;
    rep(s, k2) {
        std::vector<char> dish(m, '0');
        rep(i, k2) if ( s>>i & 1 ) dish[i] = '1';
        rep(i, dish.size()) cout << dish[i] << " ";
        cout << endl;

        // 以下
        int64_t judge = 1;
        rep(i, n-1) {
            repb(j, i+1, n) {
                int64_t i_p = 0, j_p = 0;
                rep(k, m) {
                    if ( dish[k] == a[i][k] ) ++i_p;
                    if ( dish[k] == a[j][k] ) ++j_p;
                }
                if ( i_p == j_p ) {
                    cout << i_p << " " << j_p << endl;
                    // ++ans;
                    judge = 0;
                    break;
                }
            }
            if (!judge) break;
        }
        if (judge) ++ans;
    }
    rep(i, n-1) {
        repb(j, i+1, n) {
            if ( p[i].first != p[j].first || p[i].second != p[j].second ) {
                cout << i << " " << j << endl;
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
*/
