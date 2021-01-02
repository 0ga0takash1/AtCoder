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
#define repe(a, b) for (auto&(a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define mp(a, b) make_pair((a), (b))
#define Push_back(a, b) push_back( mp( (a), (b) ) )
#define ctoi(c) (c)-'0'

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 1e9+7;


bool pair_Cf(const pair<string, int64_t>& firstElof, const pair<string, int64_t>& secondElof) {
    return firstElof.first < secondElof.first;
}

int main() {
    int64_t n;
    cin >> n;
    std::vector<string> v(n);
    // std::map<string, int64_t> m;
    vector<pair<string, int64_t> > p;
    rep(i, n) {
        cin >> v[i];

        if ( v[i].at(0) == '!' ) {
            v[i].erase(v[i].begin());
            // m.insert(mp(v[i], 1));
            p.Push_back(v[i], 1);
        } else {
            // m.insert(mp(v[i], 0));
            p.Push_back(v[i], 0);
        }
    }
    // Sort(v);
    sort(ALL(p), pair_Cf);
    rep(i, n-1) {
        if ( p[i].first == p[i+1].first
            && p[i].second != p[i+1].second ) {
            cout << p[i].first << endl;
            return 0;
        }
    }

    cout << "satisfiable" << endl;
    return 0;
}
