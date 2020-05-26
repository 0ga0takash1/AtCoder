#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ALL(v) (v).begin(), (v).end()

//π M_PI
//deg = rad*180/M_PI

bool is_prime (ll n) {
    switch(n){
        case 0:
        case 1: return false;
        case 2:
        case 3: return true;
    }

    if ( n%2 == 0 || n%3 == 0 ) {
        return false;
    }

    if( n%6 != 1 && n%6 != 5 ) {
        return false;
    }

    for(ll i = 5; i*i <= n ;i+=6 ) {
        if( n%i == 0 ) {
            return false;
        }
        if( n%(i+2) == 0 ) {
            return false;
        }
    }

    return true;
}

int main() {
    ll x;
    cin >> x;
    if ( x == 2 ) {
        cout << 2 << endl;
    } else if ( x == 3 ) {
        cout << 3 << endl;
    } else {
        while (1) {
            if ( x%6 == 1 || x%6 == 5 ) {
                if ( is_prime(x) ) {
                    break;
                }
            }
            x += 1;
        }
        cout << x << endl;
    }
    return 0;
}
