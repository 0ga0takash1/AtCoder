/*---------------------------------------------*/
/*
    ABC179 C
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
/*
int64_t enum_div2 (int64_t n) {
    int64_t ans = 0;
    rep2(i, n-1) {
        for(int j = 1; j*j <= i; ++j){
            if(i%j == 0){
                ++ans;
                if ( j*j != i ) {
                    ++ans;
                }
            }
        }
    }
    return ans;
}
*/
int64_t func (int64_t n) {
    vector<int64_t> x(n+1);
	int64_t num = n; // 素因数分解する変数num
    int64_t ans = 1;

    repb2(i, 2, n) {
		while (num%i == 0) { // 素数で割り切れなくなるまで割っていく
			x.at(i)++; //割った個数を配列に足す
			num /= i;
		}
	}

    repb2(i, 2, n) {
		ans *= x.at(i) + 1; //それぞれを+1して掛けていく
	}
    return ans;
}

int main() {
    int64_t n;
    cin >> n;

    // cout << enum_div2(n) << endl;
    int64_t ans = 0;
    rep2(i, n-1) {
        ans += func(i);
    }
    cout << ans << endl;
    return 0;
}
