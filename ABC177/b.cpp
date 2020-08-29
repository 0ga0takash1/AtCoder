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
    string s;
    cin >> s;
    string t;
    cin >> t;
    std::vector<int64_t> v;
    if ( s.length() == t.length() ) {
        if ( s == t ) {
            cout << 0 << endl;
        } else {
            int64_t ans = 0;
            rep(i, s.length()) {
                if (s[i] != t[i]) ans++;
            }
            cout << ans << endl;
        }
        return 0;
    }
    rep(i, s.length()-t.length()) {
        // if ( s.at(i) == t.at(i) ) {
            int64_t num = t.length();
            rep(j, t.length()) {
                if ( s[i+j] == t[j] ) {
                    num--;
                }
            }
            v.push_back(num);
        // }
    }
    if (v.empty()) v.push_back(t.length());
    Sort(v);
    cout << *min_element(ALL(v)) << endl;
    return 0;
}
