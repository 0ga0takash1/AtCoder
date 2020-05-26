#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if ( i%2 == 0 ) {
            ans += v[i];
        } else {
            ans -= v[i];
        }
    }
    cout << ans << endl;
}
