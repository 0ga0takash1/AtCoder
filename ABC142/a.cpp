#include <bits/stdc++.h>
using namespace std;

#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())

int main() {
    int n;
    cin >> n;
    double ans;
    for (int i = 1; i <= n; ++i) {
        if ( i%2 == 1 ) {
            ans += 1.0;
        }
    }
    cout << ans/n << setprecision(10) <<endl;
    return 0;
}
