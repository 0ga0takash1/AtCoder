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

int main() {
    ll n;
    cin >> n;
    ll num = 0;
    while (num <= 64) {
        if ( n <= pow(num, 5) ) {
            break;
        }
        // cout << num << "a " << pow(num, 5) << endl;
        num++;
    }
    /*
    if ( abs( n-pow(num, 5) ) <= abs( n-pow(num-1, 5) ) ) {
        num -= 1;
    }
    */
    ll num2 = 0;
    ll plus = 1;
    ll ans;
    // cout << "a " << num << " " << num-1 << endl;
    while (num2 <= 64) {
        if ( pow(num2, 5) == abs( n-pow(num, 5) ) ) {
            ans = num;
            break;
        }

        if ( pow(num2, 5) == abs( n-pow(num-1, 5)) ) {
            ans = num-1;
            // cout << "a " << ans << endl;
            plus = 0;
            break;
        }
        num2++;
    }

    if ( !plus ) {
        num2 *= -1;
    }

    cout << ans << " " << num2 << endl;
    return 0;
}
