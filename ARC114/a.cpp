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

vector<pair<int64_t, int64_t> > prime_factorize(int64_t N) {
    vector<pair<int64_t, int64_t> > res;
    for (int64_t a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        int64_t ex = 0;

        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        res.push_back({a, ex});
    }

    if (N != 1) res.push_back({N, 1});
    return res;
}

std::vector<int64_t> test = {
    // 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47
    // 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 28, 22, 49
    // 24, 9, 39
    // 2, 3, 5, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 49, 8
    // 8, 9, 25, 49, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47
    // 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47
    10, 15, 35, 46
    // 42, 49
    // 42, 47, 49
};

int main() {
    int64_t n;
    cin >> n;
    std::vector<int64_t> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    // std::vector<int64_t> a;
    // a = test;
    Sort(a);

    if ( n == 1 ) {
        vector<pair<int64_t, int64_t> > p = prime_factorize(a[0]);
        cout << p[0].first << endl;
        return 0;
    }

    unordered_set<int64_t> s, s2, s3;
    // std::vector<int64_t> div_cnt(50, 0);
    int64_t fd;
    rep(i, a.size()) {
        int64_t num = a[i];
        vector<pair<int64_t, int64_t> > p = prime_factorize(num);
        if ( i == 0 ) {
            fd = p.size();
            if ( fd >= 1 ) s.insert(p[0].first);
            if ( fd >= 2 ) s2.insert(p[1].first);
            if ( fd >= 3 ) s3.insert(p[2].first);
        } else {
            int ok = 0, ok2 = 0, ok3 = 0;
            if ( p.size() != 1 || p[0].second > 1 ) {
                repi(j, p) {
                    if ( find_num(s, j.first) ) ok = 1;
                    if ( fd >= 2 && find_num(s2, j.first) ) ok2 = 1;
                    if ( fd >= 3 && find_num(s3, j.first) ) ok3 = 1;
                }
            }
            if (!ok) s.insert(p[0].first);
            if ( fd >= 2 && !ok2 ) s2.insert(p[0].first);
            if ( fd >= 3 && !ok3 ) s3.insert(p[0].first);
        }
    }

    int64_t ans = 1, ans2 = 1, ans3 = 1;
    repi(num, s) {
        ans *= num;
    }
    if ( fd >= 2 ) {
        repi(num, s2) {
            ans2 *= num;
        }
        chmin(ans, ans2);
    }
    if ( fd >= 3 ) {
        repi(num, s3) {
            ans3 *= num;
        }
        chmin(ans, ans3);
    }
    cout << ans << endl;
    return 0;
}
