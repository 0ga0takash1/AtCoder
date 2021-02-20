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

int64_t convert(int64_t x, int64_t n){
    int64_t y=0, i=0, z;
    while(x > 0){
        z = x%n;
        y += z*pow(10, i);
        x = x/n;
        i++;
    }
    return y;
}

string change_base(int64_t a, int64_t base) {
    if(a==0) return "0";
    stringstream ss;
    int64_t ex = 0;
    while(a){
        int64_t rest = a%base+ex;
        if ( rest >= 10 ) {
            ex = rest/10;
            rest %= 10;
        } else {
            ex = 0;
        }
        ss << rest;
        a /= base;
    }
    // ss << ex;
    string s = ss.str();
    reverse(ALL(s));
    return s;
}

int main() {
    string x;
    cin >> x;
    int64_t xx = atoi(x.c_str());
    int64_t m;
    cin >> m;
    Sort_rev(x);
    int64_t ans = 0;
    for (int64_t i = ctoi(x[0])+1;; ++i) {
        // int64_t m2 = convert(m, i);
        // string m_s = to_string(m2);
        string m_s = change_base(m, i);
        int64_t m2 = atoi(m_s.c_str());
        if ( m_s.length() > x.length() ) {
            // cout << x << " " << m_s << endl;
            ++ans;
        } else if ( m_s.length() == x.length() ) {
            // cout << "a " << xx << " " << m2 << endl;
            if ( xx <= m2 ) {
                ++ans;
            } else {
                // cout << "Yes1" << endl;
                break;
            }
        } else {
            // cout << "Yes2" << endl;
            // cout << m_s << " " << x << endl;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
