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
#define ctoi(c) ((c)-'0')

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 1e9+7;
/*
std::vector<string> change_base(int64_t a, int64_t base) {
    std::vector<string> s;
    if( a == 0 ) {
        s.push_back("0");
        return s;
    }
    while(a){
        int64_t rest = a%base;
        s.push_back( to_string(rest) );
        a /= base;
    }
    reverse(ALL(s));
    return s;
}
*/
std::vector<int64_t> change_base(int64_t a, int64_t base) {
    std::vector<int64_t> res;
    if( a == 0 ) {
        res.push_back(0);
        return res;
    }
    while(a){
        int64_t rest = a%base;
        res.push_back(rest);
        a /= base;
    }
    reverse(ALL(res));
    return res;
}

bool Compare_string_number ( string s, vector<int64_t> v ) {
    if ( v.size() > s.size() ) return true;
    if ( v.size() < s.size() ) return false;

    rep(i, s.size()) {
        int64_t a = ctoi(s[i]), b = v[i];//atoi(v[i].c_str());
        if ( a > b ) {
            return false;
        } else if ( a < b ) {
            return true;
        }
    }
    return true;
}

int main() {
    string x, xx;
    cin >> x;
    int64_t m;
    cin >> m;
    if ( x.length() == 1 ) {
        cout << ( (ctoi(x[0]) <= m) ? 1 : 0 ) << endl;
        return 0;
    }
    xx = x;
    Sort_rev(xx);
/*
    for (int64_t i = ctoi(x[0])+1;; ++i) {
        std::vector<string> m_s = change_base(m, i);
        if ( m_s.size() > x.size() ) {
            ++ans;
        } else if ( m_s.size() == x.size() ) {
            if ( Compare_string_number(x, m_s) ) {
                ++ans;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    */
    int64_t ok = ctoi(xx[0]), ng = INF;
    while ( ok+1 < ng ) {
        int64_t num = (ok+ng)/2;
        std::vector<int64_t> m_s = change_base(m, num);
        if ( Compare_string_number(x, m_s) ) ok = num;
        else ng = num;
    }

    int64_t ans = ok-ctoi(xx[0]);
    // int64_t ans = ok-(xx[0]-'0');
    // int64_t ans = ok;
    // ans -= ctoi(xx[0]);
    cout << ans << endl;
    return 0;
}
