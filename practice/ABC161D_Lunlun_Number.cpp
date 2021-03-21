/*---------------------------------------------*/
/*
    ABC161 D
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

ll func(std::vector<std::vector<ll> > v , ll num, ll dig) {
    if ( dig == 1 ) {
        return v[num].size();
    } else {
        ll ans = 0;
        dig--;
        rep(i, v[num].size()) {
            ans += func(v, v[num].at(i), dig);
        }
        return ans;
    }
    return 0;
}

int main() {
    ll k;
    cin >> k;

    if ( k <= 10 ) {
        cout << k << endl;
    } else {
        if ( k <= 36 ) {
            k -= 9;
            ll num = ceil(k/3.0);
            /*
            if ( num <= 1.0 ) {
                num = 1;
            } else if ( num <= 2.0 ) {
                num = 2;
            } else if ( num <= 3.0 ) {
                num = 3;
            } else if ( num <= 4.0 ) {
                num = 4;
            } else if ( num <= 5.0 ) {
                num = 5;
            } else if ( num <= 6.0 ) {
                num = 6;
            } else if ( num <= 7.0 ) {
                num = 7;
            } else if ( num <= 8.0 ) {
                num = 8;
            } else if ( num <= 9.0 ) {
                num = 9;
            }
            */
            ll a = k%3;
            ll ans;
            if ( a == 1 ) {
                ans = num*10+num-1;
            } else if ( a == 2 ) {
                ans = num*10+num;
            } else {
                ans = num*10+num+1;
            }
            cout << ans << endl;
        } else {
            // ll i = 2;
            std::vector<std::vector<ll> > v(10);
            rep(i, 10) {
                if ( i == 0 ) {
                    v[i].push_back(0);
                    v[i].push_back(1);
                } else if ( i == 9 ) {
                    v[i].push_back(8);
                    v[i].push_back(9);
                } else {
                    rep(j, 3) {
                        v[i].push_back(j+i-1);
                    }
                }
            }

            std::vector<ll> dig;
            dig.push_back(0);
            dig.push_back(9);
            dig.push_back(35);
            ll num = 35;
            while ( num <= 100000 ) {
                rep2(i, 9) {
                    rep(j, dig.size()) {
                        num += func(v, i, dig.size());
                    }
                }
                dig.push_back(num);
                if ( k <= num ) {
                    break;
                }
            }
        }
    }
    return 0;
}
