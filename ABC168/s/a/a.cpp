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
    n = n%10;
    if ( n == 2 || n == 4 || n == 5 || n == 7 || n == 9 ) {
        cout << "hon" << endl;
    } else if ( n == 0 || n == 1 || n == 6 || n == 8 ) {
        cout << "pon" << endl;
    } else {
        cout << "bon" << endl;
    }
    return 0;
}
