#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p[n];
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        v.push_back(p[i]);
    }

    sort(v.begin(), v.end());

    v[n-1] /= 2;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += v[i];
    }
    cout << ans << endl;
}
