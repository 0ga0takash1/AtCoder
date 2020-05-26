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

int main() {
    long double n;
    cin >> n;
    long double nn = n/1.08;
    long double nr = (ll)nn;
    long double n1 = nn*1.08;
    long double n1r = (ll)n1;
    //cout << nn << endl;
    if ( n1r == n && n1 == n1r ) {
        cout << nn << endl;
    } else {
        cout << ":(" << endl;
    }
    return 0;
}
