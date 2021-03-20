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
    int64_t n;
    cin >> n;
    int64_t ans = 0;
    // 2桁
    repc2(i, 11, 100, 11) {
        if ( i <= n ) ++ans;
        else {
            cout << ans << endl;
            return 0;
        }
    }

    int64_t num;
    // 4桁
    rep2(i, 9) {
        rep(j, 10) {
            num = i*1000+j*100+i*10+j;
            // cout << num << endl;
            if ( num > n ) {
                cout << ans << endl;
                return 0;
            } else {
                ++ans;
            }
        }
    }

    // 6桁
    rep2(i, 9) {
        rep(j, 10) {
            rep(k, 10) {
                num = i*100000+j*10000+k*1000+i*100+j*10+k;
                if ( num > n ) {
                    cout << ans << endl;
                    return 0;
                } else {
                    ++ans;
                }
            }
        }
    }

    // 8
    rep2(i, 9) {
        rep(j, 10) {
            rep(k, 10) {
                rep(ii, 10) {
                    num = i*10000000+j*1000000+k*100000+ii*10000+i*1000+j*100+k*10+ii;
                    if ( num > n ) {
                        cout << ans << endl;
                        return 0;
                    } else {
                        ++ans;
                    }
                }
            }
        }
    }

    // 10
    rep2(i, 9) {
        rep(j, 10) {
            rep(k, 10) {
                rep(ii, 10) {
                    rep(jj, 10) {
                        num = i*1000000000+j*100000000+k*10000000+ii*1000000+jj*100000+i*10000+j*1000+k*100+ii*10+jj;
                        if ( num > n ) {
                            cout << ans << endl;
                            return 0;
                        } else {
                            ++ans;
                        }
                    }
                }
            }
        }
    }

    // 12
    rep2(i, 9) {
        rep(j, 10) {
            rep(k, 10) {
                rep(ii, 10) {
                    rep(jj, 10) {
                        rep(kk, 10) {
                            num = i*100000000000+j*10000000000+k*1000000000+ii*100000000+jj*10000000+kk*1000000+i*100000+j*10000+k*1000+ii*100+jj*10+kk;
                            if ( num > n ) {
                                cout << ans << endl;
                                return 0;
                            } else {
                                ++ans;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
