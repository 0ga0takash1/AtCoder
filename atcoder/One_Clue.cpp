#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, x;
    cin >> k >> x;

    if ( k == 1 ) {
        cout << x << endl;
    } else {
        int ans = x-k+1;
        for (int i = 0; i < (2*k-1); i++){
            cout << ans << " ";
            ans++;
        }
        cout << endl;
    }
}
