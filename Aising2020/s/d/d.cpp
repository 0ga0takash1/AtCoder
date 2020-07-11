#include <bits/stdc++.h>
#include <string>
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

int64_t binToUInt(std::string str) {
    unsigned int val = 0;
    for(int i = 0; i < (int)str.size(); ++i) {
        switch (str[i]) {
        case '0':
            val *= 2;
            break;
        case '1':
            val = val * 2 + 1;
            break;
        }
    }
    return val;
}

std::string to_binString(int64_t val) {
    if( !val ) return std::string("0");

    std::string str;
    while( val != 0 ) {
        if( (val & 1) == 0 )  // val は偶数か？
            str.insert(str.begin(), '0');  //  偶数の場合
        else
            str.insert(str.begin(), '1');  //  奇数の場合
        val >>= 1;
    }
    return str;
}

int64_t popcount (int64_t n, int64_t ans) {
    // cout << "n " << n << " " << ans << endl;
    string s = to_binString(n);
    // cout << "s: " << s << endl;
    int64_t one = 0;
    rep(i, s.length()) {
        if (s[i] == '1') one++;
    }

    ans++;
    if ( n%one == 0 ) {
        return ans;
    } else {
        return popcount(n%one, ans);
    }
}

int main() {
    int64_t n;
    cin >> n;
    string s;
    cin >> s;
    int64_t one = 0;
    // rep(i, s.length()) {
        // if (s[i] == '1') one++;
    // }
    rep(i, n) {
        // int64_t one_num = one;
        int64_t num = binToUInt(s);
        if ( s[i] == '0' ) {
            // one_num++;
            num += pow(2, (s.length()-i-1));
        } else {
            // one_num--;
            num -= pow(2, (s.length()-i-1));
        }
        int64_t ans = 0;
        cout << popcount(num, ans) << endl;
    }
    return 0;
}
