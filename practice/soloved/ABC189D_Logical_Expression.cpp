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

    std::vector<int64_t> dp(2,1);
    rep(i,n) {
        string s;
        cin>>s;
        vector<int64_t> p(2);
        swap(dp,p);
        rep(j,2)rep(k,2) {
            int nj = j;
            if (s == "AND") nj &= k;
            else nj |= k;
            dp[nj] += p[j];
        }
        cout<<dp[1]<<" ";
    }
    cout<<dp[1]<<endl;
    return 0;
}
/*
    std::vector<string> s(n);
    rep(i, n) {
        cin >> s[i];
    }

    std::vector<int64_t> v(n+1);
    v[n] = 1;
    rep_(i, n) {
        if ( s[i-1] == "OR" ) {
            v[i-1] = v[i]+(1<<i);
        } else {
            v[i-1] = v[i];
        }
    }
    cout << v[0] << endl;
*/
/*
int64_t ans = 1;
rep_2(i, n-1) {
    if ( s[i] == "OR" ) {
        ans *= 2;
    }
}
cout << ans << endl;
*/
/*
int64_t n2 = 1 << (n+1);
std::vector<int64_t> y(n+1);

rep(i, n2) {
    rep(j, n+1) {
        // cout << (i>>j) << " ";
        cout << ( (i>>j & 1) ? 1 : 0 ) << " ";
    }
    cout << endl;
}
*/
/*
rep(x, n2) {
    y[0] = (x>>0 & 1) ? 1:0;
    rep2(i, n) {
        if ( s[i-1] == "AND" ) {
            y[i] = (y[i-1]&&(x>>i & 1)) ? 1:0;
        } else {
            y[i] = (y[i-1]||(x>>i & 1)) ? 1:0;
        }
    }
    // rep(i, n+1) cout << y[i] << " ";
    // cout << endl;
    if (y[n]) {
        ++ans;
        // cout << x << endl;
    }
}
cout << ans << endl;
*/
