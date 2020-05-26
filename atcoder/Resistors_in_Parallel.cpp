#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin >> n;
    double a[n];
    double sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = 1/a[i];
        sum += a[i];
    }
    sum = 1/sum;
    cout << sum << endl;
}
