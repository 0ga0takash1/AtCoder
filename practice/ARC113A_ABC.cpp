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
    int64_t n;
    cin >> n;
    int64_t ans = 0;
    rep2(a, n) {
        for (int64_t b = 1; a*b <= n; ++b) {
            ans += n/a/b;
        }
    }
    cout << ans << endl;
    return 0;
}

/*
vector<int64_t> enum_div(int64_t n) {
    vector<int64_t> ret;
    for(int64_t i = 1; i*i <= n; ++i){
        if(n%i == 0){
            // ret.push_back(i);

            if(i*i != n){
                ret.push_back(n/i);
            }
        }
    }
    Sort(ret);
    return ret;
}

int main() {
    int64_t n;
    cin >> n;
    std::vector<int64_t> v = enum_div(n);
    int64_t ans = 0;
    rep(i, v.size()) {
        int64_t bc = n/v[i];
        for (int64_t b = 1; b*b <= bc; ++b) {
            if( bc%b == 0 ) {
                int64_t a = v[i], c = bc/b;
                int64_t min_num = min(a, min(b, c)), max_num = max(a, max(b, c));
                int64_t mid_num = a+b+c-min_num-max_num;
                /*
                if ( a == b ) {
                    if ( a == c ) {
                        // cout << "a" << endl;
                        ans += n;
                    } else {
                        // cout << "b" << endl;
                        ans += 3*n;
                        ans -= 2*min_num*min_num;
                    }
                } else {
                    if ( a == c ) {
                        // cout << "c" << endl;
                        ans += 3*n;
                    } else {
                        if ( b == c ) {
                            ans += 3*n;
                        } else {
                            // cout << "d" << endl;
                            ans += 6*n;
                            ans -= 2*mid_num*mid_num;
                        }
                    }
                    ans -= 2*min_num*min_num;
                }
                // cout << a << " " << b << " " << c << endl;
                // cout << ans << endl;
                *
                int64_t same = 0;
                if ( a == b ) ++same;
                if ( b == c ) ++same;
                if ( c == a ) ++same;
                if ( !same ) {
                    // ans += 6*n;
                    // ans -= 5*min_num*min_num;
                    // ans -= 2*(mid_num-min_num)*(mid_num-min_num);
                    ans += min_num*min_num*min_num;
                    ans += 3*min_num*(mid_num-min_num)*(mid_num-min_num);
                    ans += 3*min_num*mid_num*(max_num-mid_num);
                } else if ( same == 1 ) {
                    ans += 3*n-2*min_num*min_num;
                } else {
                    ans += n;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
*/
