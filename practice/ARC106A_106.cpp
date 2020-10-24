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

int main() {
    int64_t n;
    cin >> n;
    if (n < 8) {
        cout << -1 << endl;
        return 0;
    }

    int64_t three = 1, five = 1;
    std::vector<int64_t> v3, v5;
    while (v3.at(v3.size()-1)*3 <= n) {
        v3.push_back(v3.at(v3.size()-1)*3);
        ++three;
    }
    while (v5.at(v5.size()-1)*5 <= n) {
        v5.push_back(v5.at(v5.size()-1)*5);
        ++five;
    }

    // std::vector<std::vector<int64_t> > v35;
    int64_t right = five;
    rep(i, three) {
        rep(j, right) {
            int64_t num = v3[i]+v5[j];
            if (num > n) {
                right = j;
                break;
            }
            if (num == n) {
                cout << i+1 << " " << j+1 << endl;
                return 0;
            }
            // v35[i].push_back(num);
        }
    }

    cout << -1 << endl;
    return 0;
}
