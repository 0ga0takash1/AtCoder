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

bool pair_Cf_R(const pair<int64_t, int64_t>& firstElof, const pair<int64_t, int64_t>& secondElof) {
    return firstElof.first > secondElof.first;
}

bool pair_Cs_R(const pair<int64_t, int64_t>& firstElof, const pair<int64_t, int64_t>& secondElof) {
    return firstElof.second > secondElof.second;
}

int main() {
    int64_t n;
    cin >> n;

    int64_t aok = 0, tak = 0;
    std::vector<int64_t> a(n), b(n);
    // priority_queue<int64_t> q;
    vector<pair<int64_t, int64_t> > p;
    rep(i, n) {
        cin >> a[i] >> b[i];
        aok += a[i];
        p.Push_back(2*a[i]+b[i], a[i]);
        // q.push(a[i]+b[i]);
        // tak += b[i];
    }

    // sort(ALL(p), pair_Cs_R);
    sort(ALL(p), pair_Cf_R);
    rep(i, n) {
        // aok -= a[i];
        // aok -= p[i].first;
        aok -= p[i].second;
        // tak += a[i]+b[i];
        // tak += p[i].first+p[i].second;
        tak += p[i].first-p[i].second;
        if ( aok < tak ) {
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}
