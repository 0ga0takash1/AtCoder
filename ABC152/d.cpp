#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;

#define rep(i, n) for (ll i = 1; i <= n; ++i)
#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ALL(v) (v).begin(), (v).end()

//π M_PI
//deg = rad*180/M_PI

ll first_digit (ll n) {
    int ans;
    if ( n < 100 ) {
        ans = n/10;
    } else if ( n < 1000 ) {
        ans = n/100;
    } else if ( n < 10000 ) {
        ans = n/1000;
    } else if ( n < 100000 ) {
        ans = n/10000;
    } else {
        ans = n/100000;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    std::vector<ll> data;
    if ( n < 100 ) {
        rep(i, n) {
            if ( i < 10 ) {
                ans++;
                if ( i+(10*i) <= n ) {
                    ans += 2;
                    data.push_back(i+(10*i));
                }
            } else if ( i < 100 ) {
                if ( i%10 != 0 ) {
                    if ( first_digit(i) == i%10 ) {
                        ans++;
                    } else if ( !*find(ALL(data), i) ) {
                        if ( (i%10)*10+first_digit(i) <= n ) {
                            ans += 2;
                            data.push_back((i%10)*10+first_digit(i));
                        }
                    }
                }
            }
        }
    } else if ( n < 1000 ) {
        rep(i, n) {
            if ( i < 10 ) {
                ans++;
                if ( i+(10*i) <= n ) {
                    ans += 2;
                    data.push_back(i+(10*i));

                    // 100以上の考慮わからん
                    if ( i+(100*i) <= n ) {
                        rep(j, n) {
                            if ( i+(100*i)+(10*j) <= n ) {
                                ans++;
                                data.push_back(i+(100*i)+(10*j));
                            }
                        }
                    }
                }
            } else if ( i < 100 ) {
                // 100以上の考慮わからん
            } else if ( i < 1000 ){
                // 100以上の考慮わからん
            }
        }
    } else if ( n < 10000 ) {

    } else if ( n < 100000 ) {

    } else {

    }

    cout << ans << endl;
    return 0;
}
