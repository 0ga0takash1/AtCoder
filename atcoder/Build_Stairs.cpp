#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int ans = 0;
    for (int i = n-2; i >= 0; i--) {
        if ( h[i] >= h[i+1]+2 ) {
            cout << "No" << endl;
            return 0;
        }
        if ( h[i] > h[i+1]) {
            h[i]--;
        }
    }

    for (int i = 0; i < n-1; i++) {
        if ( h[i] <= h[i+1]) {
            ans++;
        }
    }

    if ( ans == n-1 ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
