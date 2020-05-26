#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin >> n;
    int a[n], b[n], c[n-1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n-1; ++i) {
        cin >> c[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += b[a[i]];
        if ( i != 1 && a[i] == a[i-1]+1 ) {
            ans += c[a[i-1]];
        }
    }
    cout << ans << endl;
    return 0;
}
