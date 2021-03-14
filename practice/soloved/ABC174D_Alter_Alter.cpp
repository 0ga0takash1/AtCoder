/*---------------------------------------------*/
/*
    ABC174 D
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

int main() {
    int64_t n;
    cin >> n;
    string s;
    cin >> s;
    
    int64_t ans = 0;
    int64_t r = n-1;
    rep(i, s.length()) {
        if ( s[i] == 'R' ) continue;
        while( r>=0 && s[r]=='W' ) {
            r--;
        }
        if(i<r){
            swap(s[i],s[r]);
            ans++;
        }
    }
    cout << ans << endl;
    /*
    int64_t W_num = 0;
    int64_t R_num = 0;
    int64_t p_num = 0;
    rep(i, s.length()) {
        if (s[i] == 'W') W_num++;
        if (s[i] == 'R') R_num++;
        if ( i <= s.length()-1
            && s[i] == 'W' && s[i+1] == 'R' ) {
            p_num++;
        }
    }

    int64_t ans = 0;
    if ( W_num != n
        && R_num != n
        && p_num != 0 ) {
        ans = max(p_num, min(W_num, R_num));
        /*
        if ( W_num != R_num ) {
            ans = min(W_num, R_num);
        } else {
            ans = problem_num;

            rep(i, s.length()-1) {
                if ( s[i] == 'W' && s[i+1] == 'R' ) {
                    if ( s[i+2]) {

                    } else {

                    }
                }
            }
        }
    }
    cout << ans << endl;*/
    return 0;
}
