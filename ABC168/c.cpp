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

double deg_to_rad( double deg ) {
    return (deg*M_PI)/180;
}

int main() {
    double a, b, h, m;
    cin >> a >> b >> h >> m;

    double hh = 360*h/12+(30*m/60);
    double mm = 360*m/60;

    double deg = abs(hh-mm);
    deg = min(deg, 360-deg);
    deg = deg_to_rad(deg);

    double ans = a*a+b*b-2*a*b*cos(deg);
    ans = sqrt(ans);

    cout << setprecision(20) << ans << endl;
    return 0;
}
