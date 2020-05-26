#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[10000],b[10000],c[10000];
    for (int i = 0; i < n-1; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int m = 0;
    int d[10000];

    for (int i = 0; i < n; i++) {
        d[i] = min(c[a[i]], c[b[i]]);
        m += d[i];
    }

    cout << m << endl;
    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
}
