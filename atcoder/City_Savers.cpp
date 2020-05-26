#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a[n+1], b[n];
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if ( a[i] <= b[i] ) {
            ans += a[i];
            b[i] -= a[i];
            a[i] = 0;
            if ( a[i+1] >= b[i] ) {
                ans += b[i];
                a[i+1] -= b[i];
                b[i] = 0;
            } else {
                ans += a[i+1];
                b[i] -= a[i+1];
                a[i+1] = 0;
            }
        } else {
            ans += b[i];
            a[i] -= b[i];
            b[i] = 0;
        }

        if ( i == n-1 ) {
            if ( a[n] > b[i] ) {
                ans += b[i];
            } else {
                ans += a[n];
            }
        }
    }

    cout << ans << endl;
}
