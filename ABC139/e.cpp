#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n-1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            cin >> a[i][j];
        }
    }
    int ans = n;
    bool flag = false;

    for (int j = 0; j < n-1; j++) {
        std::vector<int> v;
        for (int i = 0; i < n; i++) {
            v.push_back(a[i][j]);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            if ( v[i] == v[i+1]) {
                flag = true;
            }
        }
    }

    cout << (flag ? ans : -1) << endl;
    return 0;
}
