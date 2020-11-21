#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define repc(i, l, n, d) for (int64_t i = l; i < n; i+=d)
#define repc2(i, l, n, d) for (int64_t i = l; i <= n; i+=d)
#define repe(a, b) for (auto&(a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
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
    // string s;
    // cin >> s;
    string s(66666, 'f');
    rep (i, 33333) {
        s += "ox";
    }
    // cout << s << endl;
    // return 0;

    if ( n < 3 ) {
        cout << n << endl;
        return 0;
    }
    while ( s.length() >= 3 ) {
        int64_t slen = s.length();
        // string s2 = s;
        // reverse(ALL(s2));
        repb2(i, s.find('f'), s.find_last_of('f')+1) {
            // string ss = s[i]+s[i+1]+s[i+2];
            if ( s.substr(i, 3) == "fox" ) {
                s.erase(i, 3);
            }
        }

        if ( slen == s.length()
            || min(count(s.cbegin(), s.cend(), 'f'),
                    min(count(s.cbegin(), s.cend(), 'o'),
                        count(s.cbegin(), s.cend(), 'x')) ) == 0) {
            break;
        }
    }
/*
    int64_t left = s.length();
    for (int64_t i = s.length(); i >= 0; --i) {
        if ( s[i] != 'x' ) {
            --left;
        }
    }
    rep(i, s.length()-2) {
        if (s[i] == 'f') {
            if (s[i+1] == 'o') {
                if (s[i+2] == 'x') {
                    s.erase(i, 3);
                } else {
                    if (s[left] == 'x') {
                        s.erase(left, 1);
                        s.erase(i, 2);
                    }
                }
            } else {
                if (s.substr(left-1, 2) == "ox") {
                    s.erase(left-1, 2);
                    s.erase(i, 1);
                } else {
                    // for (int64_t j = left, j >= 0; --j) {
                    int64_t j = left;
                    while (1) {
                        if ( s[j] != 'x' ) {
                            --j;
                        } else {
                            if ( s.substr(j-1, 2) != "ox" ) {
                                j -= 2;
                            } else {
                                left = j;
                                break;
                            }
                        }

                        if (j <= i) {
                            cout << s.length() << endl;
                            return 0;
                        }
                    }
                    s.erase(left-1, 2);
                    s.erase(i, 1);
                }
            }

            left = s.length();
            for (int64_t j = s.length(); j >= 0; --j) {
                if ( s[j] != 'x' ) {
                    --left;
                }
            }
        }
    }*/
    cout << s.length() << endl;

    return 0;
}
