#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,now;
    double ans = 0.0;
    double one_n,temp;
    cin >> n >> k;
    one_n = 1.0 / n;

    for (int i = 1; i <= n; i++) {
        now = i;
        temp = one_n;
        while ( now < k ) {
            now *= 2.0;
            temp /= 2.0;
        }
        ans += temp;
    }

    cout << setprecision(15) << ans << endl;
}
