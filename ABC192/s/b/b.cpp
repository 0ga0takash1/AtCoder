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

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 1e9+7;


void Alphabet (char s) {
    if (s >= 'a' && s <= 'z') {
        cout << "small" << endl;
    } else if(s >= 'A' && s <= 'Z') {
        cout << "large" << endl;
    } else if(s >= '0') {
        cout << "number" << endl;
    }
    return;
}


int main() {
    string s;
    cin >> s;
    int64_t ans = 1;
    rep(i, s.length()) {
        if ( i%2 ) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ans = 0;
                break;
            }
        } else {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                ans = 0;
                break;
            }
        }
    }

    cout << ( ans ? "Yes" : "No" ) << endl;
    return 0;
}
