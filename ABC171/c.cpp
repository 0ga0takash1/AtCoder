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

const string abc = "abcdefghijklmnopqrstuvwxyz";

int main() {
    int64_t n;
    cin >> n;

    if ( n <= abc.length()) {
        cout << abc.at(n-1) << endl;
        return 0;
    }
    std::vector<int64_t> v, v2;
    v.push_back(abc.length());
    // cout << "cc" << endl;

    int64_t num = abc.length();
    v.push_back(1);
    v2.push_back(abc.length());
    while (1) {
        rep(i, v.size()) {
            num *= abc.length();
        }
        v.push_back(num);
        v2.push_back(v2[v2.size()-1]+num);
        if ( v2[v2.size()-1] >= n ) break;
        // if ( accumulate(ALL(v), 0LL) >= n ) break;
    }

    // cout << "aa" << endl;
    int64_t dig = v.size()-1;
    int64_t num2 = n-v2.at(v2.size()-2);
    rep(i, dig) {
        // cout << "bb" << endl;
        if ( i == dig-1) {
            // cout << abc[n%abc.length()] << endl;
            cout << abc.at((n-1)%abc.length()) << endl;
        } else {
            cout << abc.at((num2-1)%( v.at( v.size()-(i+1)) ));
        }
    }

/*
    Graph G(26);
    rep(i, 26) {
        rep(j, 26) {
            G[i].push_back(j);
        }
    }
    */
    return 0;
}
