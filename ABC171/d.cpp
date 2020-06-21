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

int main() {
    int64_t n;
    cin >> n;
    std::vector<int64_t> a(n);
    // std::vector<int64_t> num(100000, 0);
    rep(i, n) {
        cin >> a[i];
        // num[a[i]-1]++;
    }
    int64_t q;
    cin >> q;
    int64_t b[q], c[q];
    rep(i, q) {
        cin >> b[i] >> c[i];
    }
/*
    rep(i, q) {
        int64_t ans = accumulate(ALL(a), 0LL);
        // cout << "a" << ans << endl;
        int64_t C = count(ALL(a), b[i]);
        if ( C > 0 ) {
            ans += (c[i]-b[i])*C;
        }
        cout << ans << endl;
    }*/


    rep(i, q) {
        // std::vector<int64_t> v;
        // cout << "a" << ans << endl;
        /*rep(j, n) {
            v.push_back(a[j]);
        }*/
        // cout << "b:" << b[i] << " c:" << c[i] << endl;
        Sort(a);
        int64_t C = count(ALL(a), b[i]);
        cout << "C:" << C;
        if ( C > 0 ) {
            int64_t f = *find(ALL(a), b[i]);
            cout << " f:" << f << endl;
            rep(j, C) {
                a[f+j] = c[i];
            }

            cout << "Yes" << endl;
            rep(j, n) {
                cout << a[j] << " ";
            }
            cout << endl;
        }

/*
        if ( C > 0 ) {
            ans += (c[i]-b[i])*C;
        }*/
        int64_t ans = accumulate(ALL(a), 0LL);
        cout << ans << endl;
    }

    return 0;
}
