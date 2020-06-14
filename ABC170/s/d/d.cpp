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

vector<int64_t> enum_div(int64_t n) {
    vector<int64_t> ret;
    for(int i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            ret.push_back(i);
            if(i != 1 && i*i != n){
                ret.push_back(n/i);
            }
        }
    }
    return ret;
}

int main() {
    int64_t n;
    cin >> n;
    std::vector<int64_t> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    if ( n == 1 ) {
        cout << 1 << endl;
        return 0;
    }

    Sort(a);
    std::vector<int64_t> num(a[n-1], 0);
    rep(i, n) {
        num[a[i]-1]++;
    }

    if ( a[0] == a[n-1] ) {
        cout << 0 << endl;
        return 0;
    }

    Graph aa(n);
    rep(i, n) {
        std::vector<int64_t> v = enum_div(a[i]);
        rep(j, v.size()) {
            aa[i].push_back( v[j] );
        }
    }

    int64_t ans = 0;
    rep(i, n) {
        int64_t J = 0;
        rep(j, aa[i].size()) {
            if ( find_num(a, aa[i].at(j) ) ) {
                J = 1;
                break;
            }
        }
        if (!J) ans++;
    }
    cout << ans << endl;

/*
    int64_t ans = 0;
    if (a[0] != a[1]) ans++;
    for (int64_t i = 1; i < n; ++i) {
        if ( num[a[i]-1] > 1 ) continue;

        int64_t J = 0;
        rep(j, i) {
            if ( a[j] > a[i]/2 ) break;

            if ( a[i]%a[j] == 0 ) {
                J = 1;
                break;
            }
        }

        if ( !J ) ans++;
    }
    cout << ans << endl;
*/
    return 0;
}
