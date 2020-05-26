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

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        if ( v[n-1] == a[i]) {
            cout << v[n-2] << endl;
        } else {
            cout << v[n-1] << endl;
        }
    }
}
