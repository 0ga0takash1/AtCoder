#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,now;
    double ans = 0.0;
    long double one_n,prob[100000];
    cin >> n >> k;
    one_n = 1.0 / n;

    for (int i = 0; i < n; i++) {
        now = i;
        prob[i] = one_n;
        while (1) {
            now = now*2;
            prob[i] = prob[i]/2;
            if ( now >= k) {
                break;
            }
        }
        cout << prob[i] << endl;
        ans += prob[i];
    }

    cout << ans << endl;
}
