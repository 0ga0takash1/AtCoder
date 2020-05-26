#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int t[n], x[n], y[n];
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int X = 0;
        int Y = 0;
        int sum;
        if ( i == 0 ) {
            X = abs(x[i] - X);
            Y = abs(y[i] - Y);
            sum = X+Y;

            if ( t[i] %2 == sum %2 ) {
                ans++;
            }
        } else {
            X = abs(x[i] - x[i-1]);
            Y = abs(y[i] - y[i-1]);
            sum = X+Y;

            if ( (t[i]-t[i-1]) %2 == sum %2 ) {
                ans++;
            }
        }


    }

    if ( ans == n-1 ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
