#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define repe(a, b) for (auto&(a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define mp(a, b) make_pair((a), (b))
#define Push_back(a, b) push_back( mp( (a), (b) ) )

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 1e9+7;

std::vector<int64_t> seen(200000, 0);
int64_t bfs ( Graph G, int64_t start_num, std::vector<int64_t> ab ) {
    queue<int64_t> q;
    // int64_t start_num = 0;
    q.push(start_num);
    int64_t sum = 0;
    while ( !q.empty() ) {
        int64_t num = q.front();
        seen[num] = 1;

        sum += ab[num];

        q.pop();
        rep(i, G[num].size()) {
            int64_t see = G[num].at(i);
            if ( seen[see] == 0 ) {
                q.push(see);
                // seen[see] = 1;
            }
        }
    }
    // cout << "b:" << sum << endl;
    if ( sum == 0 ) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int64_t n, m;
    cin >> n >> m;
    std::vector<int64_t> a(n), b(n), ab(n);
    rep(i, n) {
        cin >> a[i];
    }
    int64_t judge = 1, sum = 0;
    rep(i, n) {
        cin >> b[i];
        if (b[i] != a[i]) judge=0;
        sum += b[i]-a[i];
        ab[i] = b[i]-a[i];
    }
/*
    cout << "ab:";
    rep(i, n) {
        cout << ab[i] << " ";
    }
    cout << endl;*/

    if ( judge ) {
        cout << "Yes" << endl;
        return 0;
    }
    if ( sum != 0 ) {
        cout << "No" << endl;
        return 0;
    }

    Graph G(n);
    std::vector<int64_t> c(m), d(m);
    rep(i, m) {
        cin >> c[i] >> d[i];
        G[c[i]-1].push_back(d[i]-1);
        G[d[i]-1].push_back(c[i]-1);
    }

    rep(i, n) {
        if ( G[i].empty() ) {
            if ( ab[i] != 0 ) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if ( !seen[i] ) {
                // cout << "com" << i << endl;
                if ( !bfs(G, i, ab) ) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
