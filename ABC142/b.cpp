#include <bits/stdc++.h>
using namespace std;

#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())

int main() {
    int n, k;
    cin >> n >> k;
    int h[n];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        if (h[i] >= k) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
