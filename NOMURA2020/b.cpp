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

int64_t print = 0;
char P;
void func2 (string s) {
    if ( P == 'P' ) {
        P = 'D';
    } else if ( P == 'D' ){
        P = 'P';
    }
    cout << P;
}

void func3 (string s, int64_t num) {
    if ( s[num+1] == '?' ) {
        func3(s, ++num);
    } else {
        if ( (num+1)%2 == 0 ) {
            cout << s[num+1];
        } else {
            if ( s[num+1] == 'P' ) {
                cout << 'D';
                P = 'D';
            } else {
                cout << 'P';
                P = 'P';
            }
        }
    }
}

int main() {
    string s;
    cin >> s;
    rep(i, s.length()) {
        if ( s[i] != '?' ) {
            cout << s[i];
        } else {
            cout << 'D';
        }
    }
    cout << endl;
    return 0;
}
