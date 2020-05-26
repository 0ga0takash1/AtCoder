#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int ans = 0;
    int a[3];
    for (int i = 1; i < (n-1); i++) {
        if ( p[i] < p[i-1] && p[i] > p[i+1]) {
            ans++;
        } else if (p[i] > p[i-1] && p[i] < p[i+1]) {
            ans++;
        }
    }
    cout << ans << endl;
}
