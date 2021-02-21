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

int main() {
    string s;
    cin >> s;
    int64_t ans = 0;
    char ever_c;
    int64_t ever_i = s.length()-1;
    // map<char, int64_t> mp;
    for (int64_t i = s.length()-2; i > 0; --i) {
        if ( s[i] == s[i-1] ) {
            if ( s[i] != s[i+1] ) {
                ans += s.length()-(i+1);
                // cout << "a: " << ans << endl;
                if ( ever_c == s[i] ) {
                    ans -= s.length()-ever_i;
                }
                repb(j, i+2, ever_i) {
                    if ( s[j] == s[i] ) {
                        ans--;
                    }
                }
                ever_c = s[i];
                ever_i = i-1;
                // cout << "b: " << ans << endl;
            }

            if ( s[i] == ever_c ) {
                ever_i = i-1;
            }
            // cout << "c: " << ans << endl;
        }
        /*
        auto itr = mp.find(s[i]);
        if( itr != mp.end() ) {
            if ( s[i] == s[i-1] && s[i] != s[i+1] ) {
                ans -= itr->second;
            }
            itr->second++;
        } else {
            mp[s[i]] = 1;
        }*/
    }
    cout << ans << endl;
    return 0;
}
