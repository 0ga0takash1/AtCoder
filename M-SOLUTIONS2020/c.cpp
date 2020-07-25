#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define Push_back(p, a, b) (p).push_back( make_pair( (a), (b) ) )

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

int main() {
    int64_t n, k;
    cin >> n >> k;
    int64_t a[n];
    std::vector<int64_t> v;
    int64_t kk = 1;
    rep(i, n) {
        cin >> a[i];
        if ( i < k ) {
            kk *= a[i];
            if ( i == k-1 ) {
                v.push_back(kk);
                // cout << "a " << i << " " << i-k << endl;
                // cout << "a " << v.at(v.size()-1) << endl;
            }
        } else {
            kk /= a[i-k];
            v.push_back(kk*a[i]);
            // cout << "a " << i << " " << i-k << endl;
            // cout << "b " << a[i-k] << " " << a[i] << endl;
            // cout << "c " << v.at(v.size()-1) << endl;
        }
    }

    repb(i, 1, v.size()) {
        int64_t ans = 1;
        if ( v[i-1] >= v[i] ) {
            ans = 0;
        }
        cout << ( ans ? "Yes" : "No" ) << endl;
    }
    return 0;
}
