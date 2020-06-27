#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define Push_back(p, a, b) (p).push_back( make_pair( (a), (b) ) )

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

// π M_PI
// deg = rad*180/M_PI

vector<int64_t> enum_div(int64_t n) {
    vector<int64_t> ret;
    for(int i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            ret.push_back(i);
            // cout << "i " << i;
            if(/*i != 1 &&*/ i*i != n){
                ret.push_back(n/i);
                // cout << " n/i " << n/i << endl;
            }
        }
    }
    return ret;
}

int main() {
    int64_t n;
    cin >> n;
    int64_t ans = 0;
    rep2(i, n) {
        // cout << "I" << i << endl;
        std::vector<int64_t> v = enum_div(i);
        cout << "a " << v.size() << endl;
        // ans += i*v.size();
    }
    // cout << ans << endl;
    return 0;
}
