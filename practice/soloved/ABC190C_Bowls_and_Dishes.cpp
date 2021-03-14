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
#define repi(a, b) for (auto&(a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define Sort_pair(x, p) sort(ALL(x), (p))
#define mp(a, b) make_pair((a), (b))
#define Push_back(a, b) push_back( mp( (a), (b) ) )
#define ctoi(c) (c)-'0'
#define vector2(a, n, k) std::vector<std::vector<int64_t>> a(n, std::vector<int64_t>(k));

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 1e9+7;

int main() {
    int64_t n, m;
    cin >> n >> m;

    std::vector<int64_t> a(m), b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        // --a[i];--b[i];
    }
    int64_t k;
    cin >> k;
    std::vector<int64_t> c(k), d(k);
    rep(i, k) {
        cin >> c[i] >> d[i];
        // --c[i];--d[i];
    }

    int64_t k2 = 1 << k; // 2^k通りの配分が考えられる
    int64_t ans = 0;

    // bit全探索、桁が0だったらc、1だったらdに配分する
    rep(i, k2) {
        // それぞれの数に対応する皿づくり
        std::vector<int64_t> dish(n+1, 0);
        rep(j, k) {
            //iのj桁目 が0ならc、1ならdを選ぶ
            if ( i>>j & 1 ) {
                ++dish[d[j]];
            } else {
                ++dish[c[j]];
            }
        }

        int64_t now = 0;
        rep(i, m) {
            if ( dish[a[i]] == 0 || dish[b[i]] == 0 ) continue;
            ++now;
            chmax(ans, now);
        }
        // cout << "a" << endl;
    }
    cout << ans << endl;
}

/*
int main() {
    int64_t n, m;
    cin >> n >> m;
    std::vector<int64_t> a(m), b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        --a[i];--b[i];
    }
    int64_t k;
    cin >> k;
    std::vector<int64_t> c(k), d(k);
    std::vector<int64_t> v(n, 0);
    rep(i, k) {
        cin >> c[i] >> d[i];
        --c[i];--d[i];
        ++v[c[i]];++v[d[i]];
    }

    // int64_t ans = m;
    rep(i, m) {
        if ( v[a[i]] == 0 || v[b[i]] == 0 ) {
            // --ans;
            v[a[i]] = 0;v[b[i]] = 0;
            a.erase(a.begin()+i);b.erase(b.begin()+i);
        }
    }
    m = a.size()-1;

    int64_t ans = 0;
    // kの選択を最大化


    rep(i, m) {
        if ( a[i] >= 1 && b[i] >= 1 ) {
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}
*/
