/*---------------------------------------------*/
/*
    ABC164 D
 */
/*---------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 1; i <= n; ++i)
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))

template<typename V,typename T>
T find_num(V v, T num) {
    if ( find(ALL(v), num) == v.end() ) {
        return false;
    } else {
        return true;
    }
}

// π M_PI
// deg = rad*180/M_PI
/*
auto find_string( string &s, auto &first, auto &end) {
    auto ans = s.find(const char *__s, size_type __pos, size_type __n)

    return ans;
}
*/
int main() {
    string s;
    cin >> s;
    vector<pair<char, ll> > p;
    rep(i, s.length()) {
        p.push_back( make_pair(s[i], i));
    }
    ll ans = 0;
    /*
    for (ll i = 4; i < s.length(); ++i) {
        rep(j, s.length()-i+1) {
            string ss = s.substr(j, i);
            int num = atoi(ss.c_str());
            if ( num%2019 == 0 ) {
                ans++;
            }
        }
    }*/
    string odd = "13579";
    string even = "02468";
    ll num = 2019;
    while ( num <= pow(10, s.length()) ) {
        ll i = 0;
        ll k;
        for (ll j = 9; j <= 0; --j) {
            k = 9-j;
            string ss, ss2;
            ss = j+'0';
            if ( i%2 == 0 ) {
                ss = odd[k%5]+ss;
            } else {
                // ss = even[]
            }
        }
        ++i;
        num *= 10;
    }
    cout << ans << endl;
    return 0;
}
