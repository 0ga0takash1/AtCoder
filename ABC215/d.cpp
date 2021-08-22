#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<std::vector<int64_t> > Graph;

#define in1(n) int64_t n;cin >> n;
#define in2(n, m) int64_t n, m;cin >> n >> m;
#define in3(n, m, k) int64_t n, m, k;cin >> n >> m >> k;
#define in4(a, b, c, d) int64_t a, b, c, d;cin >> a >> b >> c >> d;
#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define repc(i, l, n, d) for (int64_t i = l; i < n; i+=d)
#define repc2(i, l, n, d) for (int64_t i = l; i <= n; i+=d)
#define rep_(i, r) for (int64_t i = r-1; i >= 0; --i)
#define rep_2(i, r) for (int64_t i = r; i > 0; --i)
#define rep_b(i, r, l) for (int64_t i = r; i >= l; --i)
#define rep_b2(i, r, l) for (int64_t i = r; i > l; --i)
#define rep_c(i, r, l, d) for (int64_t i = r; i >= l; i-=d)
#define rep_c2(i, r, l, d) for (int64_t i = r; i > l; i-=d)
#define repf(i, l, c, d) for (int64_t i = l; c; i+=d)
#define repi(a, b) for (auto&(a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define Sort_pair(x, p) sort(ALL(x), (p))
#define vector2(a, n, k) std::vector<std::vector<int64_t>> a(n, std::vector<int64_t>(k))
#define ctoi(c) ((c)-'0')

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0; }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }
template<typename map,typename T> bool find_map(map m, T num) { auto itr = m.find(num); if ( itr == m.end() ) { return false; } return true; }

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 1e9+7;

std::vector<int64_t> Eratosthenes( int64_t n ) {
    std::vector<int64_t> is_prime(n+1, 1);

    std::vector<int64_t> P;
    repb2(i, 2, n) {
        if( is_prime[i] ) {
            for( int j = 2 * i; j <= n; j += i ) is_prime[j] = 0;
            P.push_back(i);
        }
    }
    return P;
}

vector<int64_t> prime_factorize(int64_t N) {
    vector<int64_t> res;
    for (int64_t a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        int64_t ex = 0;

        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        res.push_back(a);
    }

    if (N != 1) res.push_back(N);
    return res;
}

int main() {
    in2(n, m);
    std::vector<int64_t> a(n), ans(m, 1);
    rep(i, a.size()) {
        cin >> a[i];
        if ( ans[a[i]-1] ) {
            if ( a[i] != 1 ) {
                ans[a[i]-1] = 0;
                vector<int64_t> v = prime_factorize(a[i]);
                repi(see, v) {
                    if ( ans[see-1] ) {
                        repf(k, see, k <= m, see) {
                            ans[k-1] = 0;
                        }
                    }
                }
            }
        }
    }

    int64_t num = 0;
    rep(i, ans.size()) if ( ans[i] ) num++;
    cout << num << endl;
    rep(i, ans.size()) if ( ans[i] ) cout << i+1 << endl;
    return 0;
}
