/*---------------------------------------------*/
/*
    ABC177 D
 */
/*---------------------------------------------*/

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
const int64_t INF = 0x3fffffffffffffff;

struct UnionFind {
    //自身が親であれば、その集合に属する頂点数に-1を掛けたもの
    //そうでなければ親のid
    vector<int64_t> r;

    UnionFind(int64_t N) {
        r = vector<int64_t>(N, -1);
    }

    int64_t root(int64_t x) {
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }

    bool unite(int64_t x, int64_t y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x, y);
        r[x] += r[y];
        r[y] = x;
        return true;
    }

    int64_t size(int64_t x) {
        return -r[root(x)];
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    //友達集合を作る
    UnionFind UF(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A -= 1; B -= 1;
        UF.unite(A, B);
    }

    //最大の友達集合を求める
    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, UF.size(i));
    }

    cout << ans << endl;
    return 0;
}
