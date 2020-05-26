#include <bits/stdc++.h>
using namespace std;

#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ll long long

int main() {
    long double a, b, x;
    cin >> a >> b >> x;
    //long double b_x = b-(x/(a*a));
    long double h = x/(a*a);
    long double s = a*h;
    long double ss = (2*s)/b;
    //cout << h << " " << s << " " << ss << endl;
    //cout << setprecision(10) << atan2(ss, b) << endl;
    long double deg = (atan2(ss, b)*180.0)/M_PI;
    if ( deg > 45.0 ) {
        long double o_h = (2*s/a)-b;
        long double xx = b-o_h;
        deg = (atan2(a, xx)*180)/M_PI;
    }
    cout << setprecision(12) << 90-deg << endl;
    return 0;
}
